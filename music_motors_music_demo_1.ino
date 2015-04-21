// include these three libraries for all M3T3 projects
#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>

void setup() {
  Music.init();

}

void loop() {
  init posA = analogRead(A1);
  init posB = analogRead(A9);
  
  init freq = map(posA, 0, 1023, 500, 1500);
  init freq = map(posB, 0, 1023, 500, 1500);
  
  Music.setFrequency1(freqA);
  Music.setFrequency2(freqB);

}
