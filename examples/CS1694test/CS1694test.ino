#include <CSDisplayDriver.h>
/*
test program for the CSDisplayDriver library written by William Fleete
used with CS1694 LED driver chips found in some cheap dvd players. this sketch works with my particular board with
3 push buttons, six 7 segments and 9 other icon lamps. This library will be a WIP and I am a bit green with these
first library I have written to some degree

uses the 3 buttons on my board to change digits and scroll through the segment data for numbers and letters

this test program just displays the millis() on the LED display (or the first 6 MSD if larger than 6 digits)
none of the push buttons will respond

*/
byte editDigit = 0;
byte digitVal = 0;
CSDisplayDriver CSDisplayDriver(12,11,8); //data,clock,strobe pins
void setup() {

CSDisplayDriver.displaySetup(true); //my display is "7x10" mode, set false if display doesnt look right ("6x11" mode)
  CSDisplayDriver.setBrightness(7); //full brightness level
  CSDisplayDriver.clearDisplay(); // clear the display memory
  
}

void loop() {

CSDisplayDriver.convertVar(millis()); // convert a variable to 7 segment numbers for the display, takes unsigned long, shows first 6 MSD 

   

CSDisplayDriver.updateDisplay(); //refresh the display, transferring the contents of the variable array into display memory on the chip

 
}
