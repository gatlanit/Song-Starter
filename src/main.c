#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
  TODO:
  Command Line arguments to customize paramaters (i.e # chords, mode, key, and
  bpm)
*/

void check_updates() {
  printf("Checking for updates...\n");
  int result = system("curl -sSL "
                      "https://raw.githubusercontent.com/gatlanit/Song-Starter/"
                      "master/install.sh | bash");
  if (result == 0) {
    printf("Update successful.\n");
  } else {
    printf("Update failed.\n");
  }
}

int is_number(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isdigit(str[i]))
      return 0;
  }
  return 1;
}

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

void generate_chord_progression(char *mode) {
  // Zeros added as placeholders to fill in allocated space

  /*
    Numbers 1-7 refer to each chord in a chord progression
    (e.g. 1 = Tonic, 5 = Perfect 5th, etc)
  */
  int majorChordChoices[8][6] = {{1, 6, 3, 1, 1, 6}, {4, 2, 5, 7, 0, 0},
                                 {5, 7, 4, 2, 1, 6}, {1, 6, 5, 0, 0, 0},
                                 {4, 2, 1, 6, 0, 0}, {5, 7, 6, 2, 6, 0},
                                 {5, 1, 6, 0, 0, 0}, {1, 6, 3, 0, 0, 0}};

  int minorChordChoices[8][6] = {{1, 6, 3, 1, 1, 6}, {4, 2, 5, 7, 0, 0},
                                 {5, 7, 4, 2, 1, 6}, {1, 6, 5, 0, 0, 0},
                                 {4, 2, 1, 6, 0, 0}, {5, 7, 4, 2, 6, 0},
                                 {5, 1, 6, 0, 0, 0}, {1, 6, 3, 0, 0, 0}};

  int columnSizes[8] = {
      6, 4, 6, 3, 4, 5, 3, 3}; // Predetermined number of columns for each row
  int progresionLengths[] = {4, 8}; // Either 4 or 8 bars long
  int length = progresionLengths[rand() % 2];

  int chordProgression[length];

  for (int i = 0; i < length; i++) {
    if (strcmp(mode, "Major") == 0) {
      int sizeOfColumn = columnSizes[i % 8];
      int randomIndex = rand() % sizeOfColumn;

      chordProgression[i] = majorChordChoices[i % 8][randomIndex];
    } else {
      int sizeOfColumn = columnSizes[i % 8];
      int randomIndex = rand() % sizeOfColumn;

      chordProgression[i] = minorChordChoices[i % 8][randomIndex];
    }
  }

  printf("Chord Progression: { ");
  for (int i = 0; i < sizeof(chordProgression) / sizeof(chordProgression[0]);
       i++) {
    printf("%d ", chordProgression[i]);
  }
  printf("}\n");
}

int main(int argc, char *argv[]) {
  const char version[] = "v1.21";

  char *valid_keys[] = {"C",  "C#", "D",  "D#", "E",  "F",
                        "F#", "G",  "G#", "A",  "A#", "B"};
  const char *valid_modes[] = {"Major", "Minor"};

  // Initial values (tagged as eligible for randomization)
  int bpm = -1;
  char *mode = NULL;
  char *key = NULL;

  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "update") == 0) {
      check_updates();
      return 0;
    } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "version") == 0) {
      printf("SongStarter version %s\n", version);
      return 0;
    } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "help") == 0) {
      printf("Example usage:\n");
      printf("  song-starter                  Generate parameters\n");
      printf("  song-starter [-h | help]      Get help\n");
      printf("  song-starter [-v | version]   List version\n");
      printf("  song-starter [-u | update]    Check and install updates\n");
      printf("\nFurther help -> https://github.com/gatlanit/Song-Starter\n");
      return 0;
    }
  }

  char input[10]; // Buffer for user input

  do {
    // Check if input is "q", "Q", "Quit", or "quit"
    if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0 ||
        strcmp(input, "Quit") == 0 || strcmp(input, "quit") == 0) {
      break;
    }

    // To be used in chord Progression
    mode = generate_mode();

    printf("BPM: %d\n", generate_bpm());
    printf("Key: %s\n", generate_key());
    printf("Mode: %s\n", mode);
    generate_chord_progression(mode);

    printf("\nRun again? Type anything to refresh (or \"q\" to exit): ");
    scanf("%9s", input);
  } while (1);

  printf("Exiting song starter...\n");
  return 0;
}
