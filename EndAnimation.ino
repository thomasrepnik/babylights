
void endAnimation() {

	int index = 0;

	while(true){



		for (int i = 0; i<10; i++){
			leds_all[index + i].fadeToBlackBy(map(i, 0,9, 40, 30));
		}


		if (leds_all[index].getLuma()==0){
			leds_all[index].fadeToBlackBy(255);
			index++;
		}
		FastLED.show();
		FastLED.delay(70);
	}

}

void exitAnimation(){
	for (int i = 0; i < 500 ; i++){
		fadeToBlackBy(leds_all, total_size, 1);
		FastLED.show();
		//FastLED.delay(2);
	}

	fill_solid(leds_all, total_size, CRGB::Black);
	FastLED.show();
}

