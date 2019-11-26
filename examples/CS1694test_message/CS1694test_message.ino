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
 byte inputButtons = CS1694.readButtons();//read the button matrix
//convertVar(millis()); // convert a variable to 7 segment numbers for the display, takes unsigned long, shows first 6 MSD 
if(bitRead(inputButtons,0)){
  delay(60);
   digitVal ++;
  if(digitVal > 36){digitVal = 0;}
  CS1694.dispNum(digitVal,editDigit); 
  //setBrightness(brightness);
  }

  if(bitRead(inputButtons,1)){
    delay(60);
 digitVal --;
  if(digitVal > 36){digitVal = 36;}
  CS1694.dispNum(digitVal,editDigit); 
  }
if(bitRead(inputButtons,2)){
  delay(250);
  editDigit --;
  if(editDigit > 5){editDigit = 5;}}
   //dispNum(brightness,7); //turn on the lamps in "digit" 7 counting in binary 0 - 7
//dispNum(127,6); //turn on all the lamps 
//dispNum(127,7); 

  switch(editDigit){
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
   

CS1694.updateDisplay(); //refresh the display, transferring the contents of the variable array into display memory on the chip

 
}
