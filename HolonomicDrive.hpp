//Martingrove FIRST Robotics Team 854
/*
 motor[1]----motor[2]
   |    Front   |
   |    Motor   |
   |  Numbering |
   |            |
 motor[0]----motor[3]*/

#define PI 3.14159


class HolonomicDrive {
private: //delcare private variables and methods found in this class

	
	double scaleFactor;
	//motor angles (rad)
	const double flAngle = PI/4;
	const double frAngle = -PI/4;
	const double blAngle = -3*PI/4;
	const double brAngle = 3*PI/4;
	//motor intensity (domain: 0 - 1)
	double flMotor;
	double frMotor;
	double blMotor;
	double brMotor;
	
public: //delcare public variables and methods found in this class
	HolonomicDrive(Victor *mfl, Victor *mfr, Victor *mbl, Victor *mbr);
	~HolonomicDrive();
	
	void update(double joystickDirection, double joystickMagnitude ,double joystickZ);
	double getflMotor();
	double getfrMotor();
	double getblMotor();
	double getbrMotor();
};