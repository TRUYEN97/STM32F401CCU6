/*
 * TestModeModel.cpp
 *
 *  Created on: Dec 15, 2024
 *      Author: Admin
 */
#include "Model/Process/TestModeModel.h"

TestModeModel::TestModeModel() :
		UserModel(), mutex(xSemaphoreCreateMutex()) {

}

void TestModeModel::setCarId(const char *carId) {
	this->data[CAR_ID] = carId;
}

void TestModeModel::setStartTime(const char *startTime) {
	this->data[START_TIME] = startTime;
}

void TestModeModel::setEndTime(const char *endTime) {
	this->data[END_TIME] = endTime;
}

void TestModeModel::setScore(int8_t score) {
	if (score < 0) {
		score = 0;
	} else if (score > 100) {
		score = 100;
	}
	this->data[SCORE] = score;
}

void TestModeModel::setContestResult(int8_t contestResult) {
	if (contestResult < -1) {
		contestResult = -1;
	} else if (contestResult > 1) {
		contestResult = 1;
	}
	this->data[CONTESTS_RESULT] = contestResult;
}

void TestModeModel::setDistance(double distance) {
	this->data[DISTANCE] = distance;
}

void TestModeModel::setCycleTime(unsigned long cycleTime) {
	this->data[CYCLE_TIME] = cycleTime;
}

void TestModeModel::subtractScore(uint8_t score) {
	if (xSemaphoreTake(this->mutex, portMAX_DELAY)) {
		this->setScore(this->getScore() - score);
		xSemaphoreGive(this->mutex);
	}
}

void TestModeModel::addErrorCode(const ErrorCode *errorCode) {
	if (errorCode == nullptr) {
		return;
	}
	this->data[ERROR_CODES].add(errorCode->toJson());
}

void TestModeModel::addContestModel(const ContestModel *contestModel) {
	if (contestModel == nullptr) {
		return;
	}
	this->data[CONTESTS].add(contestModel->toJson());
}

void TestModeModel::setLocation(const LocationModel *location) {
	if (location == nullptr) {
		this->data[LOCATION] = NULL;
	}
	this->data[LOCATION] = location->toJson();
}

const char* TestModeModel::getCarId() const {
	return this->getOrDefault<const char*>(CAR_ID, "0");
}
const char* TestModeModel::getStartTime() const {
	return this->getOrDefault<const char*>(START_TIME, "");
}
const char* TestModeModel::getEndTime() const {
	return this->getOrDefault<const char*>(END_TIME, "");
}
uint8_t TestModeModel::getScore() const {
	return this->getOrDefault<uint8_t>(SCORE, 0);
}
int8_t TestModeModel::getContestResult() const {
	return this->getOrDefault<int8_t>(CONTESTS_RESULT, TEST_RUNNING);
}
double TestModeModel::getDistance() const {
	return this->getOrDefault<double>(DISTANCE, 0);
}
unsigned long TestModeModel::getCycleTime() const {
	return this->getOrDefault<unsigned long>(CYCLE_TIME, TEST_RUNNING);
}

//const LocationModel* TestModeModel::getLocation() {
//	this->getOrDefault<const JsonDocument*>(CYCLE_TIME, TEST_RUNNING);
//}

void TestModeModel::updateModel(const JsonDocument *json) {
	if (json == nullptr) {
		return;
	}
	UserModel::updateModel(json);
	const JsonDocument &jsonData = *json;
	this->setCarId(getFormJsonVariant<const char*>(jsonData[CAR_ID], "0"));
	this->setStartTime(
			getFormJsonVariant<const char*>(jsonData[START_TIME], ""));
	this->setEndTime(getFormJsonVariant<const char*>(jsonData[END_TIME], ""));
	this->setCycleTime(
			getFormJsonVariant<unsigned long>(jsonData[CYCLE_TIME], 0));
	this->setScore(getFormJsonVariant<uint8_t>(jsonData[SCORE], 0));
	this->setContestResult(
			getFormJsonVariant<int8_t>(jsonData[CONTESTS_RESULT], 0));
	this->setDistance(getFormJsonVariant<double>(jsonData[DISTANCE], 0));
}
