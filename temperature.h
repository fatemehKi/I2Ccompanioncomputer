/*
 * temperature.h
 *
 *  Created on: Sep 19, 2017
 *      Author: isaac
 */

#ifndef SRC_TEMPERATURE_H_
#define SRC_TEMPERATURE_H_
#pragma pack(1)

namespace Temperature {

	const int PERIOD_MS = 100;

	enum HeaterStatus {
		HEATER_UNKNOWN = 0,
		HEATER_ERROR = 1,
		HEATER_ON = 2,
		HEATER_OFF = 3
	};
	extern HeaterStatus status;

	extern float readings[4];

	void setup();

	void task();

}

#endif /* SRC_TEMPERATURE_H_ */
