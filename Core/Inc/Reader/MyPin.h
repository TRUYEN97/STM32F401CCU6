/*
 * MyPin.h
 *
 *  Created on: Dec 8, 2024
 *      Author: Admin
 */

#ifndef INC_READER_MYPIN_H_
#define INC_READER_MYPIN_H_

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Common/TimeTicker.h"

class MyPin {
	GPIO_TypeDef *port;
	const uint16_t pin;
	TimeTicker timer;
	GPIO_PinState isValueWithHoldSignal(bool value);
public:
	MyPin(GPIO_TypeDef *port, uint16_t pin, TickType_t holdTime = 0);
	void setHoldSignalTime(TickType_t holdTime);
	bool equalPin(uint16_t pin);
	GPIO_PinState readValue();
	GPIO_PinState readValueWithDebounce(bool reverse = false);
	void writeValue(bool value);
	void action(void (*fuc)(GPIO_TypeDef *port, uint8_t pin));

};

#endif /* INC_READER_MYPIN_MYPIN_H_ */
