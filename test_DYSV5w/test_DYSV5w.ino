/*   
modified on June 5, 2018
by SnijderC Chris from github.com/SnijderC/dyplayer/tree/master/examples/PlaySoundByNumber
Home 
*/ 
#include <Arduino.h>
#include "DYPlayerArduino.h"

// Initialise the player, it defaults to using Serial.
DY::Player player;

void setup() {
  player.begin();
  player.setVolume(30); // 100% Volume
}

void loop() {
  player.playSpecified("/00001");
  delay(5000);
}
