//Martingrove FIRST Robotics Team 854
#ifndef __Robot_2014__FIRSTRobot__
#define __Robot_2014__FIRSTRobot__

#include <iostream>
#include "WPILib.h"

#include "Input.hpp"
#include "HolonomicDrive.hpp"
#include "InlineDrive.hpp"



class FIRSTRobot : public IterativeRobot {
private: //delcare private variables and methods found in this class

	//Declare HolonomicDrive object
	Drive *drive;
	//Declare Input object
	Input *input;
	
	virtual void RobotInit(); //Declare the functions of the FIRSTRobot Class
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
	
public: //delcare public variables and methods found in this class
	
};

#endif
