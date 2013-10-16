/* Robotics 2013
Copyright (c) 2013 MCIRobotics854. All rights reserved.
Created by Alexander Momchilov on 2013-02-16.

(-1,-1) -X- (1,-1)   motor[1]   motor[2]
   |            |       |    Front   |
   Y  Joystick  Y       |    Motor   |
   |Co-ordinates|       |  Numbering |
   |            |       |            |
 (-1,1)  X   (1,1)   motor[0]   motor[3]*/

#define PI 3.14159


class DriveProcessing
{
private:
	
	double joystickMagnitude;   //joystick input magnitude (domain: 0 - 1)
	double joystickDirection;   //joystick input direction in RAD (domain: 0 - 2pi)
	
	double motor[4];            //temp motor intensity (domain: 0 - 1)
	double motorprevious[4];
	double motorAngle[4]; 		//motor angles (rad)
	double scaleFactor;         //factor by which relative motor values are scaled
	
public: //delcare public methods found in this class
	DriveProcessing(Victor *mfl, Victor *mfr, Victor *mbl, Victor *mbr);
	~DriveProcessing();
	void calculate(double joystickX, double joystickY, double joystickZ);
	void update();
	void DriveProcessing::PID_stuff(PIDController* PIDtl, PIDController* PIDtr, PIDController* PIDbl, PIDController* PIDbr);
};
