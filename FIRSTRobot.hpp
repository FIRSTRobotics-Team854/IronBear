#include <iostream>
#include <stdio.h>
#include <math.h>
#include "WPILib.h"
#include "Victor.h"

#include "Inputs.cpp"
#include "DriveProcessing.cpp"

class FIRSTRobot : public IterativeRobot {
private:
	Victor *mfl, *mfr, *mbl, *mbr; //Instantiate a Victor objects
	Inputs *inputs; //Instantiate an Input object
	
	virtual void RobotInit(); //Declare the functions of the FIRSTRobot Class
	
	virtual void AutonomousInit();
	
	virtual void AutonomousPeriodic();
	
	virtual void TeleopInit();
	
	virtual void TeleopPeriodic();
	
	virtual void TestPeriodic();
};
