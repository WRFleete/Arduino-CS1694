#include <CS.h>
/*
test program for the CSDisplayDriver library written by William Fleete
used with CS1694 LED driver chips found in some cheap dvd players. this sketch works with my particular board with
3 push buttons, six 7 segments and 9 other icon lamps. This library will be a WIP and I am a bit green with these
first library I have written to some degree

uses the 3 buttons on my board to change digits and scroll through the segment data for numbers and letters



*/
byte editDigit = 0;
byte digitVal = 0;
CS1694 CS1694(12,11,8); //change these to your IO pins that you are using (data, clock, strobe)
void setup() {
Serial.begin(9600);
CS1694.displaySetup(true); //set false if your display works with 6x11 leave true if segments are set up as 7x10 
  CS1694.setBrightness(7);
  CS1694.clearDisplay();
  pinMode(5,INPUT_PULLUP); // attach a push button to ground for advancing the segment 
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:



for(unsigned int i = 0; i < 14; i++){  
  byte address = 0xC0 | i; 
  Serial.println(address, HEX);
   
  byte data = 1;
  for(byte j = 0; j < 8; j++){
    CS1694.sendtoCS1694(address);
  delay(1);
    Serial.print (data,DEC);
   CS1694.sendtoCS1694(data);
   Serial.print(":");
digitalWrite(8,HIGH);
data = data << 1;
//CS1694.updateDisplay(); 
while(digitalRead(5)){delay(250);}//wait for input 5 to pull low before advancing 
delay (1000);
}
CS1694.clearDisplay();
 Serial.println();
}
   

//refresh the display, transferring the contents of the variable array into display memory on the chip

 
}
