
uint8_t   twinkle_fadespeed = 4;                                        // How quickly does it fade? Lower = slower fade rate.
int       twinkle_starthue = 50;                                       // Starting hue.
uint8_t   twinkle_hueincrement = 1;                                        // Incremental value for rotating hues
uint8_t   twinkle_saturation = 100;                                      // The saturation, where 255 = brilliant colours.
uint8_t   twinkle_brightness = 255;                                      // Brightness of a sequence. Remember, max_bright is the overall limiter.
int       twinkle_huediff = 256;                                      // Range of random #'s to use for hue

void twinkle(unsigned int durationMillis) {

	unsigned long startTime = millis();

	while(true){
		confetti();
		FastLED.show();
		FastLED.delay(5);

		if (millis() - startTime > durationMillis){
			exitAnimation();
			break;
		}

	}
}

void confetti() {                                             // random colored speckles that blink in and fade smoothly
  fadeToBlackBy(leds_all, total_size, twinkle_fadespeed);                    // Low values = slower fade.
  int pos = random16(total_size);                               // Pick an LED at random.
  *leds_all_ordered[pos] += CHSV((twinkle_starthue + random16(twinkle_huediff))/4 , twinkle_saturation, twinkle_brightness);  // I use 12 bits for hue so that the hue increment isn't too quick.
  twinkle_starthue = twinkle_starthue + twinkle_hueincrement;                                // It increments here.
} // confetti()



