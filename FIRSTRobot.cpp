//Martingrove FIRST Robotics Team 854
#include "FIRSTRobot.hpp"
#include <cmath>
#include "IO.cpp"

void FIRSTRobot::RobotInit() {
	
	//Instantiate new a Input object
	input = new Input();
	
#ifdef HOLONOMIC
	//Instantiate new a HolonomicDrive object
	drive = new HolonomicDrive();
#endif

#ifdef INLINE
	//Instantiate new a HolonomicDrive/InlineDrive object
	drive = new InlineDrive();
#endif
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
	drive->update(input->getJoystickDirection(), input->getJoystickMagnitude(), input->getJoystickX(), input->getJoystickY(), input->getJoystickZ());
}
 
void FIRSTRobot::TestPeriodic() {
}

START_ROBOT_CLASS(FIRSTRobot);
