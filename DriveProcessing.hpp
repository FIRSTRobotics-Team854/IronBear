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
	
	
	double motorAngle;
	double motor;//motor intensity (domain: 0 - 1)	//motor angles (rad)
	
public: //delcare public methods found in this class
	DriveProcessing(Victor *mfl, Victor *mfr, Victor *mbl, Victor *mbr);
	~DriveProcessing();
	
	void update(double joystickDirection, double joystickMagnitude);
};
