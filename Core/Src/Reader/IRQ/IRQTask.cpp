/*
 * IRQTask.cpp
 *
 *  Created on: Dec 9, 2024
 *      Author: Admin
 */
#include "Reader/IRQ/IRQTask.h"

IRQTask::IRQTask(const char *name, void (*runFunction)(void *), void *params, uint16_t stackSize,
		UBaseType_t priority) :
		MyRTOSTask(name, runFunction, params, stackSize, priority), xSemaphore(
				xSemaphoreCreateBinary()) {

}
void IRQTask::interruptCallback(uint16_t pin) {
	BaseType_t xHigherPriorityTaskWoken = pdFAIL;
	if(isExactly(pin)){
		xSemaphoreGiveFromISR(xSemaphore, &xHigherPriorityTaskWoken);
	}
	portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

void IRQTask::taskCallback() {
	if (this->runFunction != nullptr) {
		this->runFunction(this->params);
	}
}

void IRQTask::run() {
	for (;;) {
		if (xSemaphoreTake(xSemaphore, portMAX_DELAY) == pdTRUE) {
			this->taskCallback();
		}
	}
}
