#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
  TODO:
  - Randomize Key
  - Randomize Mode
  - Randomize Chord progression
      - depending on chord progresion length that is also random
*/

int generate_bpm() {
  srand(time(0));
  return rand() % (200 - 75 + 1) + 75;
}

int main() {
  char input[10]; // Buffer for user input

  do {
    // Check if input is "q", "Quit", or "quit"
    if (strcmp(input, "q") == 0 || strcmp(input, "Quit") == 0 ||
        strcmp(input, "quit") == 0) {
      break; // Exit the loop if the user enters "q", "Quit", or "quit"
    }

    printf("BPM: %d\n", generate_bpm());
    printf("\nRun again? Type anything to refresh (or \"q\" to exit): ");
    scanf("%9s", input); // Read input from the user (up to 9 characters)
  } while (1); // Infinite loop controlled by `break`

  printf("Exiting song starter...\n");
  return 0;
}
