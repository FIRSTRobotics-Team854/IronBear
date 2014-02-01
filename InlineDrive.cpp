#include "InlineDrive.hpp"
#include "IO.cpp"
#include <cmath>

InlineDrive::InlineDrive() { //Constructor
							 //Instantiate new Encoder objects (aChannel, bChannel, multiplier)
	//"CounterBase::k1X" = 360 "ticks" per revolution
	//Channels defined in FIRSTRobot.hpp
	lEncoder = new Encoder(LEFT_ENCODER_A,  LEFT_ENCODER_B, CounterBase::k1X); //TL motor II
	rEncoder = new Encoder(RIGHT_ENCODER_A, RIGHT_ENCODER_B, CounterBase::k1X); //TR motor III
	//magic?
	lEncoder->SetPIDSourceParameter(Encoder::kRate);
	rEncoder->SetPIDSourceParameter(Encoder::kRate);
	//Reset the Encoder distance to zero
	lEncoder->Reset();
	rEncoder->Reset();
	//Start counting distance rom Encoders
	lEncoder->Start();
	rEncoder->Start();
	//
	lEncoder->SetDistancePerPulse(0.1);
	rEncoder->SetDistancePerPulse(0.1);
	//
	lEncoder->SetMinRate(0);
	rEncoder->SetMinRate(0);
	
	//Instantiate new Victor objects (PWM Module, PWM Channel)
	//Channels defined in FIRSTRobot.hpp
	lVictors = new Victor(1, LEFT_MOTORS);
	rVictors = new Victor(1, RIGHT_MOTORS);
	
	//Instantiate PIDController objects (Kp, Ki, Kd, encoder object, Set Point - motor object)
	lPIDController = new PIDController(0.008, 0.00001, 0.0, lEncoder, lVictors);
	rPIDController = new PIDController(0.008, 0.00001, 0.0, rEncoder, rVictors);
	
	lPIDController->Enable();
	rPIDController->Enable();
	
	lPIDController->SetInputRange(-300.0f, 300.0f); //TEST WITH AND WITHOUT f
	rPIDController->SetInputRange(-300.0f, 300.0f);
	
	lPIDController->SetOutputRange(-1.0f, 1.0f);
	rPIDController->SetOutputRange(-1.0f, 1.0f);
}

InlineDrive::~InlineDrive() { //Destructor
	delete lVictors;
	delete rVictors;
	delete lEncoder;
	delete rEncoder;
	delete lPIDController;
	delete rPIDController;
}

void InlineDrive::update(double joystickDirection, double joystickMagnitude, double joystickX, double joystickY, double joystickZ) {
	
	lMotors = joystickY;
	rMotors = -joystickY;
		
	//Rotation
	if (joystickZ >= 0.25 || joystickZ <= -0.25) { //Rotation dead zone
		
		lMotors *= 0.8; //scaled down motors (100% motors can't go any faster)
		rMotors *= 0.8;
		
		if (joystickZ >= 0.25) { //deadzone
			lMotors -= 0.2;
			rMotors += 0.2;
		}
		if (joystickZ <= -0.25) { //deadzone
			lMotors += 0.2;
			rMotors -= 0.2;
		}
    }
	
	//update set point of PID if the change in speed is great enough
	if(fabs(lPIDController->GetSetpoint() - lMotors * 220) > 22) {
		lPIDController->SetSetpoint(lMotors * 220.0f);
	}
	
	if(fabs(rPIDController->GetSetpoint() - lMotors * 220) > 22){
		rPIDController->SetSetpoint(lMotors * 220.0f);
	}
	
	//Debuging magic and stuff.
	SmartDashboard::PutData("Left - PID", lPIDController);
	SmartDashboard::PutData("Right - PID", rPIDController);
	SmartDashboard::PutData("Left - Encoder", lEncoder);
	SmartDashboard::PutData("Right  - Encoder", rEncoder);
	SmartDashboard::PutNumber("Left - Get Rate", lEncoder->GetRate());
	SmartDashboard::PutNumber("Right  - Get Rate", rEncoder->GetRate());
	
	/*
	 cerr<<"joystickX: "<<input->getJoystickX()<<endl;
	 cerr<<"joystickY: "<<input->getJoystickY()<<endl;
	 cerr<<"joystickZ: "<<input->getJoystickZ()<<endl;
	 cerr<<"joystickMagnitude: "<<input->getJoystickMagnitude()<<endl
	 cerr<<"joystickDirection: "<<input->getJoystickDirection()<<endl
	 cerr<<"lMotors: "<<getLMotors()<<endl;
	 cerr<<"rMotors: "<<getRMotors()<<endl;
	 cerr<<"lEncoder: "<<lEncoder->GetRate()<<endl;
	 cerr<<"rEncoder: "<<rEncoder->GetRate()<<endl;*/
}

double InlineDrive::getLMotors() {
	return lMotors;
}

double InlineDrive::getRMotors() {
	return rMotors;
}
