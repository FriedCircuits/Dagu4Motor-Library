/*
Created by: William Garrido - FriedCircuits.us
Exmaple of Dagu 4 Channel Motor Controller with 4 motors on the Rover 5
Encoder support is provided by Teensy Encoder Library.

Serial processing code is borrowed from
https://github.com/hbrobotics/ros_arduino_bridge

*/



#include <Dagu4Motor.h>

//Serial input
// Variable to hold an input character
char chr;

// Variable to hold the current single-character command
char cmd;

//Character arrays to hold the first argument
char argv1[16];


//Motors
const int pwm_a = 4;  //PWM for CH1 LF
const int pwm_b = 7;  //PWM for CH4 RR  - Revserved Encoder pins to make postive
const int pwm_c = 9;  //PWM for CH2 LR
const int pwm_d = 10;  //PWM for CH3 RF
const int dir_a = 45;  //DIR for CH1
const int dir_b = 43;  //DIR for CH4
const int dir_c = 42;  //DIR for CH2
const int dir_d = 44;  //DIR for CH3

//Current Sensors
const int CURRENTA = A12; 
const int CURRENTB = A13; 
const int CURRENTC = A14; 
const int CURRENTD = A15; 
const int CURRENT_LIMIT = (1024 / 5) * 2.6;  // amps

//Encoder Interrupts
const int encA1 = 2;
const int encA2 = 46;
const int encB1 = 3;
const int encB2 = 47;
const int encC1 = 18;
const int encC2 = 48;
const int encD1 = 19;
const int encD2 = 49;


//Encoder counters


Dagu4Motor motor1(pwm_a, dir_a, CURRENTA); 
Dagu4Motor motor2(pwm_b, dir_b, CURRENTB); 
Dagu4Motor motor3(pwm_c, dir_c, CURRENTC); 
Dagu4Motor motor4(pwm_d, dir_d, CURRENTD); 

void mReverse(int speed)
{

	motor1.setMotorDirection(true);
	motor2.setMotorDirection(false);
	motor3.setMotorDirection(true);
	motor4.setMotorDirection(false);
	motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);

}


void mForward(int speed)
{

	motor1.setMotorDirection(false);
	motor2.setMotorDirection(true);
	motor3.setMotorDirection(false);
	motor4.setMotorDirection(true);
	motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);

}

void mRight(int speed)
{

	motor1.setMotorDirection(true);
	motor2.setMotorDirection(false);
	motor3.setMotorDirection(false);
	motor4.setMotorDirection(true);
	motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);


}

void mLeft(int speed)
{


	motor1.setMotorDirection(false);
	motor2.setMotorDirection(true);
	motor3.setMotorDirection(true);
	motor4.setMotorDirection(false);
	motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);

}



void mStop()
{

	motor1.stopMotors();
	motor2.stopMotors();
	motor3.stopMotors();
	motor4.stopMotors();
}

void setup(){

  Serial.begin(115200);
  Serial.println("Rover 5 Example Sketch");

}



void loop(){

  while (Serial.available() > 0) {
    
    // Read the next character
    chr = Serial.read();

    // Terminate a command with a CR
    if (chr == 13) {
      if (arg == 1) argv1[index_] = NULL;

    }
    // Use spaces to delimit parts of the command
    else if (chr == ' ') {
      // Step through the arguments
      if (arg == 0) arg = 1;
      else if (arg == 1)  {
        argv1[index_] = NULL;
        arg = 2;
        index_ = 0;
      }
      continue;
    }
    else {
      if (arg == 0) {
        // The first arg is the single-letter command
        cmd = chr;
      }
      else if (arg == 1) {
        // Subsequent arguments can be more than one character
        argv1[index_] = chr;
        index_++;
      }
      
    }
  }
  
 
    swtich (cmd){
    
      case 'f':
      
      
      
      break;
      
      case 'l':
      
      
      break;
      
      case 'r':
      
      
      
      break;
      
      case 'b':
        
      break;
      
      
      case 's':
        mStop();
      break;
  
  }
  
  cmd = NULL;
  memset(argv1, 0, sizeof(argv1));
  arg1 = 0;
  arg = 0;
  index_ = 0;




}


