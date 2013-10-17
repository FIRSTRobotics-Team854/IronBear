//Martingrove FIRST Robotics Team 854
/*
motor[1]----motor[2]
   |    Front   |
   |    Motor   |
   |  Numbering |
   |            |
motor[0]----motor[3]*/

#include "HolonomicDrive.hpp"

HolonomicDrive::DriveProcessing(double angle) { //Constructor
	motorAngle = angle
}

HolonomicDrive::~DriveProcessing() { //Destructor
	
}

void HolonomicDrive::update(double joystickDirection, double joystickMagnitude ,double joystickZ) {
	
	//set motor's speed as needed (not explaining the math here)
	motor = cos(joystickDirection-motorAngle) * scaleFactor * joystickMagnitude;
	
	//Rotation
    if (joystickZ >= 0.25) { //deadzone
        for (i=0;i<4;i++) {
            motor *= 0.8; //scaled down motors (100% motors can't go any faster)
            motor += 0.2; //+ to all motors makes robot rotate one way
        }
    }
    if (joystickZ <= -0.25) { //deadzone
        for (i=0;i<4;i++) {
            motor *= 0.8; //scaled down motors (100% motors can't go any faster)
            motor -= 0.2; //- to all motors makes robot rotate the other way
        }
    }
    
	
	/*cerr<<"M0: "<<motor[0]<<endl;
	cerr<<"M1: "<<motor[1]<<endl;
	cerr<<"M2: "<<motor[2]<<endl;
	cerr<<"M3: "<<motor[3]<<endl;
	cerr<<"X-Value: "<<joystickX<<endl;
	cerr<<"Y-Value: "<<joystickY<<endl;
    cerr<<"Z-Value: "<<joystickZ<<endl;
    cerr<<"Magnitude: "<<joystickMagnitude<<endl;*/
}

double getMotor () {
	return motor;
}

void scale(double joystickDirection) {
	double maxMotor = fabs(cos(joystickDirection-motorAngle[0]);
	for (i=1;i<4;i++){
		if (fabs(cos(joystickDirection-motorAngle[0])) > maxMotor) {
			maxMotor = fabs(motor[i]);
		}
	}
	scaleFactor = 1/maxMotor;
}