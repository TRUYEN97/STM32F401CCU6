/*
 * BaseModel.cpp
 *
 *  Created on: Dec 15, 2024
 *      Author: Admin
 */
#include "Model/Process/BaseModel.h"

BaseModel::BaseModel() :
		data() {

}

const JsonDocument& BaseModel::toJson() const{
	return this->data;
}

std::string BaseModel::toString() const {
	std::string jsonString;
	serializeJson(this->data, jsonString);
	return jsonString;
}

