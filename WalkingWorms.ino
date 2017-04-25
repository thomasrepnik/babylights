#define WORM_LENGTH 3
#define WORM_GAP    3

void walkWorms(unsigned int durationMillis) {

	unsigned long startTime = millis();

	bool drawWorm = true;
	uint32_t color = 0x0000FF;

	for (int i = 0; i < total_size; i++) {

		color+=93000;

		int index = i % (WORM_LENGTH + WORM_GAP);
		if (index < WORM_LENGTH){
			drawWorm = true;
		}else{
			drawWorm = false;
		}

		if (drawWorm) {
			*leds_all_ordered[0] = CRGB(color);
		} else {
			*leds_all_ordered[0] = CRGB(0, 0, 0);
		}

		FastLED.show();
		FastLED.delay(50);

		moveAllToRight();
	}

	while(true){
		moveAllToRight();
		FastLED.show();
		FastLED.delay(50);

		if (millis() - startTime > durationMillis){
			exitAnimation();
			break;
		}
	}

}

void moveAllToRight() {
	for (int i = total_size - 1; i >= 0; i--) {

		if (i == 0) {
			*leds_all_ordered[i] = *leds_all_ordered[total_size - 1];
		} else {
			*leds_all_ordered[i] = *leds_all_ordered[i-1];
		}
	}

}
