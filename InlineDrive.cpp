#include "InlineDrive.hpp"

InlineDrive::InlineDrive() { //Constructor
}

InlineDrive::~InlineDrive() { //Destructor
}

void InlineDrive::update(double joystickDirection, double joystickMagnitude ,double joystickZ) {
	
	flMotor = joystickMagnitude;
	frMotor = joystickMagnitude;
	blMotor = -joystickMagnitude;
	brMotor = -joystickMagnitude;
		
	//Rotation
	if (joystickZ >= 0.25 || joystickZ <= -0.25) {
		
		flMotor *= 0.8; //scaled down motors (100% motors can't go any faster)
		frMotor *= 0.8;
		blMotor *= 0.8;
		brMotor *= 0.8;
		
		if (joystickZ >= 0.25) { //deadzone
			flMotor += 0.2; //+ to all motors makes robot rotate one way
			frMotor += 0.2;
			blMotor += 0.2;
			brMotor += 0.2;
		}
		if (joystickZ <= -0.25) { //deadzone
			flMotor += 0.2; //- to all motors makes robot rotate the other way
			frMotor += 0.2;
			blMotor += 0.2;
			brMotor += 0.2;
		}
    }
}

double getflMotor () {
	return flmotor;
}

double getfrMotor () {
	return frmotor;
}

double getblMotor () {
	return blmotor;
}

double getbrMotor () {
	return brmotor;
}