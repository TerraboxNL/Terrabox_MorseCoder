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

#ifndef MORSECODER_H_
#define MORSECODER_H_

#define TRACE              0    // if 1, print just general trace information
#define TRACE_MORSE        1    // if 1, print out the morse code generated
#define TRACE_ASCII        1    // if 1, print out the ASCII characters send as morse code

#define MEDIA_LED         'l'   // Use the LED for showing morse coding
#define MEDIA_AUDIO       'a'   // Use audio to express the morse coding

#define MEDIA       MEDIA_LED

#define PITCH       680         // Morse tone frequency

#define DOT         150         // Duration of a dot
#define DASH        (3*DOT)     // Duration of a dash

#define BIT_PAUSE   (DOT)       // Duration between 2 morse DOTS, DASHES or DOT DASH
#define CHAR_PAUSE  (3*DOT)     // Duration between 2 morse characters
#define WORD_PAUSE  (7*DOT)     // Duration between 2 words in morse

#define STOP   0                // Stop code for duration sequences

#define CAST_MORSE_SEQUENCE  (int*)(const int[])   //  Needed casting for duration sequences

//
//  Duration sequences for specific characters
//
#define _A_    CAST_MORSE_SEQUENCE{ DOT, DASH, STOP }
#define _B_    CAST_MORSE_SEQUENCE{ DASH, DOT, DOT, DOT, STOP }
#define _C_    CAST_MORSE_SEQUENCE{ DASH, DOT, DASH, DOT, STOP }
#define _D_    CAST_MORSE_SEQUENCE{ DASH, DOT, DOT, STOP }
#define _E_    CAST_MORSE_SEQUENCE{ DOT, STOP }
#define _F_    CAST_MORSE_SEQUENCE{ DOT, DOT, DASH, DOT, STOP }
#define _G_    CAST_MORSE_SEQUENCE{ DASH, DASH, DOT, STOP }
#define _H_    CAST_MORSE_SEQUENCE{ DOT, DOT, DOT, DOT, STOP }
#define _I_    CAST_MORSE_SEQUENCE{ DOT, DOT, STOP }
#define _J_    CAST_MORSE_SEQUENCE{ DOT, DASH, DASH, DASH, STOP }
#define _K_    CAST_MORSE_SEQUENCE{ DASH, DOT, DASH, STOP }
#define _L_    CAST_MORSE_SEQUENCE{ DOT, DASH, DOT, DOT, STOP }
#define _M_    CAST_MORSE_SEQUENCE{ DASH, DASH, STOP }
#define _N_    CAST_MORSE_SEQUENCE{ DASH, DOT, STOP }
#define _O_    CAST_MORSE_SEQUENCE{ DASH, DASH, DASH, STOP }
#define _P_    CAST_MORSE_SEQUENCE{ DOT, DASH, DASH, DOT, STOP }
#define _Q_    CAST_MORSE_SEQUENCE{ DASH, DASH, DOT, DASH, STOP }
#define _R_    CAST_MORSE_SEQUENCE{ DOT, DASH, DOT, STOP }
#define _S_    CAST_MORSE_SEQUENCE{ DOT, DOT, DOT, STOP }
#define _T_    CAST_MORSE_SEQUENCE{ DASH, STOP }
#define _U_    CAST_MORSE_SEQUENCE{ DOT, DOT, DASH, DOT, STOP }
#define _V_    CAST_MORSE_SEQUENCE{ DOT, DOT, DOT, DASH, STOP }
#define _W_    CAST_MORSE_SEQUENCE{ DOT, DASH, DASH, STOP }
#define _X_    CAST_MORSE_SEQUENCE{ DOT, DOT, DASH, DASH, STOP }
#define _Y_    CAST_MORSE_SEQUENCE{ DASH, DOT, DASH, DASH, STOP }
#define _Z_    CAST_MORSE_SEQUENCE{ DASH, DASH, DOT, DOT, STOP }

