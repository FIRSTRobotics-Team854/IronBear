//Martingrove FIRST Robotics Team 854
/*
 motor[1]----motor[2]
   |   ~Front~  |
   |    Motor   |
   |  Numbering |
   |            |
 motor[0]----motor[3]*/

#ifndef __Robot_2014__HolonomicDrive__
#define __Robot_2014__HolonomicDrive__

#define PI 3.14159

class HolonomicDrive : Drive {
private: //delcare private variables and methods found in this class
	
	//Declare Victor objects
	Victor *flVictor, *frVictor, *blVictor, *brVictor;
	//Declare Encoder objects
	Encoder *flEncoder, *frEncoder, *blEncoder, *brEncoder;
	//Declare PIDController objects
	PIDController *flPIDController, *frPIDController, *blPIDController, *brPIDController;
	
	double scaleFactor;
	//motor angles (rad)
	static const double flAngle = PI/4;
	static const double frAngle = -PI/4;
	static const double blAngle = -3*PI/4;
	static const double brAngle = 3*PI/4;
	//motor intensity (domain: 0 - 1)
	double flMotor;
	double frMotor;
	double blMotor;
	double brMotor;
	
public: //delcare public variables and methods found in this class
	HolonomicDrive();
	~HolonomicDrive();
	
	void update(double joystickDirection, double joystickMagnitude ,double joystickZ);
	double getflMotor();
	double getfrMotor();
	double getblMotor();
	double getbrMotor();
};

#endif
