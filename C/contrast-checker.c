#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* C program to check if contrast between foreground and backgrounds round color
 * meets level AA requirements. Assumptions:
 *  - Most if not all backgrounds in web development is either white, black or
 * shades of gray. Program below will only be using white or black.
 *
 * Algorithm used
 *  - Get testing color, given by argv.
 *  - Test that against white.
 *  - Take result from contrast formula
 *    - If, contrast meets level AA requirements. return that color.
 *    - Else,
 *      take the difference of the level AA contrast requirements - current
 *      contrast. Increase given color by the difference (e.g, 10%).
 *      recalculate.
 *
 *
 * */

#define LEVEL_AA_CONTRAST_RATIO 4.51
#define CONTRAST_BUFFER_ADDITION 0.5
#define MAX_HEX_STRING_LENGTH 5
#define MAX_HEX_COLOR_OPTIONS 10

struct rgb_obj {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

/* Functions tied to calculations, or algorithm work. */
float calc_contrast_ratio(struct rgb_obj color);

/* Validation Functions */
int validate_hex_string(char hex_string[6]);

/* Utility functions */
void print_command_usage();
char *join_array(char *separator, char **array);

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    print_command_usage();
    return 1;
  }

  char **hex_strings;
  char **invalid_strings;
  uint8_t num_of_invalid_strings = 0;
  uint8_t num_of_hex_strings = 0;

  // Allocate hex_string memory (avoiding segmentation fault)
  hex_strings = (char **)malloc(MAX_HEX_COLOR_OPTIONS * sizeof(char *));
  invalid_strings = (char **)malloc(1000 * sizeof(char *));

  for (int i = 1; i <= argc - 1; i++) {
    if (strlen(argv[i]) != 6) {
      invalid_strings[num_of_invalid_strings++] = argv[i];
    } else {
      hex_strings[num_of_hex_strings++] = argv[i];
    }
  }

  if (num_of_invalid_strings > 0) {
    printf("Invalid Strings: (Expected '[a-zA-Z1-9]{6}' for each 'Word') -  %s",
           join_array(", ", invalid_strings));
    return 1;
  }

  if (num_of_hex_strings > 0) {
  }

  free(hex_strings);
  free(invalid_strings);

  return 0;
}

float calc_contrast_ratio(struct rgb_obj color) { return 0.0; }

int validate_hex_string(char hex_string[MAX_HEX_STRING_LENGTH]) { return 0; }

void print_command_usage() {
  const char *command_text = "Contrast Checker Usage: \n"
                             "./filename [foreground_color]";

  printf("%s", command_text);
}

char *join_array(char *separator, char **array) {
  char *result_string = malloc(1001 * sizeof(char));

  if (result_string == NULL) {
    perror("Memory Allocation Failed - 'Reporting incorrect Hex Strings.\n");
    exit(EXIT_FAILURE);
  }

  uint8_t array_size = sizeof(array) / sizeof(array[0]);

  for (int i = 0; i <= array_size + 1; i++) {
    strcat(result_string, array[i]);
    strcat(result_string, separator);
  }

  return result_string;
}
