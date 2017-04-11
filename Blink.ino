// Simple strand test for Adafruit Dot Star RGB LED strip.
// This is a basic diagnostic tool, NOT a graphics demo...helps confirm
// correct wiring and tests each pixel's ability to display red, green
// and blue and to forward data down the line.  By limiting the number
// and color of LEDs, it's reasonably safe to power a couple meters off
// the Arduino's 5V pin.  DON'T try that with other code!

#include "FastLED.h"

#define NUM_LEDS_SHORT 60 // Number of LEDs in strip
#define NUM_LEDS_LONG 60 // Number of LEDs in strip

// Here's how to control the LEDs from any two pins:
#define DATA_PIN_2    2
#define CLOCK_PIN_2   3
#define DATA_PIN      4
#define CLOCK_PIN     5
#define DATA_PIN_3    6
#define CLOCK_PIN_3   7

#define LEDS_LEFT_SIZE  NUM_LEDS_SHORT
#define LEDS_RIGHT_SIZE  NUM_LEDS_SHORT
#define LEDS_TOP_SIZE  NUM_LEDS_LONG
#define LEDS_BOTTOM_SIZE  NUM_LEDS_LONG

const int leds_left_size = NUM_LEDS_SHORT;
const int leds_right_size = NUM_LEDS_SHORT;
const int leds_top_size = NUM_LEDS_LONG;
const int leds_bottom_size = NUM_LEDS_LONG;

unsigned long currentMillis;

//CRGB leds_left[leds_left_size];
//CRGB leds_right[leds_right_size];
//CRGB leds_top[leds_top_size];
//CRGB leds_bottom[leds_bottom_size];

CRGB leds_all[200];

CRGB* leds_left  =  leds_all + 0;
CRGB* leds_top    = leds_all + 60;
CRGB* leds_right  = leds_all + 120;
CRGB* leds_bottom  = leds_left + 180;

const int total_size = leds_left_size + leds_right_size + leds_top_size;

void setup() {
	delay(2000);

	Serial.begin(9600);

	FastLED.setBrightness(50);
	FastLED.setMaxPowerInVoltsAndMilliamps(5, 2000);

	FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds_left,
	LEDS_RIGHT_SIZE);
	FastLED.addLeds<APA102, DATA_PIN_2, CLOCK_PIN_2, BGR>(leds_right,
	LEDS_LEFT_SIZE);
	FastLED.addLeds<APA102, DATA_PIN_3, CLOCK_PIN_3, BGR>(leds_top,
	LEDS_TOP_SIZE);
	//FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds_bottom, LEDS_BOTTOM_SIZE);

}

void setLED(int number, CRGB color) {
	if (number < leds_left_size) {
		leds_left[number] = color;
	} else if (number >= leds_left_size
			&& number < leds_left_size + leds_top_size) {
		leds_top[number - leds_left_size] = color;
	} else if (number >= leds_left_size + leds_top_size
			&& number < leds_top_size + leds_left_size + leds_right_size) {
		leds_right[number - leds_left_size - leds_top_size] = color;
	} else {
		leds_bottom[number - leds_left_size - leds_top_size - leds_right_size] =
				color;
	}
}

CRGB getLED(int number) {
	if (number < leds_left_size) {
		return leds_left[number];;
	} else if (number >= leds_left_size
			&& number < leds_left_size + leds_top_size) {
		return leds_top[number - leds_left_size];
	} else if (number >= leds_left_size + leds_top_size
			&& number < leds_top_size + leds_left_size + leds_right_size) {
		return leds_right[number - leds_left_size - leds_top_size];
	} else {
		return leds_bottom[number - leds_left_size - leds_top_size
				- leds_right_size];
	}
}

void fadeToBlack2(int numFadingLeds) {

	fill_solid(leds_left, leds_left_size, CRGB(255, 0, 0));
	FastLED.delay(3000);
	int factor = 5;
	int delta = 20;
	int middle = 0;
	int middle_left = 0;
	int middle_right = 0;

	if (leds_left_size % 2 == 0) {
		//Gerade Zahl -> Zwei Zahlen in der Mitte
		middle_left = leds_left_size / 2;
		middle_right = middle_left + 1;

		int tail_right = middle_right;

	    while (tail_right <= leds_left_size - 1){
	    	for (int i = 0; i < numFadingLeds; i++){
				leds_left[tail_right + i].fadeToBlackBy(min(delta * (5 - i), 255));
				FastLED.show();
	    	}

	    	if (leds_left[tail_right].getLuma() == 0){
	    		tail_right++;
	    	}
	    }




	} else {
		//Ungerade Zahl --> eine Zahl in der Mitte
		middle = leds_left_size / 2;
	}



//	for (int i = 0; i < 255; i++) {
//		fadeToBlackBy(leds_left, leds_left_size, 1);
//		fadeToBlackBy(leds_top, leds_left_size, 1);
//		fadeToBlackBy(leds_right, leds_left_size, 1);
//
//		FastLED.show();
//		FastLED.delay(10);
//	}

}

void loop() {


	//test124();
	rainbow(20000);
	//fadeToBlack(10);
	//walkWorms();
	//randomColors();

	Serial.println(LEDS.getFPS());
	//fadeColor();
	//singleDots();
}

void showfps(){
	currentMillis = millis();

}