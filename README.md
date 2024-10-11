/*-------------------------------------------------------------------------------------------------


       /////// ////// //////  //////   /////     /////    ////  //    //
         //   //     //   // //   // //   //    //  //  //   // // //
        //   ////   //////  //////  ///////    /////   //   //   //
       //   //     //  //  // //   //   //    //   // //   //  // //
      //   ////// //   // //   // //   //    //////    ////  //   //

     
                     A R D U I N O  M O R S E  C O D E R


                 (C) 2024, C. Hofman - cor.hofman@terrabox.nl

               <Morse Coder> - Library for morse code generation.
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

Releases
========
1.0.0-Production
The first release of a morse coding class called MorseCoder.


Abstract
========
Instantiate a MorseCoder object, call its begin() method after which you can start coding your morse messages using the morse(char * m) function.

Functions
=========
You have a choice whether you want to see the morse code on the onboard LED. Which is the default if you invoke begin().
If you invoke a parametrised version of begin, then you can get he morse signal on a digital output. On pin 0 in the example below. 

``` C++
begin(MEDIA_AUDIO, 0);
```

By default the TRACE_MORSE and TRACE_ASCIII defines are set to 1 in MorseCoder.h
This results in the serial output shown in the monitor. An example print out is shown under here in the Examples section.

Further you will find the code line below in the MorseCoder.h file. This specifies the length of a morse code dot having a duration of 150 milliseconds. Since all other timing aspects are expressed in an integer number of dots durations, specifying DOT will make the morse code appear quicker or slower.
Typically a dash has a duration of three dots. The pause between dots and dashes is a silence of a single dot duration. The silence between two morse coded characters is that of a dash. Between words there is a silence of seven dots.
``` C++
#define DOT  150
```

Limmitations
============
The characters that can be expressed in morse are limited compared to modern computers. Typically morse code support single letters, digits and a set of the punctuation characters (.,?!-*/:';=@&).
The parentheses open and close are also included.

There are some extra codings which stand for END OF WORK, ERROR, General invitation to transmit, Starting Signal, New messages follow, Verified, Wait and some special non-Latin characters. All of which are not supported by MorseCoder. But they are easily added by modifying the code in the MorseCoder.h 

Extending the morse code
========================
Juts add a new #define for a DOT/DASH sequence of your choice, terminated by STOP.
Adding that sequence to the switch() statement in the  as a specific case in the void morse(char c) function.

``` C++

//
//  Add your own morse codes, e.g.
//
//     #define _NEW_   CAST_MORSE_SEQUENCE{ /* Your comma separated DOT, DASH sequence */, STOP }
//
#define _MY_CHAR_0x80_ CAST_MORSE_SEQUENCE{ DOT, DOT, DASH, DASH, DOT, DASH, DASH, DOT, DOT, STOP }

:
:
void morse(char c) {
:
:
//
//   Adding the case for your new morse coding
// 
     case /* your character */ 0x80:
       morse(_MY_CHAR_0x80_);
       break;
:
:
```
And that's it.

Examples
========

Below the typical "Hello world" example

``` C++
#include <MorseCoder.h>

MorseCoder morse;

void setup() {
  //
  //  Initialize the serial line
  //
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
  //  Delay a bit before the next cycle starts
  //
  delay(1000);
}


```

Example output with both TRACE_ASCII and TRACE_MORSE set to 1.
```  txt
18:25:49.488 -> 'H' .... 'e' . 'l' .-.. 'l' .-.. 'o' --- ' '  / 'w' .-- 'o' --- 'r' .-. 'l' .-.. 'd' -.. '!' -.-.-- 
18:25:50.488 -> 'H' .... 'e' . 'l' .-.. 'l' .-.. 'o' --- ' '  / 'w' .-- 'o' --- 'r' .-. 'l' .-.. 'd' -.. '!' -.-.-- 
18:25:51.488 -> 'H' .... 'e' . 'l' .-.. 'l' .-.. 'o' --- ' '  / 'w' .-- 'o' --- 'r' .-. 'l' .-.. 'd' -.. '!' -.-.-- 
etc...
```

Setting TRACE_MORSE to 0 and leaving TRACE_ASCII at 1 will generate the printout below.
```  txt
18:25:49.488 -> 'H' 'e' 'l' 'l' 'o' ' ' 'w' 'o' 'r' 'l' 'd' '!' 
18:25:50.488 -> 'H' 'e' 'l' 'l' 'o' ' ' 'w' 'o' 'r' 'l' 'd' '!' 
18:25:51.488 -> 'H' 'e' 'l' 'l' 'o' ' ' 'w' 'o' 'r' 'l' 'd' '!' 
etc...
```

Setting TRACE_ASCII to 0 and leaving TRACE_MORSE at 1 will show this.
Note that the dots and dashes appear in synchronisation with the visual or audible expression of the morse code.
```  txt
18:25:49.488 -> .... . .-.. .-.. --- / .-- --- .-. .-.. -.. -.-.-- 
18:25:50.488 -> .... . .-.. .-.. --- / .-- --- .-. .-.. -.. -.-.-- 
18:25:50.488 -> .... . .-.. .-.. --- / .-- --- .-. .-.. -.. -.-.-- 
etc...
```
