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
CS1694 CS1694(12,11,8);
void setup() {

CS1694.displaySetup(true);
  CS1694.setBrightness(7);
  CS1694.clearDisplay();
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

CS1694.convertVar(millis()); // convert a variable to 7 segment numbers for the display, takes unsigned long, shows first 6 MSD 

   

CS1694.updateDisplay(); //refresh the display, transferring the contents of the variable array into display memory on the chip

 
}
