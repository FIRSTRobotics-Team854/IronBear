//Martingrove FIRST Robotics Team 854
/*
motor[1]----motor[2]
   |    Front   |
   |    Motor   |
   |  Numbering |
   |            |
motor[0]----motor[3]*/

#include "HolonomicDrive.hpp"

#include "IO.cpp"
#include <wpilib.h>
#include "Victor.h"
#include <cmath>

HolonomicDrive::HolonomicDrive() { //Constructor
	
	//Instantiate new Encoder objects (aChannel, bChannel, multiplier)
	//"CounterBase::k1X" = 360 "ticks" per revolution
	//Channels defined in FIRSTRobot.hpp
	flEncoder = new Encoder(FRONT_LEFT_ENCODER_A, FRONT_LEFT_ENCODER_B, CounterBase::k1X); //TL motor II
	frEncoder = new Encoder(FRONT_RIGHT_ENCODER_A, FRONT_RIGHT_ENCODER_B, CounterBase::k1X); //TR motor III
	blEncoder = new Encoder(BACK_LEFT_ENCODER_A, BACK_LEFT_ENCODER_B, CounterBase::k1X); //BL motor I
	brEncoder = new Encoder(BACK_RIGHT_ENCODER_A, BACK_RIGHT_ENCODER_B, CounterBase::k1X); //BR motor IIII
	//magic?
	flEncoder->SetPIDSourceParameter(Encoder::kRate);
	frEncoder->SetPIDSourceParameter(Encoder::kRate);
	blEncoder->SetPIDSourceParameter(Encoder::kRate);
	brEncoder->SetPIDSourceParameter(Encoder::kRate);
	//Reset the Encoder distance to zero
	flEncoder->Reset();
	frEncoder->Reset();
	blEncoder->Reset();
	brEncoder->Reset();
	//Start counting distance from Encoders
	flEncoder->Start();
	frEncoder->Start();
	blEncoder->Start();
	brEncoder->Start();
	//
	flEncoder->SetDistancePerPulse(0.1);
	frEncoder->SetDistancePerPulse(0.1);
	blEncoder->SetDistancePerPulse(0.1);
	brEncoder->SetDistancePerPulse(0.1);
	//
	flEncoder->SetMinRate(0);
	frEncoder->SetMinRate(0);
	blEncoder->SetMinRate(0);
	brEncoder->SetMinRate(0);
	
	//Instantiate new Victor objects (PWM Module, PWM Channel)
	//Channels defined in FIRSTRobot.hpp
	flVictor = new Victor(1, FRONT_LEFT_MOTOR);
	frVictor = new Victor(1, FRONT_RIGHT_MOTOR);
	blVictor = new Victor(1, BACK_LEFT_MOTOR);
	brVictor = new Victor(1, BACK_RIGHT_MOTOR);
	
	//Instantiate PIDController objects (Kp, Ki, Kd, encoder object, Set Point - motor object)
	flPIDController = new PIDController(0.008, 0.00001, 0.0, flEncoder, flVictor);
	frPIDController = new PIDController(0.008, 0.00001, 0.0, frEncoder, frVictor);
	blPIDController = new PIDController(0.008, 0.00001, 0.0, blEncoder, blVictor);
	brPIDController = new PIDController(0.008, 0.00001, 0.0, brEncoder, brVictor);
	
	flPIDController->Enable();
	frPIDController->Enable();
	blPIDController->Enable();
	brPIDController->Enable();
	
	flPIDController->SetInputRange(-300.0f, 300.0f); //TEST WITH AND WITHOUT f
	frPIDController->SetInputRange(-300.0f, 300.0f);
	blPIDController->SetInputRange(-300.0f, 300.0f);
	brPIDController->SetInputRange(-300.0f, 300.0f);
	
	flPIDController->SetOutputRange(-1.0f, 1.0f);
	frPIDController->SetOutputRange(-1.0f, 1.0f);
	blPIDController->SetOutputRange(-1.0f, 1.0f);
	brPIDController->SetOutputRange(-1.0f, 1.0f);
}

HolonomicDrive::~HolonomicDrive() { //Destructor
	delete flVictor, frVictor, blVictor, brVictor;
	delete flEncoder, frEncoder, blEncoder, brEncoder;
	delete flPIDController, frPIDController, blPIDController, brPIDController;
}

