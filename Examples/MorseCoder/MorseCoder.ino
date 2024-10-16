/*-------------------------------------------------------------------------------------------------


       /////// ////// //////  //////   /////     /////    ////  //    //
         //   //     //   // //   // //   //    //  //  //   // // //
        //   ////   //////  //////  ///////    /////   //   //   //
       //   //     //  //  // //   //   //    //   // //   //  // //
      //   ////// //   // //   // //   //    //////    ////  //   //

     
                     A R D U I N O  M O R S E  C O D E R


                 (C) 2024, C. Hofman - cor.hofman@terrabox.nl

               <Morse Coder> - Arduino morse code generator.
                                 11 Oct 2024
                       Released into the public domain
              as GitHub project: TerraboxNL/TerraBox_MorseCoder
                   under the GNU General public license V3.0
                          
      This program is free software: you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
      the Free Software Foundation, either version 3 of the License, or
      (at your option) any later version.

      This program is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      GNU General Public License for more details.

      You should have received a copy of the GNU General Public License
      along with this program.  If not, see <https://www.gnu.org/licenses/>.

 *---------------------------------------------------------------------------*
 *
 *  C H A N G E  L O G :
 *  ==========================================================================
 *  P0001 - Initial release 
 *  ==========================================================================
 *
 *--------------------------------------------------------------------------*/

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
 
#ifdef ARDUINO_ARCH_RP2040
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
#endif

  //
  //  Delay a bit before the next cycle starts
  //
  delay(1000);
}

