//Martingrove FIRST Robotics Team 854
//Alexander Momchilov - alexandermomchilov@gmail.com

#ifndef __Robot_2014__PORTS__
#define __Robot_2014__PORTS__

#include "WPILib.h"


class PORTS {
public:
	//Joystick port
	static const int JOYSTICK_1 = 1;

	//PWM out
	static const int LEFT_MOTORS = 1;
	static const int RIGHT_MOTORS = 2;

	//Digital I/O
	static const int PRESSURE_SWITCH = 1;
	
	//Relays
	static const int COMPRESSOR_SPIKE = 1;
	static const int FORKLIFT_SPIKE = 2;
	static const int CATAPULT_SPIKES = 3;
};

#endif /* defined __Robot_2014__PORTS__ */
