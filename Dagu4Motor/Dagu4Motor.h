/*  
*************************************************************************************
Dagu4Motor.h - Library for driving the Dagu4Motor Driver code.  
Created by William Garrdio
Created: 02/03/2012
*************************************************************************************
Change Log:
02/25/2012 - WG - Added new class for encoders
02/25/2012 - WG - Rewrite class to handle 1 motor per instance
02/28/2020 - WG - Add calculation to distance function, added ticks function
*************************************************************************************
Todo:
Comment functions
Speed function
*************************************************************************************
Notes
pwmPin: Digital pin to set motor speed
dirPin: Digital pin to set motor direction
currPin: Analog pin to monitor current usage
encA: Digital pin for encoder A, should be interrupt pin
encB: Digital pin for encoder B
*************************************************************************************
*/
#ifndef Dagu4Motor_h  
#define Dagu4Motor_h
//#define ENCODER_OPTIMIZE_INTERRUPTS //Fails to compile, vector errors
#include "Encoder.h"
 
#include "Arduino.h" 

class Dagu4Motor  
{  
public:  
    Dagu4Motor(int pwmPin, int dirPin, int currPin, int encAPin, int encBPin); 
	void begin();
    void stopMotors();  
    void setSpeed(int speedMotor);  
    void setMotorDirection(bool isMotor);  
	int getCurrent();
	float getDistance();
	int getSpeed();
	long int getTicks();
	void resetTicks();

	
	
private:  
    int _pwm;  
    int _dir; 
	int _curr;
	int _currRate;
	int _encA;
	int _encB;
	float _distance;
	int _speed;
	long int _ticks;
	Encoder enc;

	

};


#endif
