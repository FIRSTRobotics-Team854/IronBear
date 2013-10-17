//Martingrove FIRST Robotics Team 854
/*
 motor[1]----motor[2]
   |    Front   |
   |    Motor   |
   |  Numbering |
   |            |
 motor[0]----motor[3]*/

#define PI 3.14159


class DriveProcessing
{
private:
	
	
	double motorAngle;
	double motor;//motor intensity (domain: 0 - 1)	//motor angles (rad)
	
public: //delcare public methods found in this class
	DriveProcessing(Victor *mfl, Victor *mfr, Victor *mbl, Victor *mbr);
	~DriveProcessing();
	
	void update(double joystickDirection, double joystickMagnitude);
};
