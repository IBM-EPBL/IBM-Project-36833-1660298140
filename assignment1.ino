/* This code is used to give warning from the buzzer when 
the ultrasonic sensor detects objects closer than 0.5 meter
*/
//Define pins for ultrasonic sensor and buzzer
int const trigPin = 10;
int const echoPin = 9;
const int buzzer = 3; //buzzer to arduino pin 9
int led_pin = 7;//led
void setup()
{
  pinMode(10, OUTPUT);
  pinMode(9, INPUT);
  pinMode(3, OUTPUT); // Set buzzer - pin 9 as an output
}
void loop()
{
  int duration, distance;
  digitalWrite(10, HIGH);
  delay(1); // Wait for 1 millisecond(s)
  digitalWrite(10, LOW);
  //Measure the pulse input in echo pin
  duration = pulseIn(9, HIGH);
  //Distance is half the duration devided by 29.1(from datasheet)
   distance = (duration/2)/29.1;
  // if distance less than 0.5 m and more than 0
  if(distance <=50 && distance >=0)
  {
    //buzz
  tone(buzzer, 369); // Send 1KHz sound signal...
          // ...for 1 sec
  //led on
  digitalWrite(led_pin, HIGH);
  } else{
    //Don't buzz
  noTone(buzzer);     // Stop sound...
     // ...for 1sec
    // led off
    	digitalWrite(led_pin, LOW);
  }
  //Waiting 60ms wont hurt anyone
  delay(60);
}