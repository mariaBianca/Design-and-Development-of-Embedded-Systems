#include <LEDDisplay2.h>
/**
* @author: Group 4 and Group 5
* Aseel Naji
* Maria-Bianca Cindroi
* Johan Johansson
* Antonino Sauleo
* Filip Isakovski
* Yu Jet4
* 15049
* 15101
**/                                          

LEDDisplay2 *led;

#define EXTEND 12

int tempPin = A0;
int cel;
int counter;

//SWITCH
const int switchPin1 = 12; // the number of the switch’s pin
 int maxValue=0;

// set variables:
int switchState1 = 0; // variable for reading the switch’s status
int switchState2 = 0; // variable for reading the switch’s status
int switchState3 = 0; // variable for reading the switch’s status
int switchState4 = 0; // variable for reading the switch’s status
byte test = B0000; // Variable for printing value over serial debug

void setup() 
{
    Serial.begin(9600);
    
    int digitFlagPins[] = {10, 11};
    int segmentPins[] = {2, 3, 4, 5 ,6 ,7 ,8, 9};
    int decimalPointPin = 9;
    led = new LEDDisplay2(2, digitFlagPins, segmentPins, decimalPointPin);
    
}

void loop()  
{  
  int switchThing = digitalRead(12);
  
  counter++;
  if(counter == 100){
    read_display_temp();
    if(cel>maxValue){
      maxValue = cel;
    }
    counter = 0;
    
  }
    if(switchThing == 1){
    int first = cel/10;
    led->displayNumber(first, 0);  
    delay(5);
    int second = cel%10;
    led->displayNumber(second, 1); 
    delay(5);
  
  }else if (switchThing == 0){
    int first = maxValue/10;
    led->displayNumber(first, 0);  
    delay(5);
    int second = maxValue%10;
    led->displayNumber(second, 1); 
    delay(5);
  }
    
}

void read_display_temp()
{
      int reading = analogRead(tempPin);  
 
     // converting that reading to voltage.
     int mv = reading * 500 / 1024;
     cel = mv;///10;
    
    Serial.print(cel); Serial.println(" degrees C"); 
    
    delay(5);
} 
