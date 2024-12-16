/*
 * BaseMode.h
 *
 *  Created on: Dec 13, 2024
 *      Author: Admin
 */

#ifndef INC_MODE_BASEMODE_H_
#define INC_MODE_BASEMODE_H_
#include "MyRTOSTask.h"
#include "Contest/BaseContest.h"
#include "semphr.h"

class BaseMode: public MyRTOSTask {
protected:
	bool endTest;
	QueueHandle_t contests;
	bool addContestToQueue(BaseContest &contest);
	virtual void initMode()=0;
	virtual void closeMode()=0;
	virtual bool isCanTest()=0;
	void run() override;
	virtual void begin();
	virtual void test();
	virtual void end();
public:
	BaseMode(const char *name, uint16_t taskSize = 128,
			UBaseType_t priority = 1);
};

#endif /* INC_MODE_BASEMODE_H_ */
