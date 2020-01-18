#include "Arduino.h"
#include "CS.h"





 CS1694::CS1694(int dataPin,int dataClock,int StrobePin){ 
	pinMode(dataClock, OUTPUT);
	 _dataClock = dataClock;
	digitalWrite(_dataClock,HIGH);
	pinMode(dataPin,OUTPUT);
	pinMode(StrobePin,OUTPUT);  
	_StrobePin = StrobePin;
	digitalWrite(_StrobePin,HIGH);      

_dataPin = dataPin;

        }


void  CS1694::sendtoCS1694(byte inputVar){ //routine for sending commands to the CS1694 raw
     digitalWrite(_StrobePin,LOW);
    digitalWrite(_dataClock,LOW);
    shiftOut(_dataPin,_dataClock, LSBFIRST,inputVar);

  
  }
void    CS1694::updateDisplay(){
for(unsigned int i = 0; i < 14; i++){  
  byte address = 0xC0 | i; 
   CS1694::sendtoCS1694(address);
  delay(1);
   CS1694::sendtoCS1694(displayMem[i]);
digitalWrite(_StrobePin,HIGH);}}

  void    CS1694::convertVar(unsigned long inputVar){
    if (inputVar >= 10000){
      do{inputVar /= 10;}while(inputVar >= 10000); //automatically fit variable into 4 digits
      
      }
    units = inputVar % 10;
tens = (inputVar /10) %10;
hunds = (inputVar /100) %10;
thous = (inputVar /1000) %10;

  CS1694::dispNum(units,0); //display 0-9
if(tens >= 1 || inputVar >=100){
   CS1694::dispNum(tens,1);}else{   CS1694::dispNum(36,1);} //if further digits are zero, blank leading zeros unless the input value is more than place the zero is in 
if(hunds >=1 || inputVar >=1000){
   CS1694::dispNum(hunds,2);}else{   CS1694::dispNum(36,2);}  
if(thous >= 1 ){
    CS1694::dispNum(thous,3);}else{   CS1694::dispNum(36,3);}
 

    }

  void    CS1694::dispNum(byte segDataIN, byte dispDigit){ //converts a number 0 - 36 into segment data for the CS1694

byte segmentData = _segData[segDataIN];
    bool aSeg = bitRead(segmentData,0);
    bool bSeg = bitRead(segmentData,1);
    bool cSeg = bitRead(segmentData,2);
    bool dSeg = bitRead(segmentData,3);
    bool eSeg = bitRead(segmentData,4);;
    bool fSeg = bitRead(segmentData,5);
    bool gSeg = bitRead(segmentData,6);
    
    /*bool lamp1 = bitRead(segDataIN,0);
    bool lamp2 = bitRead(segDataIN,1);
    bool lamp3 = bitRead(segDataIN,2);
    bool lamp4 = bitRead(segDataIN,3);
    bool lamp5 = bitRead(segDataIN,4);
    bool lamp6 = bitRead(segDataIN,5);*/
    //bool lamp7 = bitRead(segDataIN,6);
    switch(dispDigit){
      case 0: //digit 1
      bitWrite(displayMem[4],7,aSeg);
      bitWrite(displayMem[5],1,bSeg);
      bitWrite(displayMem[4],4,cSeg);
      bitWrite(displayMem[4],2,dSeg);
      bitWrite(displayMem[4],1,eSeg);
      bitWrite(displayMem[5],0,fSeg);
      bitWrite(displayMem[4],6,gSeg);
      break;

      case 1: //digit 2
      bitWrite(displayMem[6],7,aSeg);
      bitWrite(displayMem[7],1,bSeg);
      bitWrite(displayMem[6],4,cSeg);
      bitWrite(displayMem[6],2,dSeg);
      bitWrite(displayMem[6],1,eSeg);
      bitWrite(displayMem[7],0,fSeg);
      bitWrite(displayMem[6],6,gSeg);
      break;
      case 2: //digit 3
      bitWrite(displayMem[10],7,aSeg);
      bitWrite(displayMem[11],1,bSeg);
      bitWrite(displayMem[10],4,cSeg);
      bitWrite(displayMem[10],2,dSeg);
      bitWrite(displayMem[10],1,eSeg);
      bitWrite(displayMem[11],0,fSeg);
      bitWrite(displayMem[10],6,gSeg);
      break;
      
    
    case 3: //digit 4
      bitWrite(displayMem[8],7,aSeg);
      bitWrite(displayMem[9],1,bSeg);
      bitWrite(displayMem[8],4,cSeg);
      bitWrite(displayMem[8],2,dSeg);
      bitWrite(displayMem[8],1,eSeg);
      bitWrite(displayMem[9],0,fSeg);
      bitWrite(displayMem[8],6,gSeg);
      break;
    /*case 4: //digit 5
      bitWrite(displayMem[1],0,aSeg);
      bitWrite(displayMem[3],0,bSeg);
      bitWrite(displayMem[5],0,cSeg);
      bitWrite(displayMem[7],0,dSeg);
      bitWrite(displayMem[9],0,eSeg);
      bitWrite(displayMem[11],0,fSeg);
      bitWrite(displayMem[13],0,gSeg);
      break;

      case 5: //digit 6
      bitWrite(displayMem[1],1,aSeg);
      bitWrite(displayMem[3],1,bSeg);
      bitWrite(displayMem[5],1,cSeg);
      bitWrite(displayMem[7],1,dSeg);
      bitWrite(displayMem[9],1,eSeg);
      bitWrite(displayMem[11],1,fSeg);
      bitWrite(displayMem[13],1,gSeg);
      break;

      case 6: //misc lamps 1
      bitWrite(displayMem[0],5,lamp1); //MP3
      bitWrite(displayMem[2],5,lamp2); //A-B
      bitWrite(displayMem[4],5,lamp3); //colon 2
      bitWrite(displayMem[6],5,lamp4); //ALL
      bitWrite(displayMem[8],5,lamp5); //REP
      bitWrite(displayMem[10],5,lamp6); //colon 1
      //bitWrite(displayMem[12],5,lamp7); // nothing
      break;
    case 7: //misc lamps 2
      bitWrite(displayMem[0],6,lamp1); //TRK
      bitWrite(displayMem[2],6,lamp2); //CD
      bitWrite(displayMem[4],6,lamp3); //|> (play icon)
      bitWrite(displayMem[6],6,lamp4); //|| (pause icon)
      bitWrite(displayMem[8],6,lamp5); //DVD
      bitWrite(displayMem[10],6,lamp6); //VCD
      //bitWrite(displayMem[12],6,lamp7); // nothing
      break;
      */}
    
    
    
    }

