#define STRIP_LENGTH 19
#define STRIP_COUNT 5


int strips_starthue = 90;
int strips_huedelta = 30;


void brightStrips(unsigned int durationMillis) {

	unsigned long startTime = millis();
	int index = 0;
	int deltaBetweenStrips = (total_size - (STRIP_COUNT * STRIP_LENGTH)) / STRIP_COUNT;

	for (int s = 0; s < STRIP_COUNT; s++){
		for (int i = 0; i<STRIP_LENGTH; i++){
			*leds_all_ordered[index++] = CHSV(strips_starthue , triwave8(map(i, 0, STRIP_LENGTH, 60, 255 - 60)),  triwave8(map(i, 0, STRIP_LENGTH, 10,245)));
		}
		for (int y = 0; y < deltaBetweenStrips; y++){
			*leds_all_ordered[index++] = CRGB::Black;
		}
		strips_starthue += strips_huedelta;
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


