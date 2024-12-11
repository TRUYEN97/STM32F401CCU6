/*
 * MyPin.cpp
 *
 *  Created on: Dec 8, 2024
 *      Author: Admin
 */

#include "Reader/MyPin.h"

MyPin::MyPin(GPIO_TypeDef *port, uint16_t pin) :
		port(port), pin(pin) {
}

bool MyPin::equalPin(uint16_t pin){
	return pin == this->pin;
}

GPIO_PinState MyPin::readValue() {
	if (!port) {
		return GPIO_PIN_RESET;
	}
	return HAL_GPIO_ReadPin(port, pin);
}

bool MyPin::readValueWithRTOSDebounce(bool reverse) {
	if (!port) {
		return reverse;
	}
	if (HAL_GPIO_ReadPin(port, pin) != reverse) {
		vTaskDelay(pdMS_TO_TICKS(30));
		if (HAL_GPIO_ReadPin(port, pin) != reverse) {
			return true;
		}
	}
	return false;
}

bool MyPin::readValueWithDebounce(bool reverse) {
	if (!port) {
		return reverse;
	}
	if (HAL_GPIO_ReadPin(port, pin) != reverse) {
		HAL_Delay(30);
		if (HAL_GPIO_ReadPin(port, pin) != reverse) {
			return true;
		}
	}
	return false;
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
