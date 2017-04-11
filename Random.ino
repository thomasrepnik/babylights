

void randomColors() {

	fill_solid(leds_left, leds_left_size, CRGB(255,0,0));
	FastLED.delay(3000);

	for (int i = 0; i< 20; i++){
		leds_left[3].fadeToBlackBy(70);
		FastLED.show();
		FastLED.delay(20);
	}

	FastLED.delay(1000);

	//int value = map(sin16_avr(millis() * 16), -32767, 32767, 0, total_size);



//	setLED(value, CRGB(random(0, 255),random(0, 255), random(0, 255)));
//	FastLED.show();
}



