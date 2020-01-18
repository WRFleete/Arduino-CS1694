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
LED
---------
C3 1

DIG1
---------
C4 2	e 
C4 4	d
C4 16	c
C4 64	g
C4 128	a
C5 1	f
C5 2	b

DIG2
---------
C6 2	e 
C6 4	d
C6 16	c
C6 64	g
C6 128	a
C7 1	f
C7 2	b

DIG3
---------
CA 2	e 
CA 4	d
CA 16	c
CA 64	g
CA 128	a
CB 1	f
CB 2	b

DIG4
---------
C8 2	e 
C8 4	d
C8 16	c
C8 64	g
C8 128	a
C9 1	f
C9 2	b

COLON
---------
C6 8	 
CA 8

*/

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
	unsigned long readButtons(void);

	//set brightness level
	void setBrightness ( byte brightLevel);

	//set up the display pin hookup etc
	void displaySetup(bool mode);
	
	//controls the LED
	void LED(bool);
	//turns on both colons
	void colon(bool);

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


         


};




#endif
