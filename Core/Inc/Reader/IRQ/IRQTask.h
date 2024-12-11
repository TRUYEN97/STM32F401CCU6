/*
 * IRQTask.h
 *
 *  Created on: Dec 9, 2024
 *      Author: Admin
 */

#ifndef INC_READER_IRQ_IRQTASK_H_
#define INC_READER_IRQ_IRQTASK_H_
#include "MyRTOSTask.h"
#include "semphr.h"
class IRQTask: public MyRTOSTask {

protected:
	SemaphoreHandle_t xSemaphore;
	void run() override;
	virtual void taskCallback();
	virtual bool isExactly(uint16_t pin)=0;
public:
	IRQTask(const char *name, void (*runFunction)(void *) = nullptr, void *params = nullptr,
			uint16_t stackSize = 128, UBaseType_t priority = 1);
	void interruptCallback(uint16_t pin);
};

#endif /* INC_READER_IRQTASK_H_ */
