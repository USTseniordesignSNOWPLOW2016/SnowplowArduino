//Arduino Ultrasonic Sensor Publisher (3 Sensors - Front, Middle, Right)
#include <ros.h>
#include <plow_waypoint_nav/plow_ultrasonic.h>
#include <NewPing.h>

/*-----( Declare Constants and Pin Numbers )-----*/
#define  TRIGGER_PIN1  11
#define  ECHO_PIN1     10
#define  TRIGGER_PIN2  9
#define  ECHO_PIN2     8
#define  TRIGGER_PIN3  7
#define  ECHO_PIN3     6
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters).
                         //Maximum sensor distance is rated at 400-500cm.

/*--------Instantiate node handle-------------*/
ros::NodeHandle nh;
// std_msgs::Int32MultiArray sonar;
plow_waypoint_nav::plow_ultrasonic UltraData; //define a message of type "plow_ultrasonic" that will be used to publish ultrasonic sensor values
// ros::Publisher sonar_pub("sonar", &sonar);
ros::Publisher Ultra_pub("/ultrasonic_data", &UltraData); //define a publisher for publishing all of the ultrasonic sensor data

/*-----( Declare objects )-----*/
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar3(TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
/*-----( Declare Variables )-----*/
int DistanceIn;
int DistanceCm;
int Front;
int Side1;
int Side2;



void setup()
{
  // Serial.begin(9600);
  nh.initNode();
  nh.advertise(Ultra_pub);
  
}

void checkSensor(char sensor)
{
  switch(sensor)
  {
    case 'L':
      delay(100);
      UltraData.Sensor_L = sonar1.ping_cm();
    break;
    case 'M':
      delay(100);
      UltraData.Sensor_M = sonar2.ping_cm();
    break;
    case 'R':
      delay(100);
      UltraData.Sensor_R = sonar3.ping_cm();        
    break;

  }
}

void loop()
{
  checkSensor('L');
  delay(100);
  checkSensor('M');
  delay(100);
  checkSensor('R');
  delay(100);
  Ultra_pub.publish(UltraData); //publish the ultrasonic scans
  nh.spinOnce();
}

