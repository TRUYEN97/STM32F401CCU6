/*
 * TimeTicker.cpp
 *
 *  Created on: Dec 11, 2024
 *      Author: Admin
 */
#include <Common/TimeTicker.h>

TimeTicker::TimeTicker(TickType_t delayTime) :
		delayTime(delayTime), lastTime(getCurrentTimeMS()) {
}

TickType_t TimeTicker::getCurrentTimeMS() {
	return (xTaskGetTickCount() * 1000) / configTICK_RATE_HZ;
}

void TimeTicker::reset() {
	this->lastTime = getCurrentTimeMS();
}

void TimeTicker::start(TickType_t delayTime) {
	this->delayTime = delayTime;
	this->lastTime = getCurrentTimeMS();
}

void TimeTicker::setDelayTime(TickType_t delayTime) {
	this->delayTime = delayTime;
}

bool TimeTicker::onTime() {
	return getCurrentTimeMS() - this->lastTime <= this->delayTime;
}
