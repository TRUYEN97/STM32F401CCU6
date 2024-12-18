/*
 * ErrorCode.h
 *
 *  Created on: Dec 16, 2024
 *      Author: Admin
 */

#ifndef INC_MODEL_PROCESS_ERRORCODE_H_
#define INC_MODEL_PROCESS_ERRORCODE_H_
#include "BaseModel.h"
class ErrorCode: public BaseModel {
public:
	static constexpr const char *ERROR_KEY = "errKey";
	static constexpr const char *ERROR_NAME = "errName";
	static constexpr const char *ERROR_POINT = "errPoint";
	ErrorCode(const char *errKey, const char *errName, uint8_t errPoint);
	const char* getErrKey() const;
	void setErrKey(const char *errKey);
	const char* getErrName() const;
	void setErrName(const char *errName);
	uint8_t getErrPoint() const;
	void setErrPoint(uint8_t errPoint);
	virtual void updateModel(const JsonDocument *json) override;
	virtual void reset() override;
};

#endif /* INC_MODEL_PROCESS_ERRORCODE_H_ */