#define _0_    CAST_MORSE_SEQUENCE{ DASH, DASH, DASH, DASH, DASH, STOP }
#define _1_    CAST_MORSE_SEQUENCE{ DOT, DASH, DASH, DASH, DASH, STOP }
#define _2_    CAST_MORSE_SEQUENCE{ DOT, DOT, DASH, DASH, DASH, STOP }
#define _3_    CAST_MORSE_SEQUENCE{ DOT, DOT, DOT, DASH, DASH, STOP }
#define _4_    CAST_MORSE_SEQUENCE{ DOT, DOT, DOT, DOT, DASH, STOP }
#define _5_    CAST_MORSE_SEQUENCE{ DOT, DOT, DOT, DOT, DOT, STOP }
#define _6_    CAST_MORSE_SEQUENCE{ DASH, DOT, DOT, DOT, DOT, STOP }
#define _7_    CAST_MORSE_SEQUENCE{ DASH, DASH, DOT, DOT, DOT, STOP }
#define _8_    CAST_MORSE_SEQUENCE{ DASH, DASH, DASH, DOT, DOT, STOP }
#define _9_    CAST_MORSE_SEQUENCE{ DASH, DASH, DASH, DASH, DOT, STOP }

#define _DOT_    CAST_MORSE_SEQUENCE{ DOT, DASH, DOT, DASH, DOT, DASH, STOP }
#define _COMMA_  CAST_MORSE_SEQUENCE{ DASH, DASH, DOT, DOT, DASH, DASH, STOP }
#define _QM_     CAST_MORSE_SEQUENCE{ DOT, DOT, DASH, DASH, DOT, DOT, STOP }
#define _EM_     CAST_MORSE_SEQUENCE{ DASH, DOT, DASH, DOT, DASH, DASH, STOP }
#define _MIN_    CAST_MORSE_SEQUENCE{ DASH, DOT, DOT, DOT, DOT, DASH, STOP }
#define _MUL_    CAST_MORSE_SEQUENCE{ DASH, DOT, DOT, DASH, STOP }
#define _DIV_    CAST_MORSE_SEQUENCE{ DASH, DOT, DOT, DOT, DASH, DOT, STOP }
#define _COLON_  CAST_MORSE_SEQUENCE{ DASH, DASH, DASH, DOT, DOT, DOT, STOP }
#define _APO_    CAST_MORSE_SEQUENCE{ DOT, DASH, DASH, DASH, DASH, DOT, STOP }
#define _PC_     CAST_MORSE_SEQUENCE{ DASH, DOT, DASH, DASH, DOT, DASH, STOP }
#define _SEMI_   CAST_MORSE_SEQUENCE{ DASH, DOT, DASH, DOT, DASH, STOP }
#define _PO_     CAST_MORSE_SEQUENCE{ DASH, DOT, DASH, DASH, DOT, STOP }
#define _EQ_     CAST_MORSE_SEQUENCE{ DASH, DOT, DOT, DOT, DASH, STOP }
#define _AT_     CAST_MORSE_SEQUENCE{ DOT, DASH, DASH, DOT, DASH, DOT, STOP }
#define _AMP_    CAST_MORSE_SEQUENCE{ DOT, DASH, DOT, DOT, DOT, STOP }

class MorseCoder {
  private:
    char     mediaType         = MEDIA_LED;       // The media type
    int      audioPin          = -1;              // The audio pin
    int      ledPin            = LED_BUILTIN;     // The led pin

