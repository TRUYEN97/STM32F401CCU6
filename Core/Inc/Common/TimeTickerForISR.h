/*
 * TimeTickerForISR.h
 *
 *  Created on: Dec 12, 2024
 *      Author: Admin
 */

#ifndef INC_COMMON_TIMETICKERFORISR_H_
#define INC_COMMON_TIMETICKERFORISR_H_
#include "TimeTicker.h"

class TimeTickerForISR: public TimeTicker {
protected:
	TickType_t getCurrentTimeMS() override;
public:
	using TimeTicker::TimeTicker;
};



#endif /* INC_COMMON_TIMETICKERFORISR_H_ */
