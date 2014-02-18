//Martingrove FIRST Robotics Team 854
//Alexander Momchilov - alexandermomchilov@gmail.com

#include "Fork.h"

Fork::Fork() : Pneumatics(PORTS::FORKLIFT_SPIKE) {
	std::cerr << "Fork() constructed\n";	
}

void Fork::update(float HatSwitchY) { //requires a reference (&) of Joystick
	//std::cerr << typeid(this).name() << "::update() called\n";
	switch ((int) HatSwitchY) {
		case 1:
			contract();
			break;
		case -1:
			extend();
			break;
		//default: disable();
	}
}
