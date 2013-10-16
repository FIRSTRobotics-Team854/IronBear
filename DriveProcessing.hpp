/* Robotics 2013
Copyright (c) 2013 MCIRobotics854. All rights reserved.
Created by Alexander Momchilov on 2013-02-16.

 motor[1]----motor[2]
   |    Front   |
   |    Motor   |
   |  Numbering |
   |            |
 motor[0]----motor[3]*/

#define PI 3.14159


class DriveProcessing
{
private:
	
	double motor[4];            //temp motor intensity (domain: 0 - 1)
	double motorMax
	double motorprevious[4];
	double motorAngle[4]; 		//motor angles (rad)
	double scaleFactor;         //factor by which relative motor values are scaled
	
public: //delcare public methods found in this class
	DriveProcessing(Victor *mfl, Victor *mfr, Victor *mbl, Victor *mbr);
	~DriveProcessing();
	
	void update(double joystickDirection, double joystickMagnitude);
	void DriveProcessing::PID_stuff(PIDController* PIDtl, PIDController* PIDtr, PIDController* PIDbl, PIDController* PIDbr);
};
