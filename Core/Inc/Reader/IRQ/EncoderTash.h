/*
 * EncoderTash.h
 *
 *  Created on: Dec 9, 2024
 *      Author: Admin
 */

#ifndef INC_READER_IRQ_ENCODERTASH_H_
#define INC_READER_IRQ_ENCODERTASH_H_

#include <Model/EncodeModel.h>
#include "IRQTask.h"
#include "Reader/MyPin.h"
#include "Common/TimeTicker.h"

class EncoderTask: public IRQTask {
	MyPin aPin;
	MyPin bPin;
	int32_t count;
	bool hasCallA;
	double scala;
	EncodeModel encoderModel;
	TimeTicker timer;
protected:
	void callA();
	void callB();
	void taskCallback() override;
	bool isExactly(uint16_t pin);
public:
	void setScale(double scale);
	EncoderTask(double scala = 1);
	EncodeModel* getEncoderModel();
};

#endif /* INC_READER_IRQ_ENCODERTASH_H_ */
