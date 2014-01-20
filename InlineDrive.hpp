#ifndef __Robot_2014__InlineDrive__
#define __Robot_2014__InlineDrive__

class InlineDrive {
private: //delcare private variables and methods found in this class
	
	//Declare Victor objects
	Victor *lVictors, *rVictors;
	//Declare Encoder objects
	Encoder *lEncoder, *rEncoder;
	//Declare PIDController objects
	PIDController *lPIDController, *rPIDController;
	
	//motor intensity (domain: 0 - 1)
	double lMotors;
	double rMotors;
	
public: //delcare public variables and methods found in this class
	InlineDrive();
	~InlineDrive();
	
	void update(double joystickDirection, double joystickMagnitude ,double joystickZ);
	double getLMotors();
	double getRMotors();
};

#endif
