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
				MyPin(GPIOA, GPIO_PIN_3)), ntPin(MyPin(GPIOA, GPIO_PIN_4, 666)), npPin(
				MyPin(GPIOA, GPIO_PIN_5, 666)), s1Pin(MyPin(GPIOA, GPIO_PIN_6)), s2Pin(
				MyPin(GPIOA, GPIO_PIN_7)), s3Pin(MyPin(GPIOA, GPIO_PIN_8)), s4Pin(
				MyPin(GPIOB, GPIO_PIN_10)), t1Pin(MyPin(GPIOB, GPIO_PIN_12)), t2Pin(
				MyPin(GPIOB, GPIO_PIN_13)), t3Pin(MyPin(GPIOB, GPIO_PIN_14)), sensorModel(
				ModelManagement::getInstance().getSensorModel()), encoderTask(
				EncoderTask(this->sensorModel->getEncodeModel(), 100.5)), rpmTask(
				RpmTask(1)) {
}

SensorReader::~SensorReader() {
}

void SensorReader::handleInterrupt(uint16_t pin) {
	this->encoderTask.interruptCallback(pin);
	this->rpmTask.interruptCallback(pin);
}

SensorModel* SensorReader::getSensorModel() {
	return this->sensorModel;
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
	bool s1 = this->s1Pin.readValueWithDebounce(), s2 =
			this->s2Pin.readValueWithDebounce(), s3 =
			this->s3Pin.readValueWithDebounce(), s4 =
			this->s4Pin.readValueWithDebounce();
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
	this->stopTask = false;
	while (!this->stopTask) {
		this->sensorModel->setAt(this->atPin.readValueWithDebounce());
		this->sensorModel->setPt(this->ptPin.readValueWithDebounce());
		this->sensorModel->setCm(this->cmPin.readValueWithDebounce());
		this->sensorModel->setNt(this->ntPin.readValueWithDebounce());
		this->sensorModel->setNp(this->npPin.readValueWithDebounce());
		this->sensorModel->setT1(this->t1Pin.readValueWithDebounce());
		this->sensorModel->setT2(this->t2Pin.readValueWithDebounce());
		this->sensorModel->setT3(this->t3Pin.readValueWithDebounce());
		this->sensorModel->setGear(this->getGearNumber());
		this->sensorModel->setRpm(this->rpmTask.getValue());
		this->encoderTask.getEncoderModel();
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
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