void HolonomicDrive::update(double joystickDirection, double joystickMagnitude, double joystickX, double joystickY, double joystickZ) {
	
	//set motor's speed as needed (not explaining the math here)
	flMotor = cos(joystickDirection-flAngle);
	frMotor = cos(joystickDirection-frAngle);
	blMotor = cos(joystickDirection-blAngle);
	brMotor = cos(joystickDirection-brAngle);
	
	double maxMotor = fabs(flMotor);
	if (fabs(frMotor) > maxMotor) maxMotor = fabs(frMotor);
	if (fabs(blMotor) > maxMotor) maxMotor = fabs(blMotor);
	if (fabs(blMotor) > maxMotor) maxMotor = fabs(blMotor);
	
	scaleFactor = 1/maxMotor;
	
	flMotor *= scaleFactor * joystickMagnitude;
	frMotor *= scaleFactor * joystickMagnitude;
	blMotor *= scaleFactor * joystickMagnitude;
	brMotor *= scaleFactor * joystickMagnitude;
	
	//Rotation
	if (joystickZ >= 0.25 || joystickZ <= -0.25) {
		
		flMotor *= 0.8; //scaled down motors (100% motors can't go any faster)
		frMotor *= 0.8;
		blMotor *= 0.8;
		brMotor *= 0.8;
		
		if (joystickZ >= 0.25) { //deadzone
			flMotor += 0.2; //+ to all motors makes robot rotate one way
			frMotor += 0.2;
			blMotor += 0.2;
			brMotor += 0.2;
		}
		if (joystickZ <= -0.25) { //deadzone
			flMotor += 0.2; //- to all motors makes robot rotate the other way
			frMotor += 0.2;
			blMotor += 0.2;
			brMotor += 0.2;
		}
    }
	
	//update set point of PID if the change in speed is great enough
	if(fabs(flPIDController->GetSetpoint() - drive->getflMotor() * 220) > 22) {
		flPIDController->SetSetpoint(drive->getflMotor() * 220.0f);
	}
	
	if(fabs(frPIDController->GetSetpoint() - drive->getfrMotor() * 220) > 22){
		frPIDController->SetSetpoint(drive->getfrMotor() * 220.0f);
	}
	
	if(fabs(blPIDController->GetSetpoint() - drive->getblMotor() * 220) > 22){
		blPIDController->SetSetpoint(drive->getblMotor() * 220.0f);
	}
	
	if(fabs(brPIDController->GetSetpoint() - drive->getbrMotor() * 220) > 22){
		brPIDController->SetSetpoint(drive->getbrMotor() * 220.0f);
	}
	
	//Debuging magic and stuff.
	SmartDashboard::PutData("Front-Left - PID", flPIDController);
	SmartDashboard::PutData("Front-Right - PID", frPIDController);
	SmartDashboard::PutData("Back-Left - PID", blPIDController);
	SmartDashboard::PutData("Back-Right - PID", brPIDController);
	SmartDashboard::PutData("Front-Left - Encoder", flEncoder);
	SmartDashboard::PutData("Front-Right - Encoder", frEncoder);
	SmartDashboard::PutData("Back-Left - Encoder", blEncoder);
	SmartDashboard::PutData("Back-Right - Encoder", brEncoder);
	SmartDashboard::PutNumber("Front-Left - Get Rate", flEncoder->GetRate());
	SmartDashboard::PutNumber("Front-Right - Get Rate", frEncoder->GetRate());
	SmartDashboard::PutNumber("Back-Left - Get Rate", blEncoder->GetRate());
	SmartDashboard::PutNumber("Back-Right - Get Rate", brEncoder->GetRate());
	
	/*
	 cerr<<"joystickX: "<<input->getJoystickX()<<endl;
	 cerr<<"joystickY: "<<input->getJoystickY()<<endl;
	 cerr<<"joystickZ: "<<input->getJoystickZ()<<endl;
	 cerr<<"joystickMagnitude: "<<input->getJoystickMagnitude()<<endl
	 cerr<<"joystickDirection: "<<input->getJoystickDirection()<<endl
	 cerr<<"mflMotor: "<<drive->getflMotor()<<endl;
	 cerr<<"mfrMotor: "<<drive->getfrMotor()<<endl;
	 cerr<<"mblMotor: "<<drive->getblMotor()<<endl;
	 cerr<<"mbrMotor: "<<drive->getbrMotor()<<endl;
	 cerr<<"flEncoder: "<<flEncoder->GetRate()<<endl;
	 cerr<<"frEncoder: "<<frEncoder->GetRate()<<endl;
	 cerr<<"blEncoder: "<<blEncoder->GetRate()<<endl;
	 cerr<<"brEncoder: "<<brEncoder->GetRate()<<endl;*/
}


double HolonomicDrive::getflMotor() {
	return flMotor;
}

double HolonomicDrive::getfrMotor() {
	return frMotor;
}

double HolonomicDrive::getblMotor() {
	return blMotor;
}

double HolonomicDrive::getbrMotor() {
	return brMotor;
}
