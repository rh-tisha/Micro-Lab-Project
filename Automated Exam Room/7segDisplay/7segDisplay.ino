#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment object

//long startnumber = 500 ;

void setup() {
  byte numDigits = 5;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = true; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected. Then, you only need to specify 7 segmentPins[]

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
}
void loop() 
{
//  if (startnumber > 0) {
//    for (long i=0; i<=0; i++){
//       sevseg.setNumber(startnumber);
//       sevseg.refreshDisplay();
//      }   
//      startnumber = startnumber --;
//    }
 
   
  sevseg.setNumber(500);
//   sevseg.setChars("abc");
  sevseg.refreshDisplay();
  }
