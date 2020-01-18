#include <CS.h>
/*
LED
---------
C3 1

DIG1
---------
C4 2  e 
C4 4  d
C4 16 c
C4 64 g
C4 128  a
C5 1  f
C5 2  b

DIG2
---------
C6 2  e 
C6 4  d
C6 16 c
C6 64 g
C6 128  a
C7 1  f
C7 2  b

DIG3
---------
CA 2  e 
CA 4  d
CA 16 c
CA 64 g
CA 128  a
CB 1  f
CB 2  b

DIG4
---------
C8 2  e 
C8 4  d
C8 16 c
C8 64 g
C8 128  a
C9 1  f
C9 2  b

COLON
---------
C6 8   
CA 8 */

byte editDigit = 0;
byte digitVal = 0;
CS1694 CS1694(12,11,8); //data,clock,strobe pins
void setup() {

CS1694.displaySetup(true); //set to 7x10 mode, set false for 6x11 mode
  CS1694.setBrightness(7); //full brightness, range is 0-7 higher values will be capped
  CS1694.clearDisplay(); //clear any junk off the display
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

CS1694.convertVar(millis()); // convert a variable to 7 segment numbers for the display, takes unsigned long, shows first 6 MSD 

   CS1694.LED(1);
   CS1694.colon (1);

CS1694.updateDisplay(); //refresh the display, transferring the contents of the variable array into display memory on the chip

 
}
