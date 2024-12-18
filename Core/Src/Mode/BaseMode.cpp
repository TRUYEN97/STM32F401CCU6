/*
 * Mode.cpp
 *
 *  Created on: Dec 13, 2024
 *      Author: Admin
 */

#include "Mode/BaseMode.h"

BaseMode::BaseMode(const char *name, uint16_t taskSize, UBaseType_t priority) :
		MyRTOSTask(name, nullptr, nullptr, taskSize, priority), contests(
				xQueueCreate(20, sizeof(BaseContest*))) {
	this->endTest = false;
}

void BaseMode::run() {
	this->stopTask = false;
	this->initMode();
	while (!this->stopTask) {
		this->begin();
		this->test();
		this->end();
	}
	this->closeMode();
}
bool BaseMode::addContestToQueue(BaseContest &contest) {
	BaseContest *baseContest = contest;
	xQueueSend(contest, (void* ) &baseContest, (TickType_t ) 0);
}

void BaseMode::begin() {
	while (!this->isCanTest() && !this->stopTask) {
		this->delay(100);
	}
}

void BaseMode::test() {
	BaseContest *contest = nullptr;
	this->endTest = false;
	while (stopTask && !endTest) {
		if (xQueueReceive(contests, &contest, pdMS_TO_TICKS(100)) != pdPASS) {
			continue;
		}
		if (contest == nullptr) {
			continue;
		}
		while (!endTest && contest->isBegin()) {
			delay(10);
		}
		while (!endTest && contest->test()) {
			delay(10);
		}
		contest->end();
	}
}

void BaseMode::end() {

}

