#include "CommandBasedRobot.hpp"


void Robot2013::RobotInit() {
	
	//make new Victor Objects (PWM Module, PWM Channel)
	mfl = new Victor(1, 1);
	mfr = new Victor(1, 2);
	mbl = new Victor(1, 3);
	mbr = new Victor(1, 4);
	
	//make new Encoder Objects (aChannel, bChannel, ???)
	//http://www.usdigital.com/products/cables-connectors/cables/4-pin/CA-MIC4-W4-NC
	//1	+5VDC power	Orange/Red
	//A Channel	Blue/Green
	//Ground	Brown/Black
	//B Channel	Yellow
	efl = new Encoder(1,2, CounterBase::k1X); //TL motor II
	efr = new Encoder(3,4, CounterBase::k1X); //TR motor III
	ebl = new Encoder(5,6, CounterBase::k1X); //BL motor I
	ebr = new Encoder(7,8, CounterBase::k1X); //BR motor IIII
	
	//make new PIDController Objects (Kp, Ki, Kd, encoder object, Set Point - motor object)
	PID_fl = new PIDController(0.008, 0.00001, 0.0, etl, mtl);
	PID_fr = new PIDController(0.008, 0.00001, 0.0, etr, mtr);
	PID_bl = new PIDController(0.008, 0.00001, 0.0, ebl, mbl);
	PID_br = new PIDController(0.008, 0.00001, 0.0, ebr, mbr);
	//magic?
	efl->SetPIDSourceParameter(Encoder::kRate);
	efr->SetPIDSourceParameter(Encoder::kRate);
	ebl->SetPIDSourceParameter(Encoder::kRate);
	ebr->SetPIDSourceParameter(Encoder::kRate);
	//Reset the Encoder distance to zero
	efl->Reset();
	efr->Reset();
	ebl->Reset();
	ebr->Reset();
	//Start counting distance from Encoders
	efl->Start();
	efr->Start();
	ebl->Start();
	ebr->Start();
	efl->SetDistancePerPulse(0.1);
	efr->SetDistancePerPulse(0.1);
	ebl->SetDistancePerPulse(0.1);
	ebr->SetDistancePerPulse(0.1);
	
	efl->SetMinRate(0);
	efr->SetMinRate(0);
	ebl->SetMinRate(0);
	ebr->SetMinRate(0);
	
	PID_fl->Enable();
	PID_fr->Enable();
	PID_bl->Enable();
	PID_br->Enable();
	
	PID_fl->SetInputRange(-300.0, 300.0);
	PID_fr->SetInputRange(-300.0f, 300.0f);
	PID_bl->SetInputRange(-300.0, 300.0);
	PID_br->SetInputRange(-300.0, 300.0);
	
	PID_fl->SetOutputRange(-1.0f, 1.0f);
	PID_fr->SetOutputRange(-1.0f, 1.0f);
	PID_bl->SetOutputRange(-1.0f, 1.0f);
	PID_br->SetOutputRange(-1.0f, 1.0f);
	
	//new DriveProcessing objects
	DriveProcessing = new DriveProcessing(mfl, mfr, mbl, mbr)
	
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

START_ROBOT_CLASS(Robot2013);

