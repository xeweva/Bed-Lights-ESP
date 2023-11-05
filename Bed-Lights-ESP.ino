#include "Adafruit_NeoPixel.h"
#include "FastLED.h"


#define LED_PIN 4

#define SIDE_LED_NUM 75
#define TOP_LED_NUM 232
#define TOTAL_LED_NUM 382

#define MAX_BRIGHTNESS 255


Adafruit_NeoPixel strip(TOTAL_LED_NUM, LED_PIN, NEO_GRB + NEO_KHZ800);


#include "Memory.h"
#include "WifiCommunication.h"
#include "Modes.h"

void(* resetFunc) (void) = 0;
boolean connectWifi();


// WiFi Credentials
String Device_Name = "Bed Lights";


void alexaAction(uint8_t brightness);
boolean connectWifi();




void setup() {

    Serial.begin(9600);

    strip.begin();
    strip.setBrightness(255);//getMemBright());
    strip.clear();
    strip.show();

    mode = 20;//getMemMode();
    
    
  if (connectWifi()){
    
    espalexa.addDevice(Device_Name, alexaAction); //simplest definition, default state off
    espalexa.begin();
  }
  else{
    
    Serial.println("Cannot connect to WiFi.");
    delay(1000);

    resetFunc();
  }

  EEPROM.begin(4);

}

void loop() {

  espalexa.loop();
  
  delay(1);

  setBedLights();
}



void setBedLights(){    

  switch(mode){

    
    case 5:
    
      for(int i = 0; i < TOTAL_LED_NUM; i++){
        strip.setPixelColor(i, 255, 0, 0);
      }

    break;


    case 7:

      for(int i = 0; i < TOTAL_LED_NUM; i++){
        strip.setPixelColor(i, 0, 255, 0);
      }

    break;


    case 10:

      for(int i = 0; i < TOTAL_LED_NUM; i++){
        strip.setPixelColor(i, 0, 0, 255);
      }

    break;


    case 12:

      for(int i = 0; i < TOTAL_LED_NUM; i++){
        strip.setPixelColor(i, 255, 0, 255);
      }

    break;


    case 15:

      for(int i = 0; i < TOTAL_LED_NUM; i++){
            strip.setPixelColor(i, 0, 255, 255);

      }

    break;

    case 17: //purle

      for(int i = 0; i < TOTAL_LED_NUM; i++){
            strip.setPixelColor(i, 255, 255, 0);

      }

    break;



    
    case 20: //purple fade

      perlin(25000, 35000, 30, 180);
    
    break;



    case 22: //white

      for(int i = 0; i < TOTAL_LED_NUM; i++){
            strip.setPixelColor(i, 255, 255, 255);

      }    
    break;


    case 25: //blue fade
      //41000 5500
      //39000 8000
      perlin(41000, 5500, 30, 180);

    break;
    
      
    default: 


      for(int i = 0; i < TOTAL_LED_NUM; i++){
            strip.setPixelColor(i, 255, 255, 255);

      } 

    break;
  
  }

  strip.show();
  
}



//5 
//7
//10
