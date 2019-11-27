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
byte editDigit = 0;
byte digitVal = 0;
CS1694 CS1694(12,11,8); //data, clock, strobe pins 
void setup() {

CS1694.displaySetup(true); //set chip up as 7x10 mode
  CS1694.setBrightness(7); //set full brightness
  CS1694.clearDisplay(); //clear the display
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 byte inputButtons = CS1694.readButtons();//read the button matrix
if(bitRead(inputButtons,0)){ //when the button is pressed bit = 1
  delay(60);
   digitVal ++;
  if(digitVal > 37){digitVal = 0;}
  CS1694.dispNum(digitVal,editDigit); 
  //setBrightness(brightness);
  }

  if(bitRead(inputButtons,1)){
    delay(60);
 digitVal --;
  if(digitVal > 37){digitVal = 37;}
  CS1694.dispNum(digitVal,editDigit); 
  }
if(bitRead(inputButtons,2)){
  delay(250);
  editDigit --;
  if(editDigit > 5){editDigit = 5;}}
   //dispNum(brightness,7); //turn on the lamps in "digit" 7 counting in binary 0 - 7


  switch(editDigit){ //displays one of the icons above the digit to be edited
    case 0:
    CS1694.dispNum(1,6);
     CS1694.dispNum(0,7);
    break;
    case 1:
    CS1694.dispNum(2,6);
     CS1694.dispNum(0,7);
    break;
    case 2:
    CS1694.dispNum(8,6);
     CS1694.dispNum(0,7);
    break;
    case 3:
    CS1694.dispNum(16,6);
     CS1694.dispNum(0,7);
    break;
    case 4:
     CS1694.dispNum(0,6);
    CS1694.dispNum(1,7);
    break;
    case 5:
     CS1694.dispNum(0,6);
    CS1694.dispNum(2,7);
    break;

   
    }
   //dispNum(63,6); //turn on all the lamps for "digit" 6+7
//dispNum(63,7); 

CS1694.updateDisplay(); //refresh the display, transferring the contents of the variable array into display memory on the chip

 
}
