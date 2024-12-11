/*
 * CarData.h
 *
 *  Created on: Dec 9, 2024
 *      Author: Admin
 */

#ifndef INC_MODEL_CARDATA_H_
#define INC_MODEL_CARDATA_H_

constexpr uint8_t CAR_STOP = 0;
constexpr uint8_t CAR_FORWARD = 1;
constexpr uint8_t CAR_BACKWARD = 2;
struct CarData {
	float distance = 0.0f;
	float speed = 0.0f;
	uint8_t status = CAR_STOP;
};

#endif /* INC_MODEL_CARDATA_H_ */
