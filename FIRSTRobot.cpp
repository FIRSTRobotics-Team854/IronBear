//Martingrove FIRST Robotics Team 854
#include "FIRSTRobot.hpp"

void FIRSTRobot::RobotInit() {
	
	//Instantiate new Encoder objects (aChannel, bChannel, multiplier)
	//"CounterBase::k1X" = 360 "ticks" per revolution
	//Channels defined in FIRSTRobot.hpp
	flEncoder = new Encoder(FRONT_LEFT_ENCODER_A, FRONT_LEFT_ENCODER_B, CounterBase::k1X); //TL motor II
	frEncoder = new Encoder(FRONT_RIGHT_ENCODER_A, FRONT_RIGHT_ENCODER_B, CounterBase::k1X); //TR motor III
	blEncoder = new Encoder(BACK_LEFT_ENCODER_A, BACK_LEFT_ENCODER_B, CounterBase::k1X); //BL motor I
	brEncoder = new Encoder(BACK_RIGHT_TENCODER_A, BACK_RIGHT_TENCODER_B, CounterBase::k1X); //BR motor IIII
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
	
	//Instantiate new a Input object
	input = new Input();
	
	//Instantiate new a HolonomicDrive/InLineDrive object
	drive = new HolonomicDrive();
}
	
void FIRSTRobot::AutonomousInit() {
}
	
void FIRSTRobot::AutonomousPeriodic() {
}

void FIRSTRobot::TeleopInit() {
	SmartDashboard::init();
}

void FIRSTRobot::TeleopPeriodic() {
	
	//update input data
	input->update();
	//performe drive processing using fresh input data
	drive->update(input->getJoystickDirection, input->getJoystickMagnitude, input->getJoystickZ);
	//update set point of PID if the change in speed is great enough
	if(fabs(flPIDController->GetSetpoint() - flHolonomicDrive.getMotor()*220) > 22) {
		flPIDController->SetSetpoint(drive->getflMotor*220.0f)
	}
	
	if(fabs(frPIDController->GetSetpoint() - frHolonomicDrive.getMotor()*220) > 22){
		frPIDController->SetSetpoint(drive->getfrMotor*220.0f)
	}
	
	if(fabs(blPIDController->GetSetpoint() - blHolonomicDrive.getMotor()*220) > 22){
		blPIDController->SetSetpoint(drive->getblMotor*220.0f)
	}
	
	if(fabs(brPIDController->GetSetpoint() - brHolonomicDrive.getMotor()*220) > 22){
		brPIDController->SetSetpoint(drive->getbrMotor*220.0f)
	}
	
	
	SmartDashboard::PutData("fl", flPIDController);
	SmartDashboard::PutData("fr", frPIDController);
	SmartDashboard::PutData("bl", blPIDController);
	SmartDashboard::PutData("br", brPIDController);
	SmartDashboard::PutData("efl", flEncoder);
	SmartDashboard::PutData("efr", frEncoder);
	SmartDashboard::PutData("ebl", blEncoder);
	SmartDashboard::PutData("ebr", brEncoder);
	SmartDashboard::PutNumber("efl", flEncoder->GetRate());
	SmartDashboard::PutNumber("efr", frEncoder->GetRate());
	SmartDashboard::PutNumber("ebl", blEncoder->GetRate());
	SmartDashboard::PutNumber("ebr", brEncoder->GetRate());
	
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
	cerr<<"brEncoder: "<<brEncoder->GetRate()<<endl;
}
 
void FIRSTRobot::TestPeriodic() {
}

START_ROBOT_CLASS(FIRSTRobot);