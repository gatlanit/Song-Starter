#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
  TODO:
  - Randomize Chord progression
      - depending on chord progresion length that is also random
*/

int generate_bpm() {
  srand(time(0));
  return rand() % (200 - 75 + 1) + 75;
}

char *generate_key() {

  static const char *keys[] = {"C",  "C♯", "D",  "D♯", "E",  "F",
                               "F♯", "G",  "G♯", "A",  "A♯", "B"};

  return (char *)keys[rand() % (11 - 0 + 1) + 0];
}

char *generate_mode() {

  static const char *modes[] = {"Major", "Minor"};

  return (char *)modes[rand() % (1 - 0 + 1) + 0];
}

int main() {
  char input[10]; // Buffer for user input

  do {
    // Check if input is "q", "Q", "Quit", or "quit"
    if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0 ||
        strcmp(input, "Quit") == 0 || strcmp(input, "quit") == 0) {
      break; // Exit the loop if the user enters "q", "Quit", or "quit"
    }

    printf("BPM: %d\n", generate_bpm());
    printf("Key: %s\n", generate_key());
    printf("Modes: %s\n", generate_mode());

    printf("\nRun again? Type anything to refresh (or \"q\" to exit): ");
    scanf("%9s", input);
  } while (1);

  printf("Exiting song starter...\n");
  return 0;
}
