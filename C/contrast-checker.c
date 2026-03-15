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
char *join_array(char *separator, char **string);

int main(int argc, char *argv[]) {
  printf("Processing...\n");
  fflush(stdin);

  printf("Processing %d args...\n", argc);
  fflush(stdin);

  if (argc <= 1) {
    print_command_usage();
    return 1;
  }

  printf("Passed this stage\n");
  fflush(stdin);

  char **hex_strings;
  char **invalid_strings;
  uint8_t num_of_invalid_strings = 0;
  uint8_t num_of_hex_strings = 0;

  printf("Past variable declarations\n");
  fflush(stdin);

  // Allocate hex_string memory (avoiding segmentation fault)
  hex_strings = (char **)malloc(MAX_HEX_COLOR_OPTIONS * sizeof(char *));
  invalid_strings = (char **)malloc(1000 * sizeof(char *));

  printf("Past array mallocs.\n");
  fflush(stdin);

  char *argv_array = join_array("; ", argv);
  printf("Processing... - %s\n", argv_array);
  free(argv_array);
  argv_array = NULL;

  for (int i = 1; i <= argc - 1; i++) {
    if (strlen(argv[i]) != 6) {
      invalid_strings[num_of_invalid_strings++] = argv[i];
    } else {
      hex_strings[num_of_hex_strings++] = argv[i];
    }
  }

  printf("Past string validations\n");
  fflush(stdin);

  if (num_of_invalid_strings > 0) {
    char *invalid_strings_joined_str = join_array(", ", invalid_strings);
    printf(
        "Invalid Strings: (Expected '[a-zA-Z1-9]{6}' for each 'Word') -  %s\n",
        invalid_strings_joined_str);
    free(invalid_strings_joined_str);
    invalid_strings_joined_str = NULL;
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

char *join_array(char *separator, char **string) {
  char *result_string = (char *)malloc(1001 * sizeof(char));

  if (result_string == NULL) {
    perror("Memory Allocation Failed - 'Reporting incorrect Hex Strings.\n");
    exit(EXIT_FAILURE);
  }

  printf("In 'Join Array' function past result string malloc. \n");
  fflush(stdin);

  printf("Size of string %lu\n", sizeof(string));
  printf("Size of first element %lu \n", sizeof(string[0]));

  printf("In 'Join Array' function: Calculating string array size. \n");
  fflush(stdin);

  char **limit_ptr = string;

  while (*limit_ptr != NULL) {
    printf("Size of the Result String: %lu\n", sizeof(result_string));
    printf("inside limit_ptr: %s. \n", *limit_ptr);
    strcat(result_string, *limit_ptr);
    strcat(result_string, separator);
    limit_ptr++;
  }

  printf("In 'Join Array' function: Concat result string. \n");
  fflush(stdin);

  return result_string;
}
