/*
 * BaseModel.h
 *
 *  Created on: Dec 15, 2024
 *      Author: Admin
 */

#ifndef INC_MODEL_PROCESS_BASEMODEL_H_
#define INC_MODEL_PROCESS_BASEMODEL_H_

#include "Json.h"
class BaseModel {
protected:
	JsonDocument data;
	BaseModel();
public:
	BaseModel(const BaseModel&) = delete;
	template<typename T>
	inline static T getFormJsonVariant(const JsonVariantConst &jsonVariant,
			const T &defaultValue) {
		if (jsonVariant == nullptr) {
			return defaultValue;
		}
		return jsonVariant.template is<T>() ?
				jsonVariant.template as<T>() : defaultValue;
	}
	template<typename T>
	inline T getOrDefault(const char *key, const T &defaultValue) const {
		return this->data[key].is<T>() ? this->data[key].as<T>() : defaultValue;
	}
	virtual void reset()=0;
	virtual const JsonDocument& toJson() const;
	virtual std::string toString() const;
	virtual void updateModel(const JsonDocument *json) = 0;
};

#endif /* INC_MODEL_PROCESS_BASEMODEL_H_ */
