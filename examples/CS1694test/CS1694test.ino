#include <CS.h>
/*
test program for the CSDisplayDriver library written by William Fleete
used with CS1694 LED driver chips found in some cheap dvd players. this sketch works with my particular board with
3 push buttons, six 7 segments and 12 other icon lamps. This library will be a WIP and I am a bit green with these
first library I have written to some degree

uses the 3 buttons on my board to change digits and scroll through the segment data for numbers and letters
memory map of my particular board
even addresses                                    odd addresses
0:  bit 2, 3, 4, & 7: seg A of display 3,2,1,4    1: bit 0, 1: seg A of display 5 + 6
    bit 5, 6: MP3, TRK
2:  seg B                                         3: seg B
    bit 5, 6: A-B, CD
4:  Seg C                                         5: seg C
    bit 5, 6: colon 2 ,PLAY icon
6:  Seg D                                         7: seg D
    bit 5, 6: ALL,PAUSE icon
8:  Seg E                                         9: seg E
    bit 5, 6: REP,DVD
A:  Seg F                                         B: seg F
    bit 5, 6: colon 1, VCD 
C:  Seg G                                         D: seg G
    bit 5, 6: (nothing)

bit positions for digit 6+7 to turn on particular lamps
digit 6: bit: 5  4    3  2  1     0
              :1 REP ALL :2 A-B  MP3
digit 7: bit: 5    4    3    2   1   0
              VCD DVD Pause play CD TRK */

*/
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

   

CS1694.updateDisplay(); //refresh the display, transferring the contents of the variable array into display memory on the chip

 
}