void CS1694::LED(bool LEDstate){

bitWrite(displayMem[3],0,LEDstate);




}

void CS1694::colon(bool LEDstate){
bitWrite(displayMem[6],3,LEDstate);
bitWrite(displayMem[10],3,LEDstate);
	
}

void    CS1694::clearDisplay(){ //fills the display with binary 0 (all segments off)
  
  for(byte i = 0; i < 14; i++){  
  byte address = 0xC0 | i; 
   CS1694::sendtoCS1694(address);
   CS1694::sendtoCS1694(0);
digitalWrite(_StrobePin,HIGH);
  //
 



}
}

unsigned long    CS1694::readButtons(){
  
  //sendtoCS1694(0xC0);
     CS1694::sendtoCS1694(0x46); //command to set chip to read key matrix
  digitalWrite(_dataClock,HIGH);
   //digitalWrite(_StrobePin,HIGH);
  delay(1);
   //digitalWrite(Strobe,LOW);
   //digitalWrite(DataClock,LOW);
pinMode(_dataPin,INPUT); //shift in apparently doesnt automatically set the datapin to input, manually had to do it
byte buttonData0 = shiftIn(_dataPin,_dataClock,LSBFIRST);
byte buttonData1 = shiftIn(_dataPin,_dataClock,LSBFIRST);
byte buttonData2 = shiftIn(_dataPin,_dataClock,LSBFIRST);
byte buttonData3 = shiftIn(_dataPin,_dataClock,LSBFIRST);
  //for some reason the buttons are only read correctly when I pull in 4 bytes worth of data when theoretically it would fit into an unsigned int
  unsigned long buttonData = buttonData3 << 8; //dump all the reads into an unsigned long (32bit)
  buttonData |= buttonData2;
  buttonData << 16;
  buttonData |= buttonData1 <<8;
  buttonData |= buttonData0;
  digitalWrite(_StrobePin,HIGH);
  pinMode(_dataPin,OUTPUT); 
  byte  outputButtonData = 0; //compress the button data into 8 bits for (up to 8) digital bool values formatted into something vaugely sane
        if(buttonData == 2048){bitSet(outputButtonData,0);}else{bitClear(outputButtonData,0);}
  if(buttonData == 256){bitSet(outputButtonData,2);}else{bitClear(outputButtonData,2);}
  if(buttonData == 1){bitSet(outputButtonData,1);}else{bitClear(outputButtonData,1);}
  //return outputButtonData;
  return buttonData;
  }
void    CS1694::setBrightness (byte brightLevel){
  if(brightLevel > 7){brightLevel = 7;}//cap brightness to 7 if invalid or higher value is used
  byte brightnesslevel = 0x88 | brightLevel; //command to set the pulse width (brightness) of the CS1694
        CS1694::sendtoCS1694(brightnesslevel);
      digitalWrite(_StrobePin,HIGH);  
      }

void    CS1694::displaySetup(bool mode){ //mode: 1=7 grids of 10 segments, 0=6grids of 11 segs
        if(mode){
           CS1694::sendtoCS1694(0x03);
        }else{CS1694::sendtoCS1694(0x02);}
           digitalWrite(_StrobePin,HIGH);
        CS1694::sendtoCS1694(0x44); //set to write memory mode
     
        digitalWrite(_StrobePin,HIGH);
        }
