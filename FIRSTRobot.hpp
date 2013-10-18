//Martingrove FIRST Robotics Team 854
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "WPILib.h"
#include "Victor.h"


#include "Input.cpp"
#include "HolonomicDrive.cpp"
#include "InlineDrive.cpp"

#define PI 3.14159

class FIRSTRobot : public IterativeRobot {
private: //delcare private variables and methods found in this class
	//Output Ports:
	static const int FRONT_LEFT_MOTOR = 1;
	static const int FRONT_RIGHT_MOTOR = 2;
	static const int BACK_LEFT_MOTOR = 3;
	static const int BACK_RIGHT_MOTOR = 4;
	
	//Input Ports
		//Encoder Wiring:
		//http://www.usdigital.com/products/cables-connectors/cables/4-pin/CA-MIC4-W4-NC
		//1	+5VDC power	Orange/Red
		//A Channel	Blue/Green
		//Ground	Brown/Black
		//B Channel	Yellow
	static const int FRONT_LEFT_ENCODER_A = 1;
	static const int FRONT_LEFT_ENCODER_B = 2;
	static const int FRONT_RIGHT_ENCODER_A = 3;
	static const int FRONT_RIGHT_ENCODER_B = 4;
	static const int BACK_LEFT_ENCODER_A = 5;
	static const int BACK_LEFT_ENCODER_B = 6;
	static const int BACK_RIGHT_ENCODER_A = 7;
	static const int BACK_RIGHT_ENCODER_B = 8;

	//Declare Victor objects
	Victor *flVictor, *frVictor, *blVictor, *brVictor;
	//Declare Encoder objects
	Encoder *flEncoder, *frEncoder, *blEncoder, *brEncoder;
	//Declare PIDController objects
	PIDController *flPIDController, *frPIDController, *blPIDController, *brPIDController;
	//Declare HolonomicDrive object
	HolonomicDrive *drive;
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
