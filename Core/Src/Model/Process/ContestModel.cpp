/*
 * ContestModel.cpp
 *
 *  Created on: Dec 18, 2024
 *      Author: Admin
 */
#include "Model/Process/ContestModel.h"
ContestModel::ContestModel() :
		BaseModel() {
	this->reset();
}

const char* ContestModel::getContestName() const {
	return getOrDefault<const char*>(CONTEST_NAME, "");
}

void ContestModel::setContestName(const char *contestName) {
	this->data[CONTEST_NAME] = contestName;
}

long ContestModel::getCycleTime() const {
	return getOrDefault<long>(CYCLE_TIME, 0);
}

void ContestModel::setCycleTime(long cycleTime) {
	this->data[CYCLE_TIME] = cycleTime;
}

const char* ContestModel::getEndTime() const {
	return getOrDefault<const char*>(END_TIME, "");
}

void ContestModel::setEndTime(const char *endTime) {
	this->data[END_TIME] = endTime;
}

JsonArrayConst ContestModel::getErrorCodes() const {
	return this->data[ERROR_CODES];
}

void ContestModel::addErrorCode(const ErrorCode &errorCode) {
	this->data[ERROR_CODES].add(errorCode.toJson());
}

const char* ContestModel::getStartTime() const {
	return getOrDefault<const char*>(START_TIME, "");
}

void ContestModel::setStartTime(const char *startTime) {
	this->data[START_TIME] = startTime;
}

void ContestModel::updateModel(const JsonDocument *json) {
	const JsonDocument &jsonData = *json;
	this->setStartTime(
			getFormJsonVariant<const char*>(jsonData[START_TIME], ""));
	this->setEndTime(getFormJsonVariant<const char*>(jsonData[END_TIME], ""));
	this->setContestName(
			getFormJsonVariant<const char*>(jsonData[CONTEST_NAME], ""));
	this->setCycleTime(getFormJsonVariant<long>(jsonData[CYCLE_TIME], 0));
	this->data[ERROR_CODES] = getFormJsonVariant<JsonArrayConst>(
			jsonData[ERROR_CODES], this->data[ERROR_CODES].to<JsonArray>());
}

void ContestModel::reset() {
	this->setStartTime("");
	this->setEndTime("");
	this->setContestName("");
	this->setCycleTime(0);
	this->data.remove(ERROR_CODES);
	this->data[ERROR_CODES] = this->data[ERROR_CODES].to<JsonArray>();
}

