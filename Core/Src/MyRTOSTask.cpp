/*
 * MyRTOSTask.cpp
 *
 *  Created on: Dec 5, 2024
 *      Author: Admin
 */

#include "MyRTOSTask.h"

MyRTOSTask::MyRTOSTask(const char *name, void (*runFunction)(void*),
		void *params, uint16_t size, UBaseType_t priority) :
		taskName(name), runFunction(runFunction), params(params), stackSize(
				size), priority(priority) {
	this->taskHandle = nullptr;
	this->stopTask = false;
}
MyRTOSTask::~MyRTOSTask() {
	if (taskHandle != nullptr) {
		vTaskDelete(taskHandle);
		taskHandle = nullptr;
	}
	runFunction = nullptr;
}

void MyRTOSTask::delay(TickType_t timeMs) {
	vTaskDelay(pdMS_TO_TICKS(timeMs));
}

void MyRTOSTask::run() {
	if (this->runFunction != nullptr) {
		this->runFunction(this->params);
	}
}

bool MyRTOSTask::isRunning() {
	return taskHandle != nullptr;
}

void MyRTOSTask::taskFunction(void *params) {
	MyRTOSTask *task = static_cast<MyRTOSTask*>(params);
	task->run();
	vTaskDelete(NULL);
}

bool MyRTOSTask::start() {
	stopTask = false;
	BaseType_t result = xTaskCreate(taskFunction, taskName, stackSize, this,
			priority, &taskHandle);
	return result == pdPASS;
}

void MyRTOSTask::stop() {
	stopTask = true;
	if (taskHandle != nullptr) {
		vTaskDelete(taskHandle);
		taskHandle = nullptr;
	}
}
UBaseType_t MyRTOSTask::getPriority() const {
	return priority;
}

void MyRTOSTask::setPriority(UBaseType_t priority) {
	this->priority = priority;
}
void MyRTOSTask::setRunFunction(void (*runFunction)(void*), void *params) {
	this->runFunction = runFunction;
	this->params = params;
}

uint16_t MyRTOSTask::getStackSize() const {
	return stackSize;
}

void MyRTOSTask::setStackSize(uint16_t stackSize) {
	this->stackSize = stackSize;
}

const char* MyRTOSTask::getTaskName() const {
	return taskName;
}

void MyRTOSTask::setTaskName(const char *taskName) {
	this->taskName = taskName;
}
