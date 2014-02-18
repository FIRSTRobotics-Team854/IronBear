//Martingrove FIRST Robotics Team 854
//Alexander Momchilov - alexandermomchilov@gmail.com

#include "Pneumatics.h"

Pneumatics::Pneumatics(int port): relay(port) {
	std::cerr << typeid(this).name() << "(" << port << ") constructed\n";	
}

void Pneumatics::extend() {
	std::cerr << typeid(this).name() << "::extend() called\n";
	relay.Set(Relay::kForward);
}

void Pneumatics::contract() {
	std::cerr << typeid(this).name() << "::contract() called\n";
	relay.Set(Relay::kReverse);
}

void Pneumatics::disable() {
	//std::cerr << typeid(this).name() << "::disable() called\n";
	relay.Set(Relay::kOff);
}

void Pneumatics::enable() {
	//std::cerr << typeid(this).name() << "::disable() called\n";
	relay.Set(Relay::kOn);
}

Relay::Value Pneumatics::get() {
	return relay.Get();
}
