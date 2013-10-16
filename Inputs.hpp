class Inputs {
	
private: //All these bools stored the state of the various Joystick buttons (1/0)
	Joystick *joystick;
	float joystickX; //x coord of joystick
	float joystickY; //y coord of joystick
	float joystickZ; //rotate axis of joystick
	double joystickMagnitude;   //joystick input magnitude (domain: 0 - 1)
	double joystickDirection;   //joystick input direction in RAD (domain: 0 - 2pi)
	const float DEADZONE; //dead zone set to 5% deflection
	/*
(-1,-1) -X- (1,-1)
  |            |
  Y  Joystick  Y
  |Co-ordinates|
  |            |
(-1,1)  -X-  (1,1)*/
	
public: //declare methods in this class to be made public
	Inputs();
	~Inputs();
};
