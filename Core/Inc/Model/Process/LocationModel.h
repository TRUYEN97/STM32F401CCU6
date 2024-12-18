/*
 * LocationModel.h
 *
 *  Created on: Dec 17, 2024
 *      Author: Admin
 */

#ifndef INC_MODEL_PROCESS_LOCATIONMODEL_H_
#define INC_MODEL_PROCESS_LOCATIONMODEL_H_
#include "BaseModel.h"
class LocationModel: public BaseModel {
	static constexpr const char *LNG = "lng";
	static constexpr const char *LAT = "lat";
public:
	LocationModel(double lng, double lat);
	void setLng(double lng);
	void setLat(double lat);
	double getLng();
	double getLat();
	virtual void updateModel(const JsonDocument *json) override;
	virtual void reset() override;
};

#endif /* INC_MODEL_PROCESS_LOCATIONMODEL_H_ */
