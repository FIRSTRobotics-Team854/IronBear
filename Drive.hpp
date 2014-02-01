//  Drive.h
//  Created by Alexander Momchilov on 2/1/2014.
//

#ifndef __Robot_2014__Drive__
#define __Robot_2014__Drive__

#include <iostream>

class Drive {	
public:
	Drive();
	~Drive();
	virtual void update(double joystickDirection, double joystickMagnitude ,double joystickZ);
};

#endif /* defined(__Robot_2014__Drive__) */
