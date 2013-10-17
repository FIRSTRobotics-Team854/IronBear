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

	static double motorAngle[4] = {3*PI/4,PI/4,-PI/4,-3*PI/4};
	static double scaleFactor;
	double motorAngle;
	double motor;//motor intensity (domain: 0 - 1)	//motor angles (rad)
	
public: //delcare public variables and methods found in this class
	HolonomicDrive(Victor *mfl, Victor *mfr, Victor *mbl, Victor *mbr);
	~HolonomicDrive();
	
	void update(double joystickDirection, double joystickMagnitude ,double joystickZ);
	static void scale(double joystickDirection);
};
