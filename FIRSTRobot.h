//Martingrove FIRST Robotics Team 854
//Alexander Momchilov - alexandermomchilov@gmail.com
//IterativeRobot Class Reference:
//http://rbmj.github.io/612-code/doc/html/classIterativeRobot.html

#ifndef __Robot_2014__FIRSTRobot__
#define __Robot_2014__FIRSTRobot__

#include "WPILib.h"

#include "PORTS.h"
#include "Catapult.h"
#include "Fork.h"

class FIRSTRobot : public IterativeRobot
{
private: //delcare private variables and methods found in this class
	Joystick input; // only joystick
	Victor LeftVictors, RightVictors;
	RobotDrive drive; // robot drive system
	Compressor compressor;
	Catapult catapult;
	Fork fork;
	
public: //delcare public variables and methods found in this class
	FIRSTRobot();
	
	//Superclass methods:
	void FIRSTRobot::RobotInit();
	void FIRSTRobot::DisabledInit();
	void FIRSTRobot::DisabledPeriodic();
	void FIRSTRobot::AutonomousInit();
	void FIRSTRobot::AutonomousPeriodic();
	void FIRSTRobot::TeleopInit();
	void FIRSTRobot::TeleopPeriodic();
	void FIRSTRobot::TestInit();
	void FIRSTRobot::TestPeriodic();
	
	//Custom methods:
	void FIRSTRobot::calibrationAssistant();
};

START_ROBOT_CLASS(FIRSTRobot);
#endif /* defined __Robot_2014__FIRSTRobot__ */
