#include <EEPROM.h>


byte getMemMode();
byte getMemBright();



void updateMemMode(byte m){

  EEPROM.put(0, m);

//  byte a;
//  EEPROM.get(0, a);
//  Serial.print("mode wrote "); Serial.println(a);

  Serial.println(getMemMode());
}

byte getMemMode(){

  byte readM = 0;
  
  EEPROM.get(0, readM);
  
  Serial.print("mode in memory "); Serial.println(readM);
  
  return readM;
}



void updateMemBright(byte br){

  EEPROM.put(1, br);

  byte a;
  EEPROM.get(1, a);
  Serial.print("br wrote "); Serial.println(a);
}

byte getMemBright(){

  byte readBr = 0;
  
  EEPROM.get(1, readBr);
  
  Serial.print("br got "); Serial.println(readBr);

  return readBr;
}
