#pragma once

#ifndef _SCHEDULER_LISTENER_H
#define _SCHEDULER_LISTENER_H

#include <Optimize\scheduler_messages.h>

class SchedulerListener
{
	public:
		virtual void onScheduleEvent(SchedulerMessages) = 0;
	protected:
	private:
};
#endif // !_SCHEDULER_LISTENER_H
