/* 
 * Title: Arduino Motor Driver
 * Description: Arduino file used for taking ROS topic information and sending it to an Arduino to drive a Sabertooth Motor Controller
 * Author: Brandon Jameson
 */

#include <ros.h>
#include <std_msgs/String.h>
#include <SoftwareSerial.h>
#define txPin 1 //define the TX pin that will connect to the Saberooth Motor Controller

ros::NodeHandle  nh;
SoftwareSerial MotorController = SoftwareSerial(0, txPin); //set up the serial on TX pin of Arduino

void messageCb( const std_msgs::String& msg){
      Serial.write("M1: ");//prefix for motor command
      Serial.write(msg.data);
      Serial.write("\r\n");
}

void messageCb_2( const std_msgs::String& msg){
      Serial.write("M2: ");//prefix for motor command
      Serial.write(msg.data);
      Serial.write("\r\n");
}

ros::Subscriber<std_msgs::String> sub("sabertooth_motor_data", &messageCb );
ros::Subscriber<std_msgs::String> sub_2("sabertooth_motor_data_2", &messageCb_2 );

void setup()
{ 
  nh.initNode();
  nh.subscribe(sub);
  nh.subscribe(sub_2);
  Serial.begin(9600);
  
  pinMode(txPin, OUTPUT);
  MotorController.begin(9600); //set the baud rate for the tx output to be 9600
}

void loop()
{  
  nh.spinOnce();
  delay(10);
}

