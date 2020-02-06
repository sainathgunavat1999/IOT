#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins

LiquidCrystal lcd(0, 1, 8, 9, 10, 11); /// REGISTER SELECT PIN,ENABLE PIN,D4 PIN,D5 PIN, D6 PIN, D7 PIN
const int echoPin=2;
const int trigPin=3;
long duration;
int distance;
void setup()

{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//Serial.begin(2400); // Starts the serial communication
lcd.begin(16, 2);


}

void loop()

{

// set the cursor to column 0, line 1

//lcd.print("Ultrasonic Sensor");//print name


// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if(distance<3000){
lcd.setCursor(0, 0); // set the cursor to column 0, line 2

lcd.print("Distance:");//print name

lcd.print(distance);
delay(500);
lcd.clear();
}
}
