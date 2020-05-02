/*
 * Project ParticleCloudFunction
 * Description: is used to control three LED via HTTP POST methods, it also has a variable that can be
 *              accessed via a GET request to find the current state of which LED is lit up.
 * 
 *              Exposes three functions for setting the leds on and off the function also have return values for later devlopment
 *              Upon toggling one of the led control functions it changes to the value of LEDonState to the last run led function
 * 
 *              Note: this physical control was wirtten to handle a webpage that uses a toggle radio button selection to toggle the leds
 *                    meaning that only one LED will be lit up and one given time, a per a traffic light. 
 * Author: Sean Corcoran 
 * Date: 1/05/20
 */

//pin declarations
int led = D7;       // Red
int yellowLed = D6; // Yellow
int greenLed = D5;  // Green

//current state of the traffic light
String LEDOnStatus;

void setup()
{
  // pin IO declarations
  pinMode(led, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  // Exposes the value of a variable on the Photon to an http GET method
  Particle.variable("ledState", &LEDOnStatus, STRING);

  // Exposes a function on the Photon to an http POST method
  Particle.function("led", ledToggle);
  Particle.function("ledYellow", yellowLedToggle);
  Particle.function("ledGreen", greenLedToggle);
}

void loop()
{
  //No need for loop
}

// create a functions for each led that will take a string "on" or "off"
// ledToggle("on"); turns on the LED
// ledToggle("off"); turns off the LED

// Red LED control
int ledToggle(String command)
{
  if (command == "on")
  {
    digitalWrite(led, HIGH);
    LEDOnStatus = "Red"; // <-- set public led status to red
    return 1;
  }
  else if (command == "off")
  {
    digitalWrite(led, LOW);
    return 0;
  }
  else
  {
    return -1;
  }
}
// Yellow LED control
int yellowLedToggle(String command)
{
  if (command == "on")
  {
    digitalWrite(yellowLed, HIGH);
    LEDOnStatus = "Amber"; // <-- set public led status to amber
    return 1;
  }
  else if (command == "off")
  {
    digitalWrite(yellowLed, LOW);
    return 0;
  }
  else
  {
    return -1;
  }
}
// Green LED control
int greenLedToggle(String command)
{
  if (command == "on")
  {
    digitalWrite(greenLed, HIGH);
    LEDOnStatus = "Green"; // <-- set public led status to green
    return 1;
  }
  else if (command == "off")
  {
    digitalWrite(greenLed, LOW);
    return 0;
  }
  else
  {
    return -1;
  }
}