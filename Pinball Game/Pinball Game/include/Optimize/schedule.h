#pragma once

#ifndef _SCHEDULE_H
#define _SCHEDULE_H

#include <Optimize\scheduler_timer_info.h>

class Schedule
{
	public:
		virtual void onUpdate(const SchedulerTimerInfo& info) = 0;

	protected:

	private:
};
#endif // !_SCHEDULE_H
