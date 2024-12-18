/*
 * ModelManagemant.h
 *
 *  Created on: Dec 13, 2024
 *      Author: Admin
 */

#ifndef INC_MODEL_MODELMANAGEMENT_H_
#define INC_MODEL_MODELMANAGEMENT_H_
#include <Model/Process/TestModeModel.h>
#include "Model/SensorModel.h"
#include "FreeRTOS.h"
#include "semphr.h"

class ModelManagement {
	SensorModel *sensorModel;
	TestModeModel *testModeModel;
	LocationModel *locationModel;
	static ModelManagement *instance;
	static SemaphoreHandle_t mutex;
	ModelManagement();
	~ModelManagement();
public:
	ModelManagement(const ModelManagement&) = delete;
	ModelManagement& operator=(ModelManagement&) = delete;
	static ModelManagement& getInstance();
	SensorModel* getSensorModel();
	TestModeModel* getTestModeModel();
	LocationModel* getLocationModel();
};

#endif /* INC_MODEL_MODELMANAGEMENT_H_ */
