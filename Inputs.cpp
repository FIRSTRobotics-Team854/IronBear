#include "Inputs.hpp"

#include <iostream>

Inputs::Inputs() //Constructor
{
	jsMove = new Joystick(1);
}
Inputs::~Inputs()//Destructor
{
	
}

void Inputs::update() //All these functions get the value of joystick values
{
	shooting = jsMove->GetRawButton(1); //trigger button

	joystickX = jsMove->GetX();
	joystickY = jsMove->GetY();
	joystickZ = jsMove->GetZ();
}

//Accessor functions get the value of joystick values

double Inputs::getJoystickX()
{
	return joystickX;
}

double Inputs::getJoystickY()
{
	return joystickY;
}

double Inputs::getJoystickZ()
{
	return joystickZ;
}
