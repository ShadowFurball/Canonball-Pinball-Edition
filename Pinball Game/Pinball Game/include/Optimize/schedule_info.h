#pragma once

#ifndef _SCHEDULE_INFO_H
#define _SCHEDULE_INFO_H

#include <chrono>

struct ScheduleInfo
{
	std::chrono::nanoseconds timestep;
	std::chrono::nanoseconds timeNextFrame;
};

#endif // !_SCHEDULE_INFO_H
