//Martingrove FIRST Robotics Team 854
//Alexander Momchilov - alexandermomchilov@gmail.com

#ifndef __Robot_2014__PNEUMATICS__
#define __Robot_2014__PNEUMATICS__

#include "WPILib.h"

#include "PORTS.h"

class Pneumatics {
private: //delcare private variables and methods found in this class
	Relay relay;
	
public: //delcare public variables and methods found in this class
	Pneumatics(int port);
	//virtual ~Pneumatics();
	
	void Pneumatics::extend();
	void Pneumatics::contract();;
	void Pneumatics::enable();
	void Pneumatics::disable();
	Relay::Value Pneumatics::get();
	//virtual void Pneumatics::update(bool trigger);
};

#endif /* defined __Robot_2014__PNEUMATICS__ */
