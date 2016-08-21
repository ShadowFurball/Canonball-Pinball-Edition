#include <Optimize\scheduler.h>

Scheduler::Scheduler()
{
	m_InterpolationCap = 3.f;
	m_UpdateRate = Rate(Rate::Presets::MEDIUM);
}

Scheduler::~Scheduler()
{
	
}

std::chrono::nanoseconds Scheduler::getTimeNanoSec()
{
	std::chrono::time_point<std::chrono::system_clock> current = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::nanoseconds>(current.time_since_epoch());
}

void Scheduler::setUpdateRate(Rate rate)
{
	m_UpdateRate = rate;
}

void Scheduler::start()
{
	m_ScheduleRunning = true;

	double interpolation;
	std::chrono::nanoseconds timestep;
	std::chrono::nanoseconds timeFrameRemaining;
	std::chrono::nanoseconds timeFrameStart;
	std::chrono::nanoseconds timeFrameEnd;

	bool unlimitedRate = false;
	int Lag_Monitor_Entries = 100;
	int Lag_Warning_Threshold = (int)((double)Lag_Monitor_Entries / 3.f);
	std::vector<int> lagMonitor(Lag_Monitor_Entries, 0);
	int Lag_Monitor_Active_Index = 0;


	// Check that update rate is unlimited 
	if (m_UpdateRate.get() < 1 || m_UpdateRate.get() > 1200)
	{
		unlimitedRate = true;
	}

	// Calculate the time step;
	if (unlimitedRate)
	{
		timestep = std::chrono::nanoseconds(1);
	}
	else
	{
		timestep = std::chrono::nanoseconds((long long)((double)1000000000 / m_UpdateRate.get()));
	}

	SchedulerTimerInfo timeInfo;
	interpolation = 1.f;
	while (m_ScheduleRunning)
	{
		// Calculate Frame end time
		timeFrameStart = getTimeNanoSec();
		timeFrameEnd = timeFrameStart + timestep;

		// Update each scheduled item
		timeInfo.TimeFrameStart = timeFrameStart;
		timeInfo.Interpolation = interpolation;
		for (std::pair<Schedule*, ScheduleInfo>& schedule : m_Schedulers)
		{
			timeInfo.CurrentTime = getTimeNanoSec();

			if (timeFrameStart.count() > schedule.second.timeNextFrame.count() || 
				schedule.second.timestep.count() < 1.f)
			{
				schedule.first->onUpdate(timeInfo);
				schedule.second.timeNextFrame = timeFrameStart + schedule.second.timestep;
			}
		}

		// Hande end of frame analysis and clean up
		timeFrameRemaining = timeFrameEnd - getTimeNanoSec();
		if (timeFrameRemaining.count() > 0)
		{
			std::this_thread::sleep_for(timeFrameRemaining);
			lagMonitor[Lag_Monitor_Active_Index] = 0;
		}
		else
		{
			if (unlimitedRate)
			{
				// Unlimited rate uses the last time frame as an interpolation factor
				double FrameTime = (double)(getTimeNanoSec().count() - timeFrameStart.count());
				interpolation = FrameTime / (double)timestep.count();
				timestep = std::chrono::nanoseconds((long long)FrameTime);
				continue;
			}
			else
			{
				lagMonitor[Lag_Monitor_Active_Index] = 1;
			}
		}

		// Handle lag monitors
		if (Lag_Monitor_Active_Index + 1 >= Lag_Monitor_Entries)
		{
			Lag_Monitor_Active_Index = 0;
		}
		else
		{
			Lag_Monitor_Active_Index += 1;
		}

		int Lag_Check = 0;
		for (int i = 0; i < Lag_Monitor_Entries; ++i)
		{
			Lag_Check += lagMonitor[i];
		}

		if (Lag_Check > Lag_Warning_Threshold)
		{
			for (SchedulerListener* l : m_SchedulerListeners)
			{
				l->onScheduleEvent(SchedulerMessages::SCHEDULER_FALLING_BEHIND);
			}
		}

		// Calculate next frame interpolation
		double FrameTime = (double)(getTimeNanoSec().count() - timeFrameStart.count());
		interpolation = FrameTime / (double)timestep.count();
		if (m_InterpolationCap != -1)
		{
			interpolation = std::min(interpolation, m_InterpolationCap);
		}
	}
}

void Scheduler::setInterpolationCap(double cap)
{
	if (cap <= 1.f)
	{
		cap = -1.f;
	}
	else
	{
		m_InterpolationCap = cap;
	}
}

void Scheduler::stop()
{
	m_ScheduleRunning = false;
}

void Scheduler::addSchedule(Schedule* schedule, Rate rate)
{
	m_Schedulers.push_back(std::make_pair(schedule, ScheduleInfo()));
	m_Schedulers.back().second.timeNextFrame = std::chrono::nanoseconds(0);

	if (rate.get() < 1 || rate.get() > 1200)
	{
		m_Schedulers.back().second.timestep = std::chrono::nanoseconds(0);
	}
	else
	{
		m_Schedulers.back().second.timestep = std::chrono::nanoseconds((long long)((double)1000000000 / rate.get()));
	}
}

void Scheduler::removeSchedule(Schedule* schedule)
{
	std::vector<std::pair<Schedule*, ScheduleInfo>>::iterator currentIter = m_Schedulers.begin();
	std::vector<std::pair<Schedule*, ScheduleInfo>>::iterator endIter = m_Schedulers.end();
	for (; currentIter != endIter; ++currentIter)
	{
		if (currentIter->first == schedule)
		{
			m_Schedulers.erase(currentIter);
			return;
		}
	}
}

void Scheduler::addSchedulerListener(SchedulerListener* listener)
{
	m_SchedulerListeners.push_back(listener);
}

void Scheduler::removeSchedulerListener(SchedulerListener* listener)
{
	std::vector<SchedulerListener*>::iterator currentIter = m_SchedulerListeners.begin();
	std::vector<SchedulerListener*>::iterator endIter = m_SchedulerListeners.end();
	for (; currentIter != endIter; ++currentIter)
	{
		if (*currentIter == listener)
		{
			m_SchedulerListeners.erase(currentIter);
			return;
		}
	}
}