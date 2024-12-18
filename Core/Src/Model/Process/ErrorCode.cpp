/*
 * ErrorCode.cpp
 *
 *  Created on: Dec 18, 2024
 *      Author: Admin
 */

#include "Model/Process/ErrorCode.h"

ErrorCode::ErrorCode(const char *errKey, const char *errName, uint8_t errPoint) :
		BaseModel() {
	this->setErrKey(errKey);
	this->setErrName(errName);
	this->setErrPoint(errPoint);
}
const char* ErrorCode::getErrKey() const {
	return getOrDefault<const char*>(ERROR_KEY, "");
}

void ErrorCode::setErrKey(const char *errKey) {
	this->data[ERROR_KEY] = errKey;
}

const char* ErrorCode::getErrName() const {
	return getOrDefault<const char*>(ERROR_NAME, "");
}

void ErrorCode::setErrName(const char *errName) {
	this->data[ERROR_NAME] = errName;
}

uint8_t ErrorCode::getErrPoint() const {
	return getOrDefault<uint8_t>(ERROR_POINT, 0);
}

void ErrorCode::setErrPoint(uint8_t errPoint) {
	this->data[ERROR_POINT] = errPoint;
}
void ErrorCode::updateModel(const JsonDocument *json) {
	if (json == nullptr) {
		return;
	}
	const JsonDocument &jsonData = *json;
	this->setErrKey(getFormJsonVariant<const char*>(jsonData[ERROR_KEY], ""));
	this->setErrName(getFormJsonVariant<const char*>(jsonData[ERROR_NAME], ""));
	this->setErrPoint(getFormJsonVariant<uint8_t>(jsonData[ERROR_POINT], 0));
}

void ErrorCode::reset(){

}

