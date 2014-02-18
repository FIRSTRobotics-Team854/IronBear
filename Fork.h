//Martingrove FIRST Robotics Team 854
//Alexander Momchilov - alexandermomchilov@gmail.com

#ifndef __Robot_2014__FORK__
#define __Robot_2014__FORK__

#include "WPILib.h"

#include "PORTS.h"
#include "Pneumatics.h"

class Fork : public Pneumatics {
private: //delcare private variables and methods found in this class

	
public: //delcare public variables and methods found in this class
	Fork();
	
	void Fork::update(float HatSwitchY);
};

#endif /* defined __Robot_2014__CONFIG__ */
