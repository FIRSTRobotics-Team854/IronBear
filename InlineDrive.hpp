class InlineDrive {
private: //delcare private variables and methods found in this class
	
	//motor intensity (domain: 0 - 1)
	double flMotor;
	double frMotor;
	double blMotor;
	double brMotor;
	
public: //delcare public variables and methods found in this class
	InlineDrive();
	~InlineDrive();
	
	void update(double joystickDirection, double joystickMagnitude ,double joystickZ);
	double getflMotor();
	double getfrMotor();
	double getblMotor();
	double getbrMotor();
};
