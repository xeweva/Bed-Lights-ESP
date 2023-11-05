
/**
 * int[0] - counter
 * 
 * 
 * params[0] - color 1 hue
 * params[1] - hue gap
 * params[2] - fire step
 * params[3] - minSat
 */


byte huetacolors[TOTAL_LED_NUM];

void huetaRED(){

  for(int i = 0; i < TOTAL_LED_NUM; i++){

    huetacolors[i] = constrain((huetacolors[i] + random(0, 20) - 10), 10, 255);
    
    strip.setPixelColor(i, huetacolors[i], 0, 0);
  } 
}



long getFireColor(unsigned int hueStart, unsigned int hueGap, byte minSat, int val);


 int perlinCounter = 0;

 
void perlin(unsigned int hueStart, unsigned int hueGap, byte fireStep, byte minSat){

  for(int i = 0; i < TOTAL_LED_NUM; i++)
    strip.setPixelColor(i, getFireColor(hueStart, hueGap, minSat, (inoise8(i * fireStep, perlinCounter))));

  perlinCounter += 5;  
}


long getFireColor(unsigned int hueStart, unsigned int hueGap, byte minSat, int val) {


  return strip.ColorHSV(
             ((long) hueStart + (long) map(val, 0, 255, 0, hueGap)) % 65535,                       //H  
             constrain(map(val, 0, 255, minSat, 255), 0, 255),             //S
             constrain(map(val, 0, 255, 10, MAX_BRIGHTNESS), 0, 255)       //V   
           );
}
