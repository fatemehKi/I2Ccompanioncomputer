/*
 * temperature.cpp
 *
 *  Created on: Sep 19, 2017
 *    
 */

#include "WProgram.h"
#include "temperature.h"
#include "Adafruit_MCP9808.h"

#define TEMP_SENSOR_ADDR_0	0x18
#define TEMP_SENSOR_ADDR_1	0x19
#define TEMP_SENSOR_ADDR_2	0x1A
#define TEMP_SENSOR_ADDR_3	0x1B

float Temperature::readings[4];
Temperature::HeaterStatus Temperature::status;

Adafruit_MCP9808 tempSensor[4];
uint8_t cur_temp_sensor_to_read;

void Temperature::setup(){
	status = HEATER_UNKNOWN;

	//Temperature sensors setup
	readings[0] = 666;
	tempSensor[0].begin(TEMP_SENSOR_ADDR_0);
	readings[1] = 666;
	tempSensor[1].begin(TEMP_SENSOR_ADDR_1);
	readings[2] = 666;
	tempSensor[2].begin(TEMP_SENSOR_ADDR_2);
	readings[3] = 666;
	tempSensor[3].begin(TEMP_SENSOR_ADDR_3);

	delay(250);

	tempSensor[0].shutdown_wake(0);
	tempSensor[1].shutdown_wake(0);
	tempSensor[2].shutdown_wake(0);
	tempSensor[3].shutdown_wake(0);

	cur_temp_sensor_to_read = 0;
}

void Temperature::task(){
	tempSensor[cur_temp_sensor_to_read].shutdown_wake(0);
	readings[cur_temp_sensor_to_read] = tempSensor[cur_temp_sensor_to_read].readTempC();
	cur_temp_sensor_to_read++;
	if(cur_temp_sensor_to_read >= 4){
		cur_temp_sensor_to_read = 0;
	}
}
