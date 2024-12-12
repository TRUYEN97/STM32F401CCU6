/*
 * MyPin.cpp
 *
 *  Created on: Dec 8, 2024
 *      Author: Admin
 */

#include "Reader/MyPin.h"

MyPin::MyPin(GPIO_TypeDef *port, uint16_t pin, TickType_t holdTime) :
		port(port), pin(pin), timer(holdTime) {
}

bool MyPin::equalPin(uint16_t pin) {
	return pin == this->pin;
}

GPIO_PinState MyPin::isValueWithHoldSignal(bool value) {
	if (value == false) {
		if (!this->timer.onTime()) {
			return GPIO_PIN_RESET;
		} else {
			return GPIO_PIN_SET;
		}
	} else {
		this->timer.reset();
		return GPIO_PIN_SET;
	}
}

void MyPin::setHoldSignalTime(TickType_t holdTime) {
	this->timer.setDelayTime(holdTime);
}

GPIO_PinState MyPin::readValue() {
	if (!port) {
		return GPIO_PIN_RESET;
	}
	return isValueWithHoldSignal(HAL_GPIO_ReadPin(port, pin));
}

GPIO_PinState MyPin::readValueWithDebounce(bool reverse) {
	if (!port) {
		return GPIO_PIN_RESET;
	}
	GPIO_PinState rs = GPIO_PIN_RESET;
	if (HAL_GPIO_ReadPin(port, pin) != reverse) {
		vTaskDelay(pdMS_TO_TICKS(30));
		if (HAL_GPIO_ReadPin(port, pin) != reverse) {
			rs = GPIO_PIN_SET;
		}
	}
	return this->timer.getDelayTime() > 0 ? isValueWithHoldSignal(rs) : rs;
}

void MyPin::writeValue(bool value) {
	if (!port) {
		return;
	}
	HAL_GPIO_WritePin(port, pin, value ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void MyPin::action(void (*fuc)(GPIO_TypeDef *port, uint8_t pin)) {
	if (!fuc)
		return;
	fuc(port, pin);
}
