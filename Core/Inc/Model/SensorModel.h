/*
 * SersorData.h
 *
 *  Created on: Dec 6, 2024
 *      Author: Admin
 */

#ifndef INC_MODEL_SENSORMODEL_H_
#define INC_MODEL_SENSORMODEL_H_

#include "Model/EncodeModel.h"
#include "main.h"
class SensorModel {
	bool nt, np, cm, at, pt, t1, t2, t3;
	uint8_t gear;
	uint16_t rpm;
	EncodeModel *encodeModel;
public:
	SensorModel();
	~SensorModel();
	bool isAt() const;

	void setAt(bool at);

	EncodeModel* getEncodeModel() const;

	void setDistance(float distance);

	void resetDistance();

	bool isCm() const;

	void setCm(bool cm);

	uint8_t getGear() const;

	void setGear(uint8_t gear);

	bool isNp() const;

	void setNp(bool np);

	bool isNt() const;

	void setNt(bool nt);

	bool isPt() const;

	void setPt(bool pt);

	uint16_t getRpm() const;

	void setRpm(uint16_t rpm);

	bool isT1() const;

	void setT1(bool t1);

	bool isT2() const;

	void setT2(bool t2);

	bool isT3() const;

	void setT3(bool t3);
};

#endif /* INC_MODEL_SENSORMODEL_H_ */
