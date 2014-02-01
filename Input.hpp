//Martingrove FIRST Robotics Team 854
#ifndef __Robot_2014__INPUT__
#define __Robot_2014__INPUT__

#include "WPIlib.h"

class Input {
	
private: //delcare private variables and methods found in this class
	Joystick *joystick;
	float joystickX; //x coord of joystick
	float joystickY; //y coord of joystick
	float joystickZ; //rotate axis of joystick
	double joystickMagnitude;   //joystick input magnitude (domain: 0 - 1)
	double joystickDirection;   //joystick input direction in RAD (domain: 0 - 2pi)
	static const float DEADZONE = 0.05; //dead zone set to 5% deflection
	
/*********************
 CCW(-1)---Z---(+1)CW
 
  (-1,-1) -X- (1,-1)
    |            |
    Y  Joystick  Y
    |Co-ordinates|
    |            |
  (-1,1)  -X-  (1,1)
**********************/
	
public: //delcare public variables and methods found in this class
	Input();
	~Input();
	void Input::update();
	
	double getJoystickX();
	double getJoystickY();
	double getJoystickZ();
	double getJoystickMagnitude();
	double getJoystickDirection();
};

#endif
