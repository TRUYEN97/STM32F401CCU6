/*
 * SensorModel.cpp
 *
 *  Created on: Dec 12, 2024
 *      Author: Admin
 */

#include "Model/SensorModel.h"

SensorModel::SensorModel() :
		nt(false), np(false), cm(false), at(false), pt(false), t1(false), t2(
				false), t3(false), gear(0), rpm(0), encodeModel(
				new EncodeModel()) {
}
SensorModel::~SensorModel() {
	if (this->encodeModel != nullptr) {
		delete this->encodeModel;
	}
}

bool SensorModel::isAt() const {
	return at;
}

void SensorModel::setDistance(float distance) {
	this->encodeModel->setDistance(distance);
}

void SensorModel::resetDistance() {
	this->encodeModel->resetDistance();
}

void SensorModel::setAt(bool at) {
	this->at = at;
}

EncodeModel* SensorModel::getEncodeModel() const {
	return this->encodeModel;
}

bool SensorModel::isCm() const {
	return cm;
}

void SensorModel::setCm(bool cm) {
	this->cm = cm;
}

uint8_t SensorModel::getGear() const {
	return gear;
}

void SensorModel::setGear(uint8_t gear) {
	this->gear = gear;
}

bool SensorModel::isNp() const {
	return np;
}

void SensorModel::setNp(bool np) {
	this->np = np;
}

bool SensorModel::isNt() const {
	return nt;
}

void SensorModel::setNt(bool nt) {
	this->nt = nt;
}

bool SensorModel::isPt() const {
	return pt;
}

void SensorModel::setPt(bool pt) {
	this->pt = pt;
}

uint16_t SensorModel::getRpm() const {
	return rpm;
}

void SensorModel::setRpm(uint16_t rpm) {
	this->rpm = rpm;
}

bool SensorModel::isT1() const {
	return t1;
}

void SensorModel::setT1(bool t1) {
	this->t1 = t1;
}

bool SensorModel::isT2() const {
	return t2;
}

void SensorModel::setT2(bool t2) {
	this->t2 = t2;
}

bool SensorModel::isT3() const {
	return t3;
}

void SensorModel::setT3(bool t3) {
	this->t3 = t3;
}

