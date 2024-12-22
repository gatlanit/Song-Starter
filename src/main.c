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

  return (char *)keys[rand() % 12];
}

char *generate_mode() {
  static const char *modes[] = {"Major", "Minor"};

  return (char *)modes[rand() % 2];
}

/*
  FIX:
    - Some issues with generating the chord progression including
      - Getting weird results such as starting with 0
      - Abnormally large numbers
      - Wrong numbers for their chord degrees
      - Etc
*/
void generate_chord_progression(char *mode) {
  int majorChordChoices[8][6] = {{1, 6, 3}, {4, 2, 5, 7}, {5, 7, 4, 2, 1, 6},
                                 {1, 6, 5}, {4, 2, 1, 6}, {5, 7, 6, 2, 6},
                                 {5, 1, 6}, {1, 6, 3}};

  int minorChordChoices[8][6] = {{1, 6, 3}, {4, 2, 5, 7}, {5, 7, 4, 2, 1, 6},
                                 {1, 6, 5}, {4, 2, 1, 6}, {5, 7, 4, 2, 6},
                                 {5, 1, 6}, {1, 6, 3}};

  int progresionLengths[] = {4, 8, 16};
  int length = progresionLengths[rand() % 3];

  int chordProgression[length];

  for (int i = 0; i < length; i++) {
    if (strcmp(mode, "Major") == 0) {
      int sizeOfColumn =
          sizeof(majorChordChoices) / sizeof(majorChordChoices[i][0]);
      int randomIndex = rand() % sizeOfColumn;

      chordProgression[i] = majorChordChoices[i][randomIndex];
    } else {
      int sizeOfColumn =
          sizeof(minorChordChoices) / sizeof(minorChordChoices[i][0]);
      int randomIndex = rand() % sizeOfColumn;

      chordProgression[i] = minorChordChoices[i][randomIndex];
    }
  }

  printf("Chord Progression: { ");

  for (int i = 0; i < sizeof(chordProgression) / sizeof(chordProgression[0]);
       i++) {
    printf("%d ", chordProgression[i]);
  }

  printf("}\n");
}

int main() {
  char input[10]; // Buffer for user input

  do {
    // Check if input is "q", "Q", "Quit", or "quit"
    if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0 ||
        strcmp(input, "Quit") == 0 || strcmp(input, "quit") == 0) {
      break; // Exit the loop if the user enters the following
    }

    // To be used in chord Progression
    char *mode = generate_mode();

    printf("BPM: %d\n", generate_bpm());
    printf("Key: %s\n", generate_key());
    printf("Modes: %s\n", mode);
    generate_chord_progression(mode);

    printf("\nRun again? Type anything to refresh (or \"q\" to exit): ");
    scanf("%9s", input);
  } while (1);

  printf("Exiting song starter...\n");
  return 0;
}
