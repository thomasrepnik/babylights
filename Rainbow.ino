#define LEDS_PER_TRANSITION 5

void rainbow(unsigned int durationMillis) {

	unsigned long startTime = millis();

	CRGB colors[9];
	colors[0] = CRGB(255,0,0);
	colors[1] = CRGB(255, 153, 51); 	//orange
	colors[2] = CRGB(255, 255, 0); 	//gelb
	colors[3] = CRGB(128,255,0); 		//hellgrün
	colors[4] = CRGB(0,255,0); 		//grün
	colors[5] = CRGB(102,78,255); 	//hellblau
	colors[6] = CRGB(0,0,255); 		//blau
	colors[7] = CRGB(127,0,255); 		//dunkelviolett
	colors[8] = CRGB(255, 0, 255); 	//pink

	CRGB startColor(255, 0, 0);
	CRGB endColor(0, 0, 255);

	for (int i = 0; i < total_size; i++) {

		fadePixel(colors[(i / LEDS_PER_TRANSITION) % 9], colors[((i / LEDS_PER_TRANSITION) + 1) % 9], i % LEDS_PER_TRANSITION);

		//setLED(0, colors[i]);

		FastLED.show();
		FastLED.delay(50);

		moveAllToRight();
	}

	while (true) {
		moveAllToRight();
		FastLED.show();
		FastLED.delay(50);

		if (millis() - startTime > durationMillis){
			exitAnimation();
			break;
		}
	}

}

void fadePixel(CRGB startColor, CRGB endColor, int step) {
	int r_diff = abs(startColor.r - endColor.r);
	int g_diff = abs(startColor.g - endColor.g);
	int b_diff = abs(startColor.b - endColor.b);

	int r_step = r_diff / LEDS_PER_TRANSITION;
	int g_step = g_diff / LEDS_PER_TRANSITION;
	int b_step = b_diff / LEDS_PER_TRANSITION;

	int new_r;
	int new_b;
	int new_g;

	if (startColor.r < endColor.r) {
		new_r = startColor.r + (step * r_step);
	} else {
		new_r = startColor.r - (step * r_step);
	}

	if (startColor.g < endColor.g) {
		new_g = startColor.g + (step * g_step);
	} else {
		new_g = startColor.g - (step * g_step);
	}

	if (startColor.b < endColor.b) {
		new_b = startColor.b + (step * b_step);
	} else {
		new_b = startColor.b - (step * b_step);
	}

	*leds_all_ordered[0] = CRGB(new_r, new_g, new_b);

}

