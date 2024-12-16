/*
 * SensorReader.hpp
 *
 *  Created on: Dec 6, 2024
 *      Author: Admin
 */

#ifndef INC_READER_SENSORREADER_H_
#define INC_READER_SENSORREADER_H_

#include <Model/ModelManagement.h>
#include "Reader/IRQ/RpmTask.h"
#include "Reader/IRQ/EncoderTash.h"
#include "MyRTOSTask.h"
#include "MyPin.h"
#include "semphr.h"

class SensorReader: public MyRTOSTask {
	MyPin atPin, ptPin, cmPin, ntPin, npPin, s1Pin, s2Pin, s3Pin, s4Pin, t1Pin,
			t2Pin, t3Pin;
	SensorModel *sensorModel;
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
	SensorModel* getSensorModel();
	void stop() override;
};

#endif /* INC_SENSORREADER_H_ */
