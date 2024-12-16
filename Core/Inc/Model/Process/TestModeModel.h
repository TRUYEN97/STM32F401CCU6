/*;
 * TestModeModel.h
 *
 *  Created on: Dec 15, 2024
 *      Author: Admin
 */

#ifndef INC_MODEL_PROCESS_TESTMODEMODEL_H_
#define INC_MODEL_PROCESS_TESTMODEMODEL_H_

#include "LocationModel.h"
#include "UserModel.h"
#include "ContestModel.h"
#include "ErrorCode.h"
#include "FreeRTOS.h"
#include "semphr.h"

class TestModeModel: public UserModel {
	SemaphoreHandle_t mutex;

public:
	static constexpr const char *CONTESTS = "contests";
	static constexpr const char *ERROR_CODES = "errorCodes";
	static constexpr const char *LOCATION = "location";
	static constexpr const char *CAR_ID = "carId";
	static constexpr const char *START_TIME = "startTime";
	static constexpr const char *END_TIME = "endTime";
	static constexpr const char *CYCLE_TIME = "cycleTime";
	static constexpr const char *SCORE = "score";
	static constexpr const char *CONTESTS_RESULT = "contestsResult";
	static constexpr const char *DISTANCE = "distance";
	static constexpr const int8_t TEST_RUNNING = 0;
	static constexpr const int8_t TEST_PASS = 1;
	static constexpr const int8_t TEST_FAIL = -1;
	TestModeModel();

	void setCarId(const char *carId);
	void setStartTime(const char *startTime);
	void setEndTime(const char *endTime);
	void setScore(int8_t score);
	void setLocation(const LocationModel* location);
	void setContestResult(int8_t contestResult);
	void subtractScore(uint8_t score);
	void setCycleTime(unsigned long cycleTime);
	void setDistance(double distance);
	void addErrorCode(const ErrorCode* errorCode);
	void addContestModel(const ContestModel* contestModel);
	void reset();

	const char* getCarId() const;
	const char* getStartTime() const;
	const char* getEndTime() const;
	uint8_t getScore() const;
	int8_t getContestResult() const;
	unsigned long getCycleTime() const;
	double getDistance() const;
	const LocationModel* getLocation();
	JsonArrayConst& getErrorCodes() const;
	JsonArrayConst& getContestModels() const;

	virtual void updateModel(const JsonDocument *json) override;
};

#endif /* INC_MODEL_PROCESS_TESTMODEMODEL_H_ */
