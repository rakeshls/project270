#include <Adafruit_NeoPixel.h>

// NeoPixel LED controls
const byte data_pin = 11;
const byte led_num = 16;

// creating an object
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(led_num, data_pin, NEO_GRB + NEO_KHZ800);

int led_index=8;
int y=0;
// variable to helps us assign colors
int c=128;

// add the pins for joystick here
const byte hpin = A0;
const byte vpin = A1;

void setup(){
  // put your setup code here, to run once:

  Serial.begin(9600);
 
  pixels.begin(); // initialize the library
  pixels.show();
}

void loop(){
  // put your main code here, to run repeatedly:

  check_direction();
  for(int i=0;i<=15;i++)
    pixels.setPixelColor(i, 31.4, 78.4 ,c);
  
  pixels.setPixelColor(led_index, c, 47.1,31.4);
  pixels.show();
  delay(100);

}

void check_direction(){

  if (analogRead(hpin) > 600) led_index++;
  else if (analogRead(hpin) < 400) led_index--;
  else if (analogRead(vpin) > 600) c=c+10;
  else if (analogRead(vpin) < 400) c=c-10;
  
  led_index = led_index%15;

  if(led_index<0)
    led_index = 15+led_index;

  c = constrain(c , 0 , 255);

}
