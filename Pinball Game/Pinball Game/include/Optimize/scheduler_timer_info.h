#pragma once

#ifndef _SCHEDULER_TIMER_INFO_H
#define _SCHEDULER_TIMER_INFO_H

#include <chrono>

struct SchedulerTimerInfo
{
	double Interpolation;

	std::chrono::nanoseconds TimeFrameStart;
	std::chrono::nanoseconds CurrentTime;
};
#endif // !_SCHEDULER_TIMER_INFO_H
