//Martingrove FIRST Robotics Team 854
//Alexander Momchilov - alexandermomchilov@gmail.com

#include "Catapult.h"

Catapult::Catapult() : Pneumatics(PORTS::CATAPULT_SPIKES) {
	std::cerr << typeid(this).name() << "() constructed\n";	
}

void Catapult::update(bool trigger, bool disengage) {
	//std::cerr << typeid(this).name() << "::update() called\n";
	if (trigger) shoot();
	else if (disengage) contract();
	//else disable();
}

void Catapult::shoot() {
	std::cerr << typeid(this).name() << "::shoot() called\n";
	extend();
}
