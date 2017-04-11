#define FADING_DELAY 40

void fadeColor() {
	//start from red
	for (int colorStep = 0; colorStep <= 255; colorStep++) {

		int r = 255;
		int g = 0;
		int b = colorStep;

		setAllLEDs(CRGB(r, g, b));

		// Display the colors we just set on the actual LEDs
		FastLED.delay(FADING_DELAY);
		FastLED.show();
	}

	//into blue
	for (int colorStep = 255; colorStep >= 0; colorStep--) {

		int r = colorStep;
		int g = 0;
		int b = 255;

		setAllLEDs(CRGB(r, g, b));

		// Display the colors we just set on the actual LEDs
		FastLED.delay(FADING_DELAY);
		FastLED.show();
	}

	//start from blue
	for (int colorStep = 0; colorStep <= 255; colorStep++) {

		int r = 0;
		int g = colorStep;
		int b = 255;

		setAllLEDs(CRGB(r, g, b));

		// Display the colors we just set on the actual LEDs
		FastLED.delay(FADING_DELAY);
		FastLED.show();
	}

	//into green
	for (int colorStep = 255; colorStep >= 0; colorStep--) {

		int r = 0;
		int g = 255;
		int b = colorStep;

		setAllLEDs(CRGB(r, g, b));

		// Display the colors we just set on the actual LEDs
		FastLED.delay(FADING_DELAY);
		FastLED.show();
	}

	//start from green
	for (int colorStep = 0; colorStep <= 255; colorStep++) {

		int r = colorStep;
		int g = 255;
		int b = 0;

		setAllLEDs(CRGB(r, g, b));

		// Display the colors we just set on the actual LEDs
		FastLED.delay(FADING_DELAY);
		FastLED.show();
	}

	//into yellow
	for (int colorStep = 255; colorStep >= 0; colorStep--) {

		int r = 255;
		int g = colorStep;
		int b = 0;

		setAllLEDs(CRGB(r, g, b));

		// Display the colors we just set on the actual LEDs
		FastLED.delay(FADING_DELAY);
		FastLED.show();
	}

}

void setAllLEDs(CRGB color) {
	fill_solid(leds_all, LEDS_ALL_SIZE, color);
}

