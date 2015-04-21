// include these three libraries for all M3T3 projects
#include <spi4teensy3.h>
#include <EEPROM.h>
#include <M3T3.h>

long tick = 0;

int c = 0;
int last_pos = 0;

byte waveFormArray[] = { SINE,
                         SQUARE,
                         PULSE,
                         TRIANGLE,
                         SAW,
                         FUZZ,
                         /* DIGI1,
                         DIGI2,
                         DIGI3,
                         DIGI4,
                         NOISE,
                         DIGI6,
                         TAN1,
                         TAN2,
                         TAN3,
                         TAN4 */
                       };

void setup() {

  tick = millis();
  last_pos = analogRead(A1);

  Music.init();

  Music.setWaveform(SINE);

}

void loop() {

  long tick_now = millis();

  long dt = tick_now - tick;

  if (dt >= 20) {

    c++;

    int current_pos = analogRead(A1);
    int dx = last_pos - current_pos;
    float vel = (float) dx / (float) dt;
    
    if (abs(vel) >= 1.0) {
      set_freq(vel);
    }

    if (c % 15 == 0) {
      Serial.println(vel);
    }

    tick = millis();
    last_pos = current_pos;

  }

  int posA = analogRead(A1);
  int posB = analogRead(A9);

  int freqA = map(posA, 0, 1023, 500, 1500);
  int freqB = map(posB, 0, 1023, 500, 1500);

  Music.setFrequency1((float)freqA);
  Music.setFrequency2((float)freqB);

}

void set_freq(float vel) {
  float vel_amp = abs(vel);
  float freq = map(vel_amp, 1, 11, 100, 1500);
  
  Music.setFrequency(freq);

}
