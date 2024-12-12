/*
 * RpmTask.cpp
 *
 *  Created on: Dec 9, 2024
 *      Author: Admin
 */

#include "Reader/IRQ/RpmTask.h"

RpmTask::RpmTask(uint16_t scala) :
		IRQTask("rpmTask", nullptr, nullptr, 64, 1), rpmPin(
				MyPin(GPIOB, GPIO_PIN_2)), scala(scala == 0 ? 1 : scala), timer(1000) {
	this->count = 0;
	this->rmp = 0;
}

bool RpmTask::isExactly(uint16_t pin) {
	return this->rpmPin.equalPin(pin) && this->rpmPin.readValue();
}

uint16_t RpmTask::getValue() {
	if (!this->timer.onTime()) {
		int32_t tempCount = this->count;
		float deltaTimeM = this->timer.getDelta() / 60000.0;
		this->count = 0;
		this->timer.reset();
		if (deltaTimeM == 0) {
			return 0;
		}
		rmp = tempCount / this->scala / deltaTimeM;
	}
	return rmp;
}

void RpmTask::setScale(uint16_t scala) {
	this->scala = scala == 0 ? 1 : scala;
}

void RpmTask::taskCallback() {
	this->count += 1;
}

