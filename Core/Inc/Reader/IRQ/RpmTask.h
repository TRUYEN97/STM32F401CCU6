/*
 * RpmTest.h
 *
 *  Created on: Dec 9, 2024
 *      Author: Admin
 */

#ifndef INC_READER_IRQ_RPMTASK_H_
#define INC_READER_IRQ_RPMTASK_H_
#include "IRQTask.h"
#include "Reader/MyPin.h"
class RpmTask: public IRQTask {
	MyPin rpmPin;
	uint32_t count;
	uint16_t scala;
protected:
	void taskCallback() override;
	bool isExactly(uint16_t pin);
public:
	RpmTask(uint16_t scala = 1);
	uint16_t getValue();
	void setScale(uint16_t scala);
};

#endif /* INC_READER_IRQ_RPMTASK_H_ */