    uint32_t lastMorse         = 0; // Remember when the last morse message end time

/**-----------------------------------------------------------------------
 *
 *  Translate a character into morse code
 *
 *  @param c  The character to be translated
 *
 *-----------------------------------------------------------------------*/
  void morse(char c) {
    #if TRACE_ASCII
      Serial.print("'");Serial.print(c); Serial.print("' ");
    #endif

    switch (c) {
      case ' ':
      #if TRACE_MORSE
         Serial.print(" / ");
      #endif
         delay(WORD_PAUSE);
         break;
      case 'A':
      case 'a':
        morse(_A_);
        break;
      case 'B':
      case 'b':
        morse(_B_);
        break;
      case 'C':
      case 'c':
        morse(_C_);
        break;
      case 'D':
      case 'd':
        morse(_D_);
        break;
      case 'E':
      case 'e':
        morse(_E_);
        break;
      case 'F':
      case 'f':
        morse(_F_);
        break;
      case 'G':
      case 'g':
        morse(_G_);
        break;
      case 'H':
      case 'h':
        morse(_H_);
        break;
      case 'I':
      case 'i':
        morse(_I_);
        break;
      case 'J':
      case 'j':
        morse(_J_);
        break;
      case 'K':
      case 'k':
        morse(_K_);
        break;
      case 'L':
      case 'l':
        morse(_L_);
        break;
      case 'M':
      case 'm':
        morse(_M_);
        break;
      case 'N':
      case 'n':
        morse(_N_);
        break;
      case 'O':
      case 'o':
        morse(_O_);
        break;
      case 'P':
      case 'p':
        morse(_P_);
        break;
     case 'Q':
      case 'q':
        morse(_Q_);
        break;
      case 'R':
      case 'r':
        morse(_R_);
        break;
      case 'S':
      case 's':
        morse(_S_);
        break;
      case 'T':
      case 't':
        morse(_T_);
        break;
      case 'U':
      case 'u':
        morse(_U_);
        break;
      case 'V':
      case 'v':
        morse(_V_);
        break;
      case 'W':
      case 'w':
        morse(_W_);
        break;
      case 'X':
      case 'x':
        morse(_X_);
        break;
      case 'Y':
      case 'y':
        morse(_Y_);
        break;
      case 'Z':
      case 'z':
        morse(_Z_);
        break;

      case '0':
        morse(_0_);
        break;
      case '1':
        morse(_1_);
        break;
      case '2':
        morse(_2_);
        break;
      case '3':
        morse(_3_);
        break;
      case '4':
        morse(_4_);
        break;
      case '5':
        morse(_5_);
        break;
      case '6':
        morse(_6_);
        break;
      case '7':
        morse(_7_);
        break;
      case '8':
        morse(_8_);
        break;
      case '9':
        morse(_9_);
        break;

      case '.':
        morse(_DOT_);
        break;
      case ',':
        morse(_COMMA_);
        break;
      case '?':
        morse(_QM_);
        break;
      case '!':
        morse(_EM_);
        break;
      case '-':
        morse(_MIN_);
        break;
      case '*':
        morse(_MUL_);
        break;
      case '/':
        morse(_DIV_);
        break;
      case ':':
        morse(_COLON_);
        break;
      case '\'':
        morse(_APO_);
        break;
      case ')':
        morse(_PC_);
        break;
      case ';':
        morse(_SEMI_);
        break;
      case '(':
        morse(_PO_);
        break;
      case '=':
        morse(_EQ_);
        break;
      case '@':
        morse(_AT_); 
        break;
      case '&':
        morse(_AMP_);
        break;

      default:
        Serial.println("Unsupported morse character: "); Serial.println(c);
    }
  }

/**------------------------------------------------------------------------
 *
 *  Punch out a single character in morse
 *
 *  @param mCode   A sequence of durations in ms, during which a tone musr be heard or a led must be o.
 *
 *-----------------------------------------------------------------------*/ 
  void morse(int* mCode) {

    switch (mediaType) {
        case MEDIA_LED:
          morseLed(mCode);
          break;
        case MEDIA_AUDIO:
          morseAudio(mCode);
          break;
        default:
          Serial.println("Illegal media type was assigned, use #define MEDIA   MEDIA_AUDIO or MEDIA_LED");
    }

    #if TRACE_MORSE
      Serial.print(" ");
    #endif
    delay(CHAR_PAUSE);
  }

/**-------------------------------------------------------------------------
 *
 *  Light a LED for a specific time, followed by a dark period
 *
 *  @param t   The timimg sequence representing the morse code
 *
 *-----------------------------------------------------------------------*/ 
  void morseLed(int* t) {
    if (ledPin < 0)
      return;

    int i = 0;
    while (t[i]) {
      #if TRACE_MORSE
        switch(t[i]) {
          case DOT:
            Serial.print(".");
            break;
          case DASH:
            Serial.print("-");
        }
      #endif
      digitalWrite(ledPin, HIGH);   // turn the LED ON
      delay((uint32_t)t[i]);                          // wait for the duration of a dot or a dash
      digitalWrite(ledPin, LOW);    // turn the LED off
      delay(BIT_PAUSE);                  // wait for a fixed darkened period  
      i++;                               // On to the next dot or dash
    }
  }

/**------------------------------------------------------------------------
 *
 *  Generate an audible morse sequence for a specific character
 *
 *  @param t   The morse time sequence
 *
 *-----------------------------------------------------------------------*/
  void morseAudio(int* t) {
    if (audioPin < 0)
      return;

    int i = 0;
    while (t[i]) {
      #if TRACE_MORSE
        switch(t[i]) {
          case DOT:
            Serial.print(".");
            break;
          case DASH:
            Serial.print("-");
        }
      #endif
      tone(audioPin, PITCH, (uint32_t)t[i]);            // Generate a tone for a dot or dash
      delay(BIT_PAUSE);                  // wait for a fixed silent period  
      i++;                               // On to the next dot or dash
    }

    #if TRACE_MORSE
      Serial.print(" ");
    #endif
  }

