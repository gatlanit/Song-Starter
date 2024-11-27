#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
  TODO:
  Randomize Key
  Randomize Mode
  Randomize Chord progression (depending
  on chord progresion length that is
  also random)
*/

int generate_bpm() {
  srand(time(0));
  return rand() % (200 - 75 + 1) + 75;
}

int main() {

  printf("BPM: %d", generate_bpm());

  return 0;
}
