/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle  nh;

void messageCb( const std_msgs::String& msg){
  //digitalWrite(13, HIGH-digitalRead(13));   // blink the led
  Serial.write("\r\n");
  Serial.write(msg.data);
}

ros::Subscriber<std_msgs::String> sub("sabertooth_motor_data", &messageCb );

void setup()
{ 
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  nh.getHardware()->setBaud(9600);//force the baud rate to be set at 9600 (if this has problems, remove this and replace the line below to 57600)
  Serial.begin(9600);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}

