//Martingrove FIRST Robotics  Team 854
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "WPILib.h"
#include "Victor.h"

#include "Inputs.cpp"
#include "DriveProcessing.cpp"

class FIRSTRobot : public IterativeRobot {
private:
	//Output Ports:
	const int FRONT_LEFT_MOTOR = 1;
	const int FRONT_RIGHT_MOTOR = 2;
	const int BACK_LEFT_MOTOR = 3;
	const int BACK_RIGHT_TMOTOR = 4;
	
	//Input Ports
		//Encoder Wiring:
		//http://www.usdigital.com/products/cables-connectors/cables/4-pin/CA-MIC4-W4-NC
		//1	+5VDC power	Orange/Red
		//A Channel	Blue/Green
		//Ground	Brown/Black
		//B Channel	Yellow
	const int FRONT_LEFT_MOTOR_A = 1;
	const int FRONT_LEFT_MOTOR_B = 2;
	
	const int FRONT_RIGHT_MOTOR_A = 3;
	const int FRONT_RIGHT_MOTOR_B = 4;
	
	const int BACK_LEFT_MOTOR_A = 5;
	const int BACK_LEFT_MOTOR_B = 6;
	
	const int BACK_RIGHT_MOTOR_A = 7;
	const int BACK_RIGHT_MOTOR_B = 8;

	//Declare Victor objects
	Victor *flVictor, *frVictor, *blVictor, *brVictor;
	//Declare Encoder objects
	Encoder *flEncoder, *frEncoder, *blEncoder, *brEncoder;
	//Declare PIDController objects
	PIDController *flPIDController, *frPIDController, *blPIDController, *brPIDController;
	//Declare DriveProcessing objects
	DriveProcessing *flDriveProcessing, *frDriveProcessing, *blDriveProcessing, *brDriveProcessing;
	//Declare input objects
	//Inputs *inputs;
	
	virtual void RobotInit(); //Declare the functions of the FIRSTRobot Class
	
	virtual void AutonomousInit();
	
	virtual void AutonomousPeriodic();
	
	virtual void TeleopInit();
	
	virtual void TeleopPeriodic();
	
	virtual void TestPeriodic();
};
