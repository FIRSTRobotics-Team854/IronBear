//Martingrove FIRST Robotics  Team 854


//update set point of PID if the change in speed is great enough

if(fabs(PIDtl->GetSetpoint() - motor[1]*220) > 22)
PIDfl->SetSetpoint(motor[1]*220.0f);

if(fabs(PIDtr->GetSetpoint() - motor[2]*220) > 22)
PIDfr->SetSetpoint(motor[2]*220.0f);

if(fabs(PIDbl->GetSetpoint() - motor[0]*220) > 22)
PIDbl->SetSetpoint(motor[0]*220.0f);

if(fabs(PIDbr->GetSetpoint() - motor[3]*220) > 22)
PIDbr->SetSetpoint(motor[3]*220.0f);



/*cerr<<"M1 Setpoint: "<<PIDtl->GetSetpoint()<<endl;
 cerr<<"M2 Setpoint: "<<PIDtr->GetSetpoint()<<endl;
 cerr<<"M0 Setpoint: "<<PIDbl->GetSetpoint()<<endl;
 cerr<<"M3 Setpoint: "<<PIDbr->GetSetpoint()<<endl;*/


cerr<<"Direction: "<<joystickDirection<<endl;
cerr<<"Magnitude: "<<joystickMagnitude<<endl;
cerr<<"Z-Value: "<<joystickZ<<endl;