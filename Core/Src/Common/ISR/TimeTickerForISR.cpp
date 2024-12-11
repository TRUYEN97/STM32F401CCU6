/*
 * TimeTicker.cpp
 *
 *  Created on: Dec 11, 2024
 *      Author: Admin
 */
#include "Common/TimeTickerForISR.h"

TickType_t TimeTickerForISR::getCurrentTimeMS() {
	return (xTaskGetTickCountFromISR() * 1000) / configTICK_RATE_HZ;
}
