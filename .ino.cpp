#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2017-04-25 20:31:57

#include "Arduino.h"
#include "FastLED.h"
#include <stdarg.h>
void setup() ;
void loop() ;
void showfps();
void brightStrips(unsigned int durationMillis) ;
void endAnimation() ;
void exitAnimation();
void fadeColor(unsigned int durationMillis) ;
bool isAnimationTimeExceeded(unsigned long startTime, 		unsigned long durationMillis) ;
void setAllLEDs(CRGB color) ;
void printFmt(char *fmt, ...) ;
void rainbow(unsigned int durationMillis) ;
void fadePixel(CRGB startColor, CRGB endColor, int step) ;
void singleDots(unsigned int durationMillis) ;
void twinkle(unsigned int durationMillis) ;
void confetti() ;
void walkWorms(unsigned int durationMillis) ;
void moveAllToRight() ;


#include "Blink.ino"
#include "BrightStrips.ino"
#include "EndAnimation.ino"
#include "FadeColor.ino"
#include "PrintHelper.ino"
#include "Rainbow.ino"
#include "SingleDots.ino"
#include "Twinkle.ino"
#include "WalkingWorms.ino"

#endif
