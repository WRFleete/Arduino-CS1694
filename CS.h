#ifndef CS_h
#define CS_h
#include "Arduino.h"

class CS1694
{
public:

	bool mode;
	int dataPin;
	 int dataClock;
	 int StrobePin;
/*
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

 	byte displayMem[14]; 
	CS1694(int ,int ,int);
	//send a raw byte to the CS1694
	void sendtoCS1694(byte inputVar);

	//refresh the display RAM contents
	void updateDisplay(void);
	
	//convert a variable to the display
	void convertVar(unsigned long);

	//display a single digit
	void dispNum( byte segDataIN,  byte dispDigit);
	
	//clear the CS1694 display
	void clearDisplay(void);

	//read the key matrix
	byte readButtons(void);

	//set brightness level
	void setBrightness ( byte brightLevel);

	//set up the display pin hookup etc
	void displaySetup(bool mode);

private:

	  int _dataPin;
	 int _dataClock;
	 int _StrobePin;
 	        		//0 - 9                     //a b   c etc and approximations thereof
	 byte _segData[38]{63,6,91,79,102,109,125,7,127,111,119,124,57,94,121,113,61,118,4,30,99,56,72,84,92,115,103,49,109,120,62,28,29,118,110,91,0,64};
	 byte units;
	 byte tens;
	 byte hunds;
	 byte thous;
	 byte tenthou;
	 byte hundthou; 

         


};




#endif
