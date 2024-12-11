#include "Reader/IRQ/EncoderTash.h"

EncoderTask::EncoderTask(double scala) :
		IRQTask("EncoderTask", nullptr, nullptr, 128, 1), aPin(MyPin(GPIOB, GPIO_PIN_0)), bPin(
				MyPin(GPIOB, GPIO_PIN_1)), scala(scala), carData() {
	this->count = 0;
	this->hasCallA = false;
}

bool EncoderTask::isExactly(uint16_t pin) {
	if (this->aPin.equalPin(pin)) {
		this->hasCallA = true;
		return true;
	} else if (this->bPin.equalPin(pin)) {
		this->hasCallA = false;
		return true;
	}
	return false;
}

void EncoderTask::setScale(double scala){
	this->scala = scala;
}

void EncoderTask::taskCallback() {
	if (this->hasCallA) {
		if (this->bPin.readValue()) {
			this->count += 1;
		}
	} else {
		if (this->aPin.readValue()) {
			this->count -= 1;
		}
	}
}

const CarData& EncoderTask::getCarData() {
	int32_t tempV = this->count;
	if (tempV == 0) {
		carData.distance = 0;
		carData.status = CAR_STOP;
	} else {
		carData.distance = tempV / this->scala == 0 ? 1.0f : this->scala;
		if (tempV > 0) {
			carData.status = CAR_FORWARD;
		} else {
			carData.status = CAR_BACKWARD;
		}
	}
	return this->carData;
}
