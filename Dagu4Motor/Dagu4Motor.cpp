/*  
Dagu4Motor.cpp - Library for driving the Dagu4Motor Driver code.  
Created by William Garrdio
Created on: 02/03/2012
02/25/2012 - Rewrite class to handle 1 motor per instance

*/  
#include "Arduino.h"  
#include "Dagu4Motor.h"


Dagu4Motor::Dagu4Motor(int pwmPin, int dirPin, int currPin, int encAPin, int encBPin) //: enc(encAPin, encBPin)
{  
	_pwm = pwmPin;  
    _dir = dirPin;  
    _curr = currPin;
	_currRate = 0;
	_encA = encAPin;
	_encB = encBPin;
    _distance = 0;
	_speed = 0;	
	
}

void Dagu4Motor::begin()
{

	
    pinMode(_pwm, OUTPUT);  
    pinMode(_dir, OUTPUT); 
	pinMode(_curr, INPUT);
	
}

void Dagu4Motor::stopMotors()  
{  
    digitalWrite(_pwm, LOW);  
    setSpeed(0);  
}  

void Dagu4Motor::setSpeed(int speedMotor)  
{  
	speedMotor = constrain(speedMotor, 0, 255);
	
	analogWrite(_pwm, speedMotor);
	_speed=speedMotor;

}

void Dagu4Motor::setMotorDirection(bool isMotor)  
{  

    if(isMotor)  
    {  
      digitalWrite(_dir, LOW);  //Set motor direction, 1 low, 2 high  
    }  
    else  
    {  
      digitalWrite(_dir, HIGH);  //Reverse motor direction, 1 high, 2 low  
    } 


}

int Dagu4Motor::getCurrent()
{

_currRate = analogRead(_curr);

return _currRate;
}

float Dagu4Motor::getDistance()
{
	
//	_distance = enc.read();
//	_distance = (((_distance/333.33)*7.8)/12);

return _distance;
}


int Dagu4Motor::getSpeed()
{


return _speed;
}

long int Dagu4Motor::getTicks()
{

//	_ticks = enc.read();

return _ticks;
}

void Dagu4Motor::resetTicks()
{

	//enc.write(0);
}





	
