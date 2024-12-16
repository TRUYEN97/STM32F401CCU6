/*
 * BaseContest.h
 *
 *  Created on: Dec 13, 2024
 *      Author: Admin
 */

#ifndef INC_CONTEST_BASECONTEST_H_
#define INC_CONTEST_BASECONTEST_H_

#include "Model/ModelManagement.h"

class BaseContest{
protected:
	const char *name;
	SensorModel *sensorModel;
public:
	virtual bool isBegin() = 0;
	virtual bool test() = 0;
	virtual void end() = 0;
};



#endif /* INC_CONTEST_BASECONTEST_H_ */
