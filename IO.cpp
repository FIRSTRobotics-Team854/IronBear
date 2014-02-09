//  I:O.cpp
//  Created by Alexander Momchilov on 1/19/2014.

//change to #define HOLONOMIC for Holonomic Drive
#define INLINE

//Encoder Wiring:
//http://www.usdigital.com/products/cables-connectors/cables/4-pin/CA-MIC4-W4-NC
//1	+5VDC power	Orange/Red
//A Channel	Blue/Green
//Ground	Brown/Black
//B Channel	Yellow

/*#ifdef HOLONOMIC //IO map for holonomic drive

//Output Ports:
static const int FRONT_LEFT_MOTOR = 1;
static const int FRONT_RIGHT_MOTOR = 2;
static const int BACK_LEFT_MOTOR = 3;
static const int BACK_RIGHT_MOTOR = 4;

//Input Ports
static const int FRONT_LEFT_ENCODER_A = 1;
static const int FRONT_LEFT_ENCODER_B = 2;
static const int FRONT_RIGHT_ENCODER_A = 3;
static const int FRONT_RIGHT_ENCODER_B = 4;
static const int BACK_LEFT_ENCODER_A = 5;
static const int BACK_LEFT_ENCODER_B = 6;
static const int BACK_RIGHT_ENCODER_A = 7;
static const int BACK_RIGHT_ENCODER_B = 8;

#endif*/

#ifdef INLINE //IO map for inline drive

//Output Ports:
static const int LEFT_MOTORS = 1;
static const int RIGHT_MOTORS = 2;

//Input Ports
static const int LEFT_ENCODER_A = 1;
static const int LEFT_ENCODER_B = 2;
static const int RIGHT_ENCODER_A = 3;
static const int RIGHT_ENCODER_B = 4;

#endif