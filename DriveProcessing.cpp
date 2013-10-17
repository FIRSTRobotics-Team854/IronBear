/* Robotics 2013
Copyright (c) 2013 MCIRobotics854. All rights reserved.
//Martingrove FIRST Robotics Team 854
/*
motor[1]----motor[2]
   |    Front   |
   |    Motor   |
   |  Numbering |
   |            |
motor[0]----motor[3]*/

#include "DriveProcessing.hpp"

DriveProcessing::DriveProcessing(double angle) { //Constructor
	motorAngle = angle
	/*3*PI/4;
	MOTORANGLE[1] = PI/4;
	MOTORANGLE[2] = -PI/4;
	MOTORANGLE[3] = -3*PI/4;*/
}

DriveProcessing::~DriveProcessing() { //Destructor
	
}

void DriveProcessing::update(double joystickDirection, double joystickMagnitude) {
	
	//Holonmic drive
	for (i=0;i<4;i++){
		motor = cos(joystickDirection-motorAngle[i]);
		//set each motor's speed as needed (not explaining the math here)
	}

	
	scaleFactor = 1/motorMax; //the motor values thus far will all likely be less than 1. We find by what factor we need to multiply the highest motor speed to make it 1, and scale up all other motor speeds by this factor. I.e. if the speeds of the motors are 0.8 0.8 0.5 0.5, 0.8 is the fastest, the scale factor becomes 1.25 (1/0.8), and all values are scaled up by 1.25 to yeild 1 1 0.625 0.625
	
	for (i=0;i<4;i++)
	{
		motor[i] *= scaleFactor; //Motors are scaled up
		motor[i] *= joystickMagnitude; //Motors are scaled down according to joystick, if needed
	}
	
	//Rotation
    if (joystickZ >= 0.25) { //deadzone
        for (i=0;i<4;i++)
        {
            motor[i] *= 0.8; //scaled down motors (100% motors can't go any faster)
            motor[i] += 0.2; //+ to all motors makes robot rotate one way
        }
    }
    if (joystickZ <= -0.25) { //deadzone
        for (i=0;i<4;i++)
        {
            motor[i] *= 0.8; //scaled down motors (100% motors can't go any faster)
            motor[i] -= 0.2; //- to all motors makes robot rotate the other way
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
