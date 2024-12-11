/*
 * SensorReader.cpp
 *
 *  Created on: Dec 6, 2024
 *      Author: Admin
 */

#include <Reader/SensorReader.h>
SensorReader *SensorReader::instance = nullptr;
SemaphoreHandle_t SensorReader::mtx = nullptr;
SensorReader::SensorReader() :
		MyRTOSTask("SensorReader", nullptr, nullptr, 128, 1), atPin(
				MyPin(GPIOA, GPIO_PIN_1)), ptPin(MyPin(GPIOA, GPIO_PIN_2)), cmPin(
				MyPin(GPIOA, GPIO_PIN_3)), ntPin(MyPin(GPIOA, GPIO_PIN_4)), npPin(
				MyPin(GPIOA, GPIO_PIN_4)), s1Pin(MyPin(GPIOA, GPIO_PIN_5)), s2Pin(
				MyPin(GPIOA, GPIO_PIN_6)), s3Pin(MyPin(GPIOA, GPIO_PIN_7)), s4Pin(
				MyPin(GPIOB, GPIO_PIN_10)), t1Pin(MyPin(GPIOB, GPIO_PIN_12)), t2Pin(
				MyPin(GPIOB, GPIO_PIN_13)), t3Pin(MyPin(GPIOB, GPIO_PIN_14)), sensorData(), encoderTask(
				EncoderTask(10.5)), rpmTask(RpmTask(1)) {
}

SensorReader::~SensorReader() {
}

void SensorReader::handleInterrupt(uint16_t pin) {
	this->encoderTask.interruptCallback(pin);
	this->rpmTask.interruptCallback(pin);
}

const SensorData& SensorReader::getSensorData() const {
	return sensorData;
}

SensorReader& SensorReader::getInstance() {
	if (instance == nullptr) {
		if (mtx == nullptr) {
			mtx = xSemaphoreCreateMutex();
		}
		if (xSemaphoreTake(mtx, portMAX_DELAY) == pdTRUE) {
			if (instance == nullptr) {
				instance = new SensorReader();
			}
			xSemaphoreGive(mtx);
		}
	}
	return *instance;
}

int SensorReader::getGearNumber() {
	bool s1 = this->s1Pin.readValueWithRTOSDebounce(), s2 =
			this->s2Pin.readValueWithRTOSDebounce(), s3 =
			this->s3Pin.readValueWithRTOSDebounce(), s4 =
			this->s4Pin.readValueWithRTOSDebounce();
	if (s3) {
		if (s1) {
			return 3;
		}
		if (s2) {
			return 4;
		}
		if (s4) {
			return 5;
		}
	}
	if (s1) {
		return 1;
	}
	if (s2) {
		return 2;
	}
	return 0;
}

void SensorReader::run() {
	this->encoderTask.start();
	this->rpmTask.start();
	this->stopSt = false;
	while (!this->stopSt) {
		this->sensorData.at = this->atPin.readValueWithRTOSDebounce();
		this->sensorData.pt = this->ptPin.readValueWithRTOSDebounce();
		this->sensorData.cm = this->cmPin.readValueWithRTOSDebounce();
		this->sensorData.nt = this->ntPin.readValueWithRTOSDebounce();
		this->sensorData.np = this->npPin.readValueWithRTOSDebounce();
		this->sensorData.t1 = this->t1Pin.readValueWithRTOSDebounce();
		this->sensorData.t2 = this->t2Pin.readValueWithRTOSDebounce();
		this->sensorData.t3 = this->t3Pin.readValueWithRTOSDebounce();
		this->sensorData.gear = this->getGearNumber();
		this->sensorData.rpm = this->rpmTask.getValue();
		this->sensorData.cardata = this->encoderTask.getCarData();
		delay(100);
	}
}

void SensorReader::stop() {
	this->encoderTask.stop();
	this->rpmTask.stop();
	MyRTOSTask::stop();
}

void HAL_GPIO_EXTI_Callback(uint16_t pin) {
	SensorReader::getInstance().handleInterrupt(pin);
}
