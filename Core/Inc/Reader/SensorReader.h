/*
 * SensorReader.hpp
 *
 *  Created on: Dec 6, 2024
 *      Author: Admin
 */

#ifndef INC_READER_SENSORREADER_H_
#define INC_READER_SENSORREADER_H_

#include <Model/SensorModel.h>
#include "MyRTOSTask.h"
#include "MyPin.h"
#include "Reader/IRQ/RpmTask.h"
#include "Reader/IRQ/EncoderTash.h"
#include "semphr.h"

class SensorReader: public MyRTOSTask {
	MyPin atPin, ptPin, cmPin, ntPin, npPin, s1Pin, s2Pin, s3Pin, s4Pin, t1Pin,
			t2Pin, t3Pin;
	SensorModel sensorModel;
	EncoderTask encoderTask;
	RpmTask rpmTask;
	static SensorReader *instance;
	static SemaphoreHandle_t mtx;
	SensorReader();
	~SensorReader();
	int getGearNumber();
protected:
	void run() override;
public:
	SensorReader(const SensorReader&) = delete;
	SensorReader& operator=(const SensorReader&) = delete;
	static SensorReader& getInstance();
	void handleInterrupt(uint16_t pin);
	const SensorModel& getSensorModel() const;
	void stop() override;
};

#endif /* INC_SENSORREADER_H_ */
