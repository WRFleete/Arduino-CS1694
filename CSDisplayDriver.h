#ifndef CSDisplayDriver_h
#define CSDisplayDriver_h
#include "Arduino.h"

class CSDisplayDriver
{
public:

	bool mode;
	int dataPin;
	 int dataClock;
	 int StrobePin;
/* memory map of the board I have based this on
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

digit 6: bit: 5  4    3  2  1     0
              :1 REP ALL :2 A-B  MP3
digit 7: bit: 5    4    3    2   1   0
              VCD DVD Pause play CD TRK */

 	byte displayMem[14]; //scratchpad to store the data for the display before being sent out
	CSDisplayDriver(int ,int ,int); //pins the chip is hooked up to, data pin, clock pin, strobe pin
	//send a raw byte to the CS1694
	void sendtoCS1694(byte inputVar);

	//refresh the display RAM contents
	void updateDisplay(void);
	
	//convert a variable to the display
	void convertVar(unsigned long); //converts an up to 6 digit number (automatically truncates to the MSDs if longer)

	//display a single digit
	void dispNum( byte segDataIN,  byte dispDigit); //0-5 are the 7 segment displays 6&7 are the icon lamps which ignore the segment data array and are sent raw
	
	//clear the CS1694 display
	void clearDisplay(void); //blanks the display (fills with 0)

	//read the key matrix
	byte readButtons(void); //only returns 3 of the buttons ATM as that is what is hooked up on my board

	//set brightness level
	void setBrightness ( byte brightLevel); //0-7. 0 = dim 7+ full brightness (automatically caps at 7 if a larger value sent)

	//set up the display pin hookup etc
	void displaySetup(bool mode); // sets to 7x10 or 6x11 display modes when true or false respectivly

private:

	  int _dataPin;
	 int _dataClock;
	 int _StrobePin;
 	        		//0 - 9                     //a b   c etc and approximations thereof
	 byte _segData[37]{63,6,91,79,102,109,125,7,127,111,119,124,57,94,121,113,61,118,4,30,99,56,72,84,92,115,103,49,109,120,62,28,29,118,110,91,0};
	//segment data for the numbers and a few symbols(letters etc) end of array is a blank 
	byte units;
	 byte tens;
	 byte hunds;
	 byte thous;
	 byte tenthou;
	 byte hundthou; 

         


};




#endif
