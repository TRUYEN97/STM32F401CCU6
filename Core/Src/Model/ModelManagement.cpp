/*
 * ModelManagemant.cpp
 *
 *  Created on: Dec 13, 2024
 *      Author: Admin
 */
#include "Model/ModelManagement.h"

ModelManagement *ModelManagement::instance = nullptr;
SemaphoreHandle_t ModelManagement::mutex = nullptr;

ModelManagement::ModelManagement() :
		sensorModel(new SensorModel()), testModeModel(new TestModeModel()) {

}
ModelManagement::~ModelManagement() {

}

ModelManagement& ModelManagement::getInstance() {
	if (instance == nullptr) {
		if (mutex == nullptr) {
			mutex = xSemaphoreCreateMutex();
		}
		if (xSemaphoreTake(mutex, portMAX_DELAY) == pdPASS) {
			if (instance == nullptr) {
				instance = new ModelManagement();
			}
		}
	}
	return *instance;
}

SensorModel* ModelManagement::getSensorModel() {
	return sensorModel;
}

TestModeModel* ModelManagement::getTestModeModel(){
	return testModeModel;
}
