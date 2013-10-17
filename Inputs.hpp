//Martingrove FIRST Robotics Team 854
class Input {
	
private: //delcare private variables and methods found in this class
	Joystick *joystick;
	float joystickX; //x coord of joystick
	float joystickY; //y coord of joystick
	float joystickZ; //rotate axis of joystick
	double joystickMagnitude;   //joystick input magnitude (domain: 0 - 1)
	double joystickDirection;   //joystick input direction in RAD (domain: 0 - 2pi)
	const float DEADZONE; //dead zone set to 5% deflection
/**********************************************************************************
(-1,-1) -X- (1,-1)  CCW(-)---0---(+)CW
  |            |
  Y  Joystick  Y
  |Co-ordinates|
  |            |
(-1,1)  -X-  (1,1)
**********************************************************************************/
	
public: //delcare public variables and methods found in this class
	Input();
	~Input();
	
	double getJoystickX;
	double getJoystickY;
	double getJoystickZ;
	double getJoystickMagnitude;
	double getJoystickDirection;
};
