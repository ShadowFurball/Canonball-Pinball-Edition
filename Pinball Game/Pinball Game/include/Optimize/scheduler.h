#pragma once

#ifndef _SCHEDULER_H
#define _SCEDULER_H

#include <thread>
#include <chrono>
#include <vector>
#include <queue>
#include <iostream>

#include <Optimize\scheduler_listener.h>
#include <Optimize\scheduler_timer_info.h>
#include <Optimize\schedule_info.h>
#include <Optimize\schedule.h>
#include <Optimize\rate.h>

class Scheduler
{
public:
	Scheduler();
	~Scheduler();

	void setInterpolationCap(double);
	void setUpdateRate(Rate);
	void start();
	void stop();
	void addSchedule(Schedule*, Rate);
	void removeSchedule(Schedule*);
	void addSchedulerListener(SchedulerListener*);
	void removeSchedulerListener(SchedulerListener*);

	protected:

	private:
		bool m_ScheduleRunning;
		double m_InterpolationCap;
		Rate m_UpdateRate;
		std::vector<std::pair<Schedule*, ScheduleInfo>> m_Schedulers;
		std::vector<SchedulerListener*> m_SchedulerListeners;
		std::chrono::nanoseconds getTimeNanoSec();
};
#endif // !_SCHEDULER_H


