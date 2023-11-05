#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <Espalexa.h>

const char* ssid = "";
const char* password = "";

Espalexa espalexa;

byte mode = 0;


void alexaAction(uint8_t brightness)
{
  //Control the device
  
  Serial.print("brightness : "); Serial.println(brightness);

    if(brightness >= 230){
      
      strip.setBrightness(map(brightness, 230, 255, 50, 255));
      
      updateMemBright(byte(map(brightness, 230, 255, 50, 255)));
    }
      
    else{
      
      mode = brightness;
      
      updateMemMode(byte(brightness));
    }
}




boolean connectWifi()
{
  boolean state = true;
  int i = 0;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 20) {
      state = false; break;
    }
    i++;
  }
  Serial.println("");
  if (state) {
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("Connection failed.");
  }
  return state;
}
