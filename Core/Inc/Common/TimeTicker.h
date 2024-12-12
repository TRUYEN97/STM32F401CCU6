/*
 * TimeTicker.h
 *
 *  Created on: Dec 11, 2024
 *      Author: Admin
 */

#ifndef INC_COMMON_TIMETICKER_H_
#define INC_COMMON_TIMETICKER_H_

#include "FreeRTOS.h"
#include "task.h"

class TimeTicker {
	TickType_t delayTime;
	TickType_t lastTime;
protected:
	virtual TickType_t getCurrentTimeMS();
public:
	TimeTicker(TickType_t delayTime = 0);
	TickType_t getDelta();
	TickType_t getDelayTime() const;
	void start(TickType_t delayTime);
	bool onTime();
	void setDelayTime(TickType_t delayTime);
	void reset();
};

#endif /* INC_COMMON_TIMETICKER_H_ */
