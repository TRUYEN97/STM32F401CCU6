/*
 * MyRTOSTask.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Admin
 */

#ifndef INC_MYRTOSTASK_H_
#define INC_MYRTOSTASK_H_

#include "FreeRTOS.h"
#include "task.h"

class MyRTOSTask {
protected:
	TaskHandle_t taskHandle;
	const char *taskName;
	void (*runFunction)(void *params);
	void *params;
	uint16_t stackSize;
	UBaseType_t priority;
	static void taskFunction(void *params);
	virtual void run();
	bool stopTask;
	void delay(TickType_t timeMs);

public:
	MyRTOSTask(const char *name, void (*runFunction)(void *) = nullptr, void *params =
			nullptr, uint16_t stackSize = 128, UBaseType_t priority = 1);
	virtual ~MyRTOSTask();

	virtual bool start();
	virtual void stop();

	void setRunFunction(void (*runFunction)(void *params), void *params = nullptr);

	UBaseType_t getPriority() const;

	void setPriority(UBaseType_t priority);

	uint16_t getStackSize() const;

	void setStackSize(uint16_t stackSize);

	const char* getTaskName() const;

	void setTaskName(const char *taskName);

	bool isRunning();
};

#endif /* INC_MYRTOSTASK_H_ */

