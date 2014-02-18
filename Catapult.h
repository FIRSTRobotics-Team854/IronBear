//Martingrove FIRST Robotics Team 854
//Alexander Momchilov - alexandermomchilov@gmail.com

#ifndef __Robot_2014__CATAPULT__
#define __Robot_2014__CATAPULT__

#include "WPILib.h"

#include "PORTS.h"
#include "Pneumatics.h"

class Catapult : public Pneumatics {
private: //delcare private variables and methods found in this class

	
public: //delcare public variables and methods found in this class
	Catapult();
	
	void Catapult::update(bool trigger, bool disengage);
	void Catapult::shoot();
};

#endif /* defined __Robot_2014__CONFIG__ */
