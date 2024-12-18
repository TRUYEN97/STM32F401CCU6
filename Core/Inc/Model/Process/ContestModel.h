/*
 * ContestModel.h
 *
 *  Created on: Dec 13, 2024
 *      Author: Admin
 */

#ifndef INC_MODEL_PROCESS_CONTESTMODEL_H_
#define INC_MODEL_PROCESS_CONTESTMODEL_H_

#include "BaseModel.h"
#include "ErrorCode.h"
class ContestModel: public BaseModel {
public:
	static constexpr const char *CONTEST_NAME = "contestName";
	static constexpr const char *START_TIME = "startTime";
	static constexpr const char *END_TIME = "endTime";
	static constexpr const char *CYCLE_TIME = "cycleTime";
	static constexpr const char *ERROR_CODES = "errorCodes";
	ContestModel();
	virtual void updateModel(const JsonDocument *json) override;
	virtual void reset() override;
	const char* getContestName() const;
	void setContestName(const char *contestName);
	long getCycleTime() const;
	void setCycleTime(long cycleTime);
	const char* getEndTime() const;
	void setEndTime(const char *endTime);
	JsonArrayConst getErrorCodes() const;
	const char* getStartTime() const;
	void setStartTime(const char *startTime);
	void addErrorCode(const ErrorCode &errorCode);
};

#endif /* INC_MODEL_PROCESS_CONTESTMODEL_H_ */