  /**-----------------------------------------------------
   *
   *  Generate a tone
   *
   *  @param pin       Pin to generte the tone on
   *  @param herz      The pitch expressed in herz
   *  @param duration  The duration of the tone
   *
   *----------------------------------------------------*/
  void tone(int pin, float herz, uint32_t duration) {
    uint32_t halfCycle = 500/herz;
    uint32_t fullCycle = 1000/herz;
    uint32_t start = duration + fullCycle;
    while ((start -= fullCycle) > 0) {
      digitalWrite(pin, HIGH);
      delay(halfCycle);
      digitalWrite(pin, LOW);
      delay(halfCycle);
    }
  }

  public:
     MorseCoder() {

     }

/**----------------------------------------------------------------
 *
 *  Initialize a default morse coder object using media type LED and the built in LED.
 *
 *----------------------------------------------------------------*/
  void begin() {
    mediaType = MEDIA_LED;
    ledPin    = LED_BUILTIN;
    audioPin  = -1;
  }

  /**----------------------------------------------------------------
   *
   *  Initialize the morse coder object with the needed io pins.
   *  
   *  @param  media  The media, eithe MEDIA_LED or MEDIA_AUDIO
   *  @param  pin    The output pin to use
   *
   *----------------------------------------------------------------*/
  void begin(int media, uint pin) {
    mediaType = media;

    switch (mediaType) {
      case MEDIA_LED:
        ledPin = pin;
        break;
      case MEDIA_AUDIO:
        audioPin = pin;
        break;
    }
    pinMode(pin, OUTPUT);
  }

  /**------------------------------------------------------------------------
   *
   *  Punch out a message in morse code.
   *
   *  @param s   The string containing the message
   *
   *------------------------------------------------------------------------*/
  void morse(char * s) {
    //
    //  If the time between 2 message is shorter than a word pause,
    //  then introduce a delay up to the WORD_PAUSE.
    //
    uint32_t ago = millis() - lastMorse;
    if (ago < WORD_PAUSE) {
      #if TRACE
        Serial.println("Fix word pause between messages...");
      #endif
      delay (WORD_PAUSE - ago);
    }

    //
    //  Send the new morse message
    //
    int i = 0;
    while (s[i]) {
      morse(s[i]);
      i++;
    }

    //
    //  Remember the end time of the morse message
    //
    lastMorse = millis();

    #if TRACE || TRACE_MORSE || TRACE_ASCII
      Serial.println();
    #endif
  }
};

#endif