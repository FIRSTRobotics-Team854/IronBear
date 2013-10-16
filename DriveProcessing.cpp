/* Robotics 2013
Copyright (c) 2013 MCIRobotics854. All rights reserved.
Created by Alexander Momchilov on 2013-02-16.

motor[1]----motor[2]
   |    Front   |
   |    Motor   |
   |  Numbering |
   |            |
motor[0]----motor[3]*/

#include "DriveProcessing.hpp"

DriveProcessing::DriveProcessing(Victor *mfl, Victor *mfr, Victor *mbl, Victor *mbr) {
	motorAngle[0] = 3*PI/4;
	motorAngle[1] = PI/4;
	motorAngle[2] = -PI/4;
	motorAngle[3] = -3*PI/4;
}

DriveProcessing::~DriveProcessing()
{
	
}

void DriveProcessing::update(double joystickDirection, double joystickMagnitude) {
	
	//Holonmic drive
	for (i=0;i<4;i++){
		motor[i] = cos(joystickDirection-motorAngle[i]);
		//set each motor's speed as needed (not explaining the math here)
	}
	motorMax = fabs(motor[0]);
	for (i=0;i<4;i++){
		if (fabs(motor[i]) > motorMax) {
			motorMax = fabs(motor[i]);
		}
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

void DriveProcessing::PID_stuff(PIDController* PIDfl, PIDController* PIDfr, PIDController* PIDbl, PIDController* PIDbr){
	
	//update set point of PID if the change in speed is great enough
	
		if(fabs(PIDtl->GetSetpoint() - motor[1]*220) > 22)
			PIDfl->SetSetpoint(motor[1]*220.0f);

		if(fabs(PIDtr->GetSetpoint() - motor[2]*220) > 22)
			PIDfr->SetSetpoint(motor[2]*220.0f);

		if(fabs(PIDbl->GetSetpoint() - motor[0]*220) > 22)
			PIDbl->SetSetpoint(motor[0]*220.0f);

		if(fabs(PIDbr->GetSetpoint() - motor[3]*220) > 22)
			PIDbr->SetSetpoint(motor[3]*220.0f);
	
	
	
	/*cerr<<"M1 Setpoint: "<<PIDtl->GetSetpoint()<<endl;
	cerr<<"M2 Setpoint: "<<PIDtr->GetSetpoint()<<endl;
	cerr<<"M0 Setpoint: "<<PIDbl->GetSetpoint()<<endl;
	cerr<<"M3 Setpoint: "<<PIDbr->GetSetpoint()<<endl;*/
}
