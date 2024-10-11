#include <MorseCoder.h>

MorseCoder morse;

float tempC;
float tempCCorrection = -2.7;

void setup() {
  Serial.begin(115200);
  while (!Serial) ;

  //
  //  Initialize the morse coder
  //
  morse.begin(MEDIA_LED, LED_BUILTIN);

}

void loop() {

  //
  //  The first thing to try :)
  //
  morse.morse((char *) "Hello world!");
 
  //
  //  Send out The famous SOS message
  //
   morse.morse((char *) "SOS");
 
  //
  //  Read internal RP-pico chip temperature
  //
  tempC = analogReadTemp() + tempCCorrection; // Get internal temperature
  Serial.print(tempC); Serial.println(" ºC");

  //
  //  Send it into the world using morse code
  //
  char buf[32];
  sprintf(buf, "%.2f C", tempC);
  morse.morse(buf);

  //
  //  Delay a bit before the next cycle starts
  //
  delay(1000);
}

