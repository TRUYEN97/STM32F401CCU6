/*
 * CarStatus.cpp
 *
 *  Created on: Dec 12, 2024
 *      Author: Admin
 */
#include "Model/EncodeModel.h"

EncodeModel::EncodeModel(): distance(0), speed(0), carStatus(CAR_STOP) {

}

float EncodeModel::getDistance() const {
	return this->distance;
}
float EncodeModel::getSpeed() const {
	return this->speed;
}
float EncodeModel::getCarStatus() const {
	return this->carStatus;
}
void EncodeModel::setDistance(float distance) {
	this->distance = distance;
}
void EncodeModel::setSpeed(float speed) {
	this->speed = speed;
}
void EncodeModel::setCarStatus(CarStatus carStatus) {
	this->carStatus = carStatus;
}
void EncodeModel::resetDistance() {
	this->distance = 0;
}

