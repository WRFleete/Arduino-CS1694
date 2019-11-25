#include <CSDisplayDriver.h>
/*
test program for the CSDisplayDriver library written by William Fleete
used with CS1694 LED driver chips found in some cheap dvd players. this sketch works with my particular board with
3 push buttons, six 7 segments and 9 other icon lamps. This library will be a WIP and I am a bit green with these
first library I have written to some degree

uses the 3 buttons on my board to change digits and scroll through the segment data for numbers and letters
digit 0, rightmost digit
digit 5, leftmost digit

digit 6: bit: 5  4    3  2  1     0
              :1 REP ALL :2 A-B  MP3
digit 7: bit: 5    4    3    2   1   0
              VCD DVD Pause play CD TRK 

*/
byte editDigit = 0;
byte digitVal = 0;
CSDisplayDriver CSDisplayDriver(12,11,8); //data,clock, strobe pins
void setup() {

CSDisplayDriver.displaySetup(true); //my display needs 7x10 mode, set false if your display is 6x11 
  CSDisplayDriver.setBrightness(7); //set to full brightness
  CSDisplayDriver.clearDisplay(); //clear any garbage or old data
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 byte inputButtons = CSDisplayDriver.readButtons();//read the button matrix, returns a byte, low 3 bits 

if(bitRead(inputButtons,0)){ //reading which buttons are pressed 
  delay(60);
   digitVal ++;
  if(digitVal > 36){digitVal = 0;}
  CSDisplayDriver.dispNum(digitVal,editDigit); 
  //setBrightness(brightness);
  }

  if(bitRead(inputButtons,1)){
    delay(60);
 digitVal --;
  if(digitVal > 36){digitVal = 36;}
  CSDisplayDriver.dispNum(digitVal,editDigit); 
  }
if(bitRead(inputButtons,2)){
  delay(250);
  editDigit --;
  if(editDigit > 5){editDigit = 5;}}

  switch(editDigit){
    case 0:
    CSDisplayDriver.dispNum(1,6); //show one of the icon lamps to indicate which digit you're editing
     CSDisplayDriver.dispNum(0,7);
    break;
    case 1:
    CSDisplayDriver.dispNum(2,6);
     CSDisplayDriver.dispNum(0,7);
    break;
    case 2:
    CSDisplayDriver.dispNum(8,6);
     CSDisplayDriver.dispNum(0,7);
    break;
    case 3:
    CSDisplayDriver.dispNum(16,6);
     CSDisplayDriver.dispNum(0,7);
    break;
    case 4:
     CSDisplayDriver.dispNum(0,6);
    CSDisplayDriver.dispNum(1,7);
    break;
    case 5:
     CSDisplayDriver.dispNum(0,6);
    CSDisplayDriver.dispNum(2,7);
    break;

   
    }
   

CSDisplayDriver.updateDisplay(); //refresh the display, transferring the contents of the variable array into display memory on the chip

 
}
