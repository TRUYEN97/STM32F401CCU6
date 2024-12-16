/*
 * ContestModel.h
 *
 *  Created on: Dec 13, 2024
 *      Author: Admin
 */

#ifndef INC_MODEL_PROCESS_CONTESTMODEL_H_
#define INC_MODEL_PROCESS_CONTESTMODEL_H_

#include <Model/Process/BaseModel.h>
class ContestModel: public BaseModel {
public:
	ContestModel();
	virtual void updateModel(const JsonDocument *json) override;
};

#endif /* INC_MODEL_PROCESS_CONTESTMODEL_H_ */
