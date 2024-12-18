/*
 * UserModel.cpp
 *
 *  Created on: Dec 15, 2024
 *      Author: Admin
 */

#include "Model/Process/UserModel.h"

UserModel::UserModel() :
		BaseModel() {
	this->reset();
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
	return this->getOrDefault<const char*>(ID, "");
}
const char* UserModel::getName() const {
	return this->getOrDefault<const char*>(NAME, "");
}
const char* UserModel::getExamId() const {
	return this->getOrDefault<const char*>(EXAM_ID, "");
}
const char* UserModel::getExamStatus() const {
	return this->getOrDefault<const char*>(EXAM_STATUS, "");
}
const char* UserModel::getModeName() const {
	return this->getOrDefault<const char*>(MODE_NAME, "");
}
const char* UserModel::getRank() const {
	return this->getOrDefault<const char*>(RANK, "");
}
const char* UserModel::getMobile() const {
	return this->getOrDefault<const char*>(MOBILE, "");
}
const char* UserModel::getPlaceOfOrigin() const {
	return this->getOrDefault<const char*>(PLACE_OF_ORIGIN, "");
}
const char* UserModel::setDateOfBirth() const {
	return this->getOrDefault<const char*>(DATE_OF_BIRTH, "");
}
int8_t UserModel::getSex() const {
	return this->getOrDefault<int8_t>(NAME, 0);
}
void UserModel::clear() {
	this->setId("");
	this->setName("");
	this->setExamId("");
	this->setExamStatus("");
	this->setModeName("");
	this->setRank("");
	this->setMobile("");
	this->setPlaceOfOrigin("");
	this->setDateOfBirth("");
	this->setSex(0);
}
void UserModel::reset() {
	this->setId("0");
	this->setName("");
	this->setExamId("0");
	this->setExamStatus("");
	this->setModeName("");
	this->setRank("");
	this->setMobile("");
	this->setPlaceOfOrigin("");
	this->setDateOfBirth("");
	this->setSex(0);
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
