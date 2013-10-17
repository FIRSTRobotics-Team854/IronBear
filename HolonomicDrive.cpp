//Martingrove FIRST Robotics Team 854
/*
motor[1]----motor[2]
   |    Front   |
   |    Motor   |
   |  Numbering |
   |            |
motor[0]----motor[3]*/

#include "HolonomicDrive.hpp"

HolonomicDrive::DriveProcessing() { //Constructor
}

HolonomicDrive::~DriveProcessing() { //Destructor	
}

void HolonomicDrive::update(double joystickDirection, double joystickMagnitude ,double joystickZ) {
	
	//set motor's speed as needed (not explaining the math here)
	flMotor = cos(joystickDirection-flAngle);
	frMotor = cos(joystickDirection-frAngle);
	blMotor = cos(joystickDirection-blAngle);
	brMotor = cos(joystickDirection-brAngle);
	
	double maxMotor = abs(flMotor);
	if (abs(frMotor) > maxMotor) maxMotor = abs(frMotor);
	if (abs(blMotor) > maxMotor) maxMotor = abs(blMotor);
	if (abs(blMotor) > maxMotor) maxMotor = abs(blMotor);
	
	scaleFactor = 1/maxMotor;
	
	flMotor *= scaleFactor * joystickMagnitude;
	frMotor *= scaleFactor * joystickMagnitude;
	blMotor *= scaleFactor * joystickMagnitude;
	brMotor *= scaleFactor * joystickMagnitude;
	
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
	//cerr<<"M: "<<motor<<endl;
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