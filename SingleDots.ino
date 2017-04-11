

void singleDots() {

	bool drawWorm = false;

	for (int i = 0; i < total_size / 2; i++) {

		if ((i % 2) == 0 ){
			drawWorm = true;
		}else{
			drawWorm = false;
		}

		if (drawWorm) {
			leds_all[0] = CRGB(255,255,0);
			leds_all[total_size/2] = CRGB(255,0,0);
		} else {
			leds_all[0] = CRGB(0, 0, 0);
			leds_all[total_size/2] = CRGB(0, 0, 0);
		}

		FastLED.show();
		FastLED.delay(100);

		moveAllToRight();
	}

	while(true){
		moveAllToRight();
		FastLED.show();
		FastLED.delay(100);
	}

}

