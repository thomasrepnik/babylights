// Simple strand test for Adafruit Dot Star RGB LED strip.
// This is a basic diagnostic tool, NOT a graphics demo...helps confirm
// correct wiring and tests each pixel's ability to display red, green
// and blue and to forward data down the line.  By limiting the number
// and color of LEDs, it's reasonably safe to power a couple meters off
// the Arduino's 5V pin.  DON'T try that with other code!

#include "FastLED.h"

#define SHOW_LENGTH_MILLIS 15000

// Here's how to control the LEDs from any two pins:
#define DATA_PIN_LEFT     2
#define CLOCK_PIN_LEFT    3
#define DATA_PIN_TOP      4
#define CLOCK_PIN_TOP     5
#define DATA_PIN_RIGHT    6
#define CLOCK_PIN_RIGHT   7
#define DATA_PIN_BOTTOM   8
#define CLOCK_PIN_BOTTOM  9

#define LEDS_LEFT_SIZE  20
#define LEDS_RIGHT_SIZE  21
#define LEDS_TOP_SIZE  46
#define LEDS_BOTTOM_SIZE  46
#define LEDS_ALL_SIZE  LEDS_LEFT_SIZE + LEDS_RIGHT_SIZE + LEDS_TOP_SIZE + LEDS_BOTTOM_SIZE


const int leds_left_size = LEDS_LEFT_SIZE;
const int leds_right_size = LEDS_RIGHT_SIZE;
const int leds_top_size = LEDS_TOP_SIZE;
const int leds_bottom_size = LEDS_BOTTOM_SIZE;
const int total_size = LEDS_ALL_SIZE;

unsigned long currentMillis;

CRGB leds_all[LEDS_ALL_SIZE];

CRGB* leds_left  =  leds_all + 0;
CRGB* leds_top    = leds_all + LEDS_LEFT_SIZE;
CRGB* leds_right  = leds_all + LEDS_LEFT_SIZE + LEDS_TOP_SIZE;
CRGB* leds_bottom  = leds_all + LEDS_LEFT_SIZE + LEDS_TOP_SIZE + LEDS_RIGHT_SIZE;

CRGB *leds_all_ordered[LEDS_ALL_SIZE];

int counter = 0;

void setup() {
	delay(2000);

	Serial.begin(9600);

	FastLED.setBrightness(50);
	FastLED.setMaxPowerInVoltsAndMilliamps(5, 2000);

	FastLED.addLeds<APA102, DATA_PIN_LEFT, CLOCK_PIN_LEFT, BGR>(leds_left, LEDS_LEFT_SIZE);
	FastLED.addLeds<APA102, DATA_PIN_TOP, CLOCK_PIN_TOP, BGR>(leds_top, LEDS_TOP_SIZE);
	FastLED.addLeds<APA102, DATA_PIN_RIGHT, CLOCK_PIN_RIGHT, BGR>(leds_right, LEDS_RIGHT_SIZE);
	FastLED.addLeds<APA102, DATA_PIN_BOTTOM, CLOCK_PIN_BOTTOM, BGR>(leds_bottom, LEDS_BOTTOM_SIZE);

	for (int i = 0; i < LEDS_ALL_SIZE; i++) {
	  if (i < LEDS_LEFT_SIZE){
		  leds_all_ordered[i] = &leds_all[LEDS_LEFT_SIZE - i - 1];
		  printFmt("%d --> %d",i, LEDS_LEFT_SIZE - i - 1);
	  }else if (i >= LEDS_LEFT_SIZE + LEDS_TOP_SIZE && i < LEDS_LEFT_SIZE + LEDS_TOP_SIZE + LEDS_RIGHT_SIZE){
		  leds_all_ordered[i] = &leds_all[LEDS_LEFT_SIZE + LEDS_TOP_SIZE + LEDS_RIGHT_SIZE - i - 1 + LEDS_LEFT_SIZE + LEDS_TOP_SIZE];
		  printFmt("%d --> %d",i, LEDS_LEFT_SIZE + LEDS_TOP_SIZE + LEDS_RIGHT_SIZE - i - 1 + LEDS_LEFT_SIZE + LEDS_TOP_SIZE);
	  }else{
		  leds_all_ordered[i] = &leds_all[i]; /* assign the address of integer. */
		  printFmt("%d --> %d",i, i);
	  }
	}


}

void loop() {

	brightStrips(SHOW_LENGTH_MILLIS);

	twinkle(SHOW_LENGTH_MILLIS);

	rainbow(SHOW_LENGTH_MILLIS);

	walkWorms(SHOW_LENGTH_MILLIS);

	fadeColor(SHOW_LENGTH_MILLIS);

	singleDots(SHOW_LENGTH_MILLIS);

	//Serial.println(LEDS.getFPS());
	//singleDots();
}

void showfps(){
	currentMillis = millis();

}
