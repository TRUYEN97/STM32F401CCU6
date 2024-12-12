#include "Reader/IRQ/EncoderTash.h"

EncoderTask::EncoderTask(double scala) :
		IRQTask("EncoderTask", nullptr, nullptr, 64, 1), aPin(
				MyPin(GPIOB, GPIO_PIN_0)), bPin(MyPin(GPIOB, GPIO_PIN_1)), scala(
				scala == 0 ? 1.0f : scala), encoderModel(), timer(200) {
	this->count = 0;
	this->hasCallA = false;
}

bool EncoderTask::isExactly(uint16_t pin) {
	if (this->aPin.equalPin(pin) && this->aPin.readValue()) {
		this->hasCallA = true;
		return true;
	} else if (this->bPin.equalPin(pin) && bPin.readValue()) {
		this->hasCallA = false;
		return true;
	}
	return false;
}

void EncoderTask::setScale(double scala) {
	this->scala = scala == 0 ? 1.0f : scala;
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

EncodeModel* EncoderTask::getEncoderModel() {
	if (!this->timer.onTime()) {
		int32_t tempCount = this->count;
		float deltaTimeS = this->timer.getDelta() / 1000.0;
		this->count = 0;
		this->timer.reset();
		if (tempCount == 0 || deltaTimeS == 0) {
			this->encoderModel.setSpeed(0);
			this->encoderModel.setCarStatus(CAR_STOP);
		} else {
			this->encoderModel.setDistance(
					this->encoderModel.getDistance() + tempCount / this->scala);
			if (tempCount > 0) {
				this->encoderModel.setSpeed(
						tempCount * 3.6 / this->scala / deltaTimeS);
				this->encoderModel.setCarStatus(CAR_FORWARD);
			} else {
				this->encoderModel.setSpeed(
						tempCount * -3.6 / this->scala / deltaTimeS);
				this->encoderModel.setCarStatus(CAR_BACKWARD);
			}
		}
	}
	return &this->encoderModel;
}
