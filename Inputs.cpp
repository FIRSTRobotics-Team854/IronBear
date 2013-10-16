#include "Inputs.hpp"

#include <iostream>

Inputs::Inputs() //Constructor
{
	joystick = new Joystick(1);
}
Inputs::~Inputs()//Destructor
{
	
}

void Inputs::update() //All these functions get the value of joystick values
{
	shooting = joystick->GetRawButton(1); //trigger button
	
	joystickX = joystick->GetX();
	joystickY = joystick->GetY();
	joystickZ = joystick->GetZ();
	
	joystickMagnitude = 0;
	joystickDirection = 0;
	
	if((fabs(joystickX) > DEADZONE) || (fabs(joystickY) > DEADZONE)) {
		//dead zone ensures twichy joystick values don't give the robot seizures
		
		joystickMagnitude = sqrt(pow(joystickX,2) + pow(joystickY,2)) / sqrt(2);
		
		if (joystickX != 0){
			joystickDirection = atan2(joystickY,joystickX); //stores angle in RAD
		}
		//manual angle definition for undefined areas of tan.
		else if (joystickY > 0){
			joystickDirection = PI/2
		}
		else if (joystickY < 0){
			joystickDirection = 3*PI/2;
		}
		
	}
}

//Accessor functions get the value of joystick values

double Inputs::getJoystickX() {
	return joystickX;
}

double Inputs::getJoystickY() {
	return joystickY;
}

double Inputs::getJoystickZ() {
	return joystickZ;
}

double Inputs::joystickMagnitude() {
	return joystickMagnitude;
}

double Inputs::joystickDirection() {
	return joystickDirection;
}
