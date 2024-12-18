/*
 * LocationModel.cpp
 *
 *  Created on: Dec 17, 2024
 *      Author: Admin
 */

#include "Model/Process/LocationModel.h"

LocationModel::LocationModel(double lng, double lat) :
		BaseModel() {
	this->setLng(lng);
	this->setLat(lat);
}

void LocationModel::setLng(double lng) {
	this->data[LNG] = lng;
}

void LocationModel::setLat(double lat) {
	this->data[LAT] = lat;

}
double LocationModel::getLng() {
	return this->data[LNG];

}
double LocationModel::getLat() {
	return this->data[LAT];
}

void LocationModel::updateModel(const JsonDocument *json) {
	if (json == nullptr) {
		return;
	}
	const JsonDocument &jsonData = *json;
	this->setLat(getFormJsonVariant<double>(jsonData[LAT], 0));
	this->setLng(getFormJsonVariant<double>(jsonData[LNG], 0));
}
void LocationModel::reset() {

}
