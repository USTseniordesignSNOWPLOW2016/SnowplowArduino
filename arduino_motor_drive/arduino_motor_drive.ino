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
  Serial.begin(57600);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}

