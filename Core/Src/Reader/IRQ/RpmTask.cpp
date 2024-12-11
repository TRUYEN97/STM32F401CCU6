/*
 * RpmTask.cpp
 *
 *  Created on: Dec 9, 2024
 *      Author: Admin
 */

#include "Reader/IRQ/RpmTask.h"

RpmTask::RpmTask(uint16_t scala) :
		IRQTask("rpmTask", nullptr, nullptr, 128, 1), rpmPin(
				MyPin(GPIOB, GPIO_PIN_2)), scala(scala) {
	this->count = 0;
}

bool RpmTask::isExactly(uint16_t pin) {
	return this->rpmPin.equalPin(pin);
}

uint16_t RpmTask::getValue() {
	uint32_t tempV = this->count;
	this->count = 0;
	return tempV / this->scala == 0 ? 1 : this->scala;
}

void RpmTask::setScale(uint16_t scala) {
	this->scala = scala;
}

void RpmTask::taskCallback() {
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	this->count += 1;
}

