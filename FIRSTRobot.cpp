//Martingrove FIRST Robotics Team 854
//Alexander Momchilov - alexandermomchilov@gmail.com

#include "FIRSTRobot.h"
/**
 * This is a demo program showing the use of the RobotBase class.
 * The IterativeRobot class is the base of a robot application that will automatically call your
 * Periodic methods for each packet based on the mode.
 */ 
FIRSTRobot::FIRSTRobot():
	input(PORTS::JOYSTICK_1),
	LeftVictors(PORTS::LEFT_MOTORS), // these must be initialized in the same order
	RightVictors(PORTS::RIGHT_MOTORS), // as they are declared above.
	drive(LeftVictors, RightVictors),
	compressor(PORTS::PRESSURE_SWITCH,PORTS::COMPRESSOR_SPIKE),
	catapult(),
	fork() {
		std::cerr << typeid(this).name() << "() constructed\n";
		this->SetPeriod(0); 	//Set update period to sync with robot control packets (20ms nominal)
		drive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
		drive.SetInvertedMotor(RobotDrive::kRearRightMotor, true);
		drive.SetExpiration(30000); //Motors shutdown after inactivity
		compressor.Start();
	}
/**
 * Robot-wide initialization code should go here.
 * 
 * Use this method for default Robot-wide initialization which will
 * be called when the robot is first powered on.  It will be called exactly 1 time.
 */
void FIRSTRobot::RobotInit() {
	std::cerr << typeid(this).name() << "::RobotInit() called\n";
}

/**
 * Initialization code for disabled mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters disabled mode. 
 */
void FIRSTRobot::DisabledInit() {
	std::cerr << typeid(this).name() << "::DisabledInit() called\n";
}

/**
 * Periodic code for disabled mode should go here.
 * 
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in disabled mode.
 */
void FIRSTRobot::DisabledPeriodic() {
	//std::cerr << typeid(this).name() << "::DisabledPeriodic() called\n";
}

/**
 * Initialization code for autonomous mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters autonomous mode.
 */
void FIRSTRobot::AutonomousInit() {
	std::cerr << typeid(this).name() << "::AutonomousInit() called\n";
}

/**
 * Periodic code for autonomous mode should go here.
 *
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in autonomous mode.
 */
void FIRSTRobot::AutonomousPeriodic() {
	//std::cerr << typeid(this).name() << "::AutonomousPeriodic() called\n";
}

/**
 * Initialization code for teleop mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters teleop mode.
 */
void FIRSTRobot::TeleopInit() {
	std::cerr << typeid(this).name() << "::TeleopInit() called\n";
}

/**
 * Periodic code for teleop mode should go here.
 *
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in teleop mode.
 */
void FIRSTRobot::TeleopPeriodic() {
	//std::cerr << typeid(this).name() << "::TeleopPeriodic() called\n";
	drive.ArcadeDrive(input); // drive with arcade style
	drive.ArcadeDrive(input);
	catapult.update(input.GetButton(Joystick::kTriggerButton),input.GetRawButton(2));
	fork.update(input.GetRawAxis(6));
	if (input.GetRawButton(7)) compressor.Stop();
	if (input.GetRawButton(8)) compressor.Start();

	SmartDashboard::PutNumber("Y", input.GetY());
	SmartDashboard::PutNumber("Z", input.GetZ());
	SmartDashboard::PutData("L",&LeftVictors);
	SmartDashboard::PutData("R",&RightVictors);
	SmartDashboard::PutBoolean("Catapult", catapult.get());
	SmartDashboard::PutBoolean("Forklift", fork.get());
	//drive.SetLeftRightMotorOutputs(SmartDashboard::GetNumber("LeftVictors"),SmartDashboard::GetNumber("RightVictors"));
}

/**
 * Initialization code for test mode should go here.
 * 
 * Use this method for initialization code which will be called each time
 * the robot enters test mode.
 */
void FIRSTRobot::TestInit(){
	std::cerr << typeid(this).name() << "::TestInit() called\n";
}

/**
 * Periodic code for test mode should go here.
 *
 * Use this method for code which will be called periodically at a regular
 * rate while the robot is in test mode.
 */
void FIRSTRobot::TestPeriodic() {
	//std::cerr << typeid(this).name() << "::TestPeriodic() called\n";
	//calibrationAssistant(); //uncomment to run motor controller calibration assistant
	drive.ArcadeDrive(input.GetY(),input.GetZ(), true);
	catapult.update(input.GetButton(Joystick::kTriggerButton),input.GetRawButton(2));
	fork.update(input.GetRawAxis(6));
	if (input.GetRawButton(7)) compressor.Stop();
	if (input.GetRawButton(8)) compressor.Start();
	//LiveWindow::GetInstance()->Run();
	//LiveWindow::GetInstance()->addSensor("Joystick", "input", input);
	Wait(0.05);
}

void FIRSTRobot::calibrationAssistant() {
	std::cerr << typeid(this).name() << "::calibrationAssistant() called\n";
	for (int i = 0; i < 100; i++) { //full foward for 5 seconds
		drive.ArcadeDrive(1.0,0.0); //run full speed (forwards 1) with no turn (0)
		std::cerr << LeftVictors.Get() << "                " << RightVictors.Get() << "\n";
		Wait(0.05);
	}
	for (int i = 0; i < 100; i++) { //full reverse for 5 seconds
		drive.ArcadeDrive(-1.0,0.0); //run full speed backwards (-1) with no turn (0)
		std::cerr << LeftVictors.Get() << "                " << RightVictors.Get() << "\n";
		Wait(0.05);
	}
	for (int i = 0; i < 100; i++) { //rest for 5 seconds
		drive.ArcadeDrive(0.0,0.0); //run full speed backwards (-1) with no turn (0)
		std::cerr << LeftVictors.Get() << "                " << RightVictors.Get() << "\n";
		Wait(0.05);
	}
}
