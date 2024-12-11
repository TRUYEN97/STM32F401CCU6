/*
 * SersorData.h
 *
 *  Created on: Dec 6, 2024
 *      Author: Admin
 */

#ifndef INC_MODEL_SERSORDATA_H_
#define INC_MODEL_SERSORDATA_H_

#include "Model/CarData.h"
struct SensorData {
	bool nt, np, cm, at, pt, t1, t2, t3;
	uint8_t gear;
	uint16_t rpm;
	CarData cardata;
};

#endif /* INC_MODEL_SERSORDATA_H_ */
