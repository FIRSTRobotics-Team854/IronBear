//Martingrove FIRST Robotics  Team 854
#include "FIRSTRobot.hpp"

void FIRSTRobot::RobotInit() {
	
	//Instantiate new Encoder objects (aChannel, bChannel, multiplier)
	//"CounterBase::k1X" = 360 "ticks" per revolution
	//Channels defined in FIRSTRobot.hpp
	flEncoder = new Encoder(FRONT_LEFT_MOTOR_A,FRONT_LEFT_MOTOR_B, CounterBase::k1X); //TL motor II
	frEncoder = new Encoder(FRONT_RIGHT_MOTOR_A,FRONT_RIGHT_MOTOR_B, CounterBase::k1X); //TR motor III
	blEncoder = new Encoder(BACK_LEFT_MOTOR_A,BACK_LEFT_MOTOR_B, CounterBase::k1X); //BL motor I
	brEncoder = new Encoder(BACK_RIGHT_TMOTOR_A,BACK_RIGHT_TMOTOR_B, CounterBase::k1X); //BR motor IIII
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
	
	//Instantiate PIDController objects (Kp, Ki, Kd, encoder object, Set Point - motor object)
	flPIDController = new PIDController(0.008, 0.00001, 0.0, etl, mtl);
	frPIDController = new PIDController(0.008, 0.00001, 0.0, etr, mtr);
	blPIDController = new PIDController(0.008, 0.00001, 0.0, ebl, mbl);
	brPIDController = new PIDController(0.008, 0.00001, 0.0, ebr, mbr);
	
	flPIDController->Enable();
	frPIDController->Enable();
	blPIDController->Enable();
	brPIDController->Enable();
	
	flPIDController->SetInputRange(-300.0, 300.0);
	frPIDController->SetInputRange(-300.0f, 300.0f);
	blPIDController->SetInputRange(-300.0, 300.0);
	brPIDController->SetInputRange(-300.0, 300.0);
	
	flPIDController->SetOutputRange(-1.0f, 1.0f);
	frPIDController->SetOutputRange(-1.0f, 1.0f);
	blPIDController->SetOutputRange(-1.0f, 1.0f);
	brPIDController->SetOutputRange(-1.0f, 1.0f);
	
	//Instantiate new DriveProcessing objects
	flDriveProcessing = new DriveProcessing(3*PI/4);
	frDriveProcessing = new DriveProcessing(PI/4);
	blDriveProcessing = new DriveProcessing(-PI/4);
	brDriveProcessing = new DriveProcessing(-3*PI/4);
	
	//Instantiate new Victor objects (PWM Module, PWM Channel)
	//Channels defined in FIRSTRobot.hpp
	flVictor = new Victor(1, FRONT_LEFT_MOTOR);
	frVictor = new Victor(1, FRONT_RIGHT_MOTOR);
	blVictor = new Victor(1, BACK_LEFT_MOTOR);
	brVictor = new Victor(1, BACK_RIGHT_MOTOR);
}
	
void Robot2013::AutonomousInit() {

}
	
void Robot2013::AutonomousPeriodic() {

}

void Robot2013::TeleopInit() {
}

void Robot2013::TeleopPeriodic() {
	
}
 
void Robot2013::TestPeriodic() {
	
}

START_ROBOT_CLASS(FIRSTRobot);

