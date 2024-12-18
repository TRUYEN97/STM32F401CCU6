/*
 * UserModel.h
 *
 *  Created on: Dec 15, 2024
 *      Author: Admin
 */

#ifndef INC_MODEL_PROCESS_USERMODEL_H_
#define INC_MODEL_PROCESS_USERMODEL_H_

#include <Model/Process/BaseModel.h>

class UserModel: public BaseModel {
public:
	static constexpr const char *ID = "id";
	static constexpr const char *NAME = "name";
	static constexpr const char *EXAM_STATUS = "examStatus";
	static constexpr const char *MOBILE = "mobile";
	static constexpr const char *EXAM_ID = "examId";
	static constexpr const char *MODE_NAME = "modeName";
	static constexpr const char *RANK = "rank";
	static constexpr const char *DATE_OF_BIRTH = "dateOfBirth";
	static constexpr const char *PLACE_OF_ORIGIN = "placeOfOrigin";
	static constexpr const char *SEX = "sex";
	UserModel();
	void setId(const char *id);
	void setName(const char *name);
	void setExamStatus(const char *examStatus);
	void setMobile(const char *mobile);
	void setExamId(const char *examId);
	void setModeName(const char *modeName);
	void setRank(const char *rank);
	void setDateOfBirth(const char *dateOfBirth);
	void setPlaceOfOrigin(const char *placeOfOrigin);
	void setSex(int8_t sex);
	virtual void reset() override;
	virtual void clear();

	const char* getId() const;
	const char* getName() const;
	const char* getExamStatus() const;
	const char* getMobile() const;
	const char* getExamId() const;
	const char* getModeName() const;
	const char* getRank() const;
	const char* setDateOfBirth() const;
	const char* getPlaceOfOrigin() const;
	int8_t getSex() const;

	virtual void updateModel(const JsonDocument *json) override;

};

#endif /* INC_MODEL_PROCESS_USERMODEL_H_ */
