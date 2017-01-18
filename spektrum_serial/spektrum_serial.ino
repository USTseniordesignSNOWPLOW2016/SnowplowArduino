int ch1; // Here's where we'll keep our channel values
int e_stop_pin_1 = 9;
int e_stop_pin_2 = 10;
int green_led = 13;
int red_led = 12;
int spektrum_in = 6;
void setup() {
  
  pinMode(spektrum_in, INPUT);
  pinMode(green_led, OUTPUT); // Set our input pins as such
  pinMode(e_stop_pin_1,OUTPUT);
  pinMode(e_stop_pin_2,OUTPUT);
  pinMode(red_led,OUTPUT);
  Serial.begin(9600); // Pour a bowl of Serial
 digitalWrite(e_stop_pin_1, LOW);
 digitalWrite(e_stop_pin_2, LOW);
 digitalWrite(green_led,LOW);
 digitalWrite(red_led, HIGH);
 delay(3000);
}

void loop() {

  
  ch1 = pulseIn(spektrum_in, HIGH, 25000); // Read the pulse width of 

  //Serial.print("Channel 1:"); // Print the value of 
  //Serial.println(ch1);        // each channel
  
  digitalWrite(e_stop_pin_1,HIGH);
  digitalWrite(e_stop_pin_2,HIGH);
  digitalWrite(red_led,LOW);
  if (ch1 > 2300)
  { 
    //Serial.println("E-STOP Triggered!!");
    digitalWrite(e_stop_pin_1, LOW);
    digitalWrite(e_stop_pin_2, LOW);
    digitalWrite(red_led,HIGH);
    while(1);
  }
}
