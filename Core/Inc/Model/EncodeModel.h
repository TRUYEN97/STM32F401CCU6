/*
 * CarData.h
 *
 *  Created on: Dec 9, 2024
 *      Author: Admin
 */

#ifndef INC_MODEL_ENCODEMODEL_H_
#define INC_MODEL_ENCODEMODEL_H_

typedef enum{
	CAR_STOP = 0, CAR_FORWARD = 1, CAR_BACKWARD = 2
} CarStatus;

class EncodeModel {
	float distance;
	float speed;
	CarStatus carStatus;
public:
	EncodeModel();
	float getDistance() const;
	float getSpeed()  const;
	float getCarStatus()  const;
	void setDistance(float discance);
	void setSpeed(float speed);
	void setCarStatus(CarStatus carStatus);
	void resetDistance();
};

#endif /* INC_MODEL_ENCODEMODEL_H_ */
