/*
 * UserModel.cpp
 *
 *  Created on: Dec 15, 2024
 *      Author: Admin
 */

#include "Model/Process/UserModel.h"

UserModel::UserModel() :
		BaseModel() {

}

void UserModel::setId(const char *id) {
	this->data[ID] = id;
}
void UserModel::setName(const char *name) {
	this->data[NAME] = name;
}
void UserModel::setExamStatus(const char *examStatus) {
	this->data[EXAM_STATUS] = examStatus;
}
void UserModel::setMobile(const char *mobile) {
	this->data[MOBILE] = mobile;
}
void UserModel::setExamId(const char *examId) {
	this->data[EXAM_ID] = examId;
}
void UserModel::setModeName(const char *modeName) {
	this->data[MODE_NAME] = modeName;
}
void UserModel::setRank(const char *rank) {
	this->data[RANK] = rank;
}
void UserModel::setDateOfBirth(const char *dateOfBirth) {
	this->data[DATE_OF_BIRTH] = dateOfBirth;
}
void UserModel::setPlaceOfOrigin(const char *placeOfOrigin) {
	this->data[PLACE_OF_ORIGIN] = placeOfOrigin;
}
void UserModel::setSex(int8_t sex) {
	this->data[SEX] = sex;
}

const char* UserModel::getId() const {
	return this->data[ID].as<const char*>();
}
const char* UserModel::getName() const {
	return this->data[NAME].as<const char*>();
}
const char* UserModel::getExamId() const {
	return this->data[EXAM_ID].as<const char*>();
}
const char* UserModel::getExamStatus() const {
	return this->data[EXAM_STATUS].as<const char*>();
}
const char* UserModel::getModeName() const {
	return this->data[MODE_NAME].as<const char*>();
}
const char* UserModel::getRank() const {
	return this->data[RANK].as<const char*>();
}
const char* UserModel::getMobile() const {
	return this->data[MOBILE].as<const char*>();
}
const char* UserModel::getPlaceOfOrigin() const {
	return this->data[PLACE_OF_ORIGIN].as<const char*>();
}
const char* UserModel::setDateOfBirth() const {
	return this->data[DATE_OF_BIRTH].as<const char*>();
}
int8_t UserModel::getSex() const {
	return this->data[SEX].as<int8_t>();
}

void UserModel::updateModel(const JsonDocument *json) {
	if (json == nullptr) {
		return;
	}
	const JsonDocument &jsonData = *json;
	this->setId(UserModel::getFormJsonVariant<const char*>(jsonData[ID], ""));
	this->setName(
			UserModel::getFormJsonVariant<const char*>(jsonData[NAME], ""));
	this->setExamId(
			UserModel::getFormJsonVariant<const char*>(jsonData[EXAM_ID], ""));
	this->setExamStatus(
			UserModel::getFormJsonVariant<const char*>(jsonData[EXAM_STATUS],
					""));
	this->setModeName(
			UserModel::getFormJsonVariant<const char*>(jsonData[MODE_NAME],
					""));
	this->setRank(
			UserModel::getFormJsonVariant<const char*>(jsonData[RANK], ""));
	this->setMobile(
			UserModel::getFormJsonVariant<const char*>(jsonData[MOBILE], ""));
	this->setPlaceOfOrigin(
			UserModel::getFormJsonVariant<const char*>(
					jsonData[PLACE_OF_ORIGIN], ""));
	this->setDateOfBirth(
			UserModel::getFormJsonVariant<const char*>(jsonData[DATE_OF_BIRTH],
					""));
	this->setSex(UserModel::getFormJsonVariant<int8_t>(jsonData[SEX], 0));

}
