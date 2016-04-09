/*
 * Author: Raul Vasile
 * Mail: vasile.raul@webmonsters.ro
 */

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

unsigned long long solve(int number, FILE *output, int *digits) {
  unsigned long acc = 1;

  // Could not find a limit for acc, so basically I go to the limit of ulonglong
  while(diffzero(digits, 10) == 0 && acc <= 99999999) {
    unsigned long long aux = number * acc;

    while(aux > 0) {
      digits[aux % 10]++;
      aux /= 10;
    }

    acc++;
  }

  return number * (acc - 1);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Error: too many parameters!\n");
    printf("Usage: ./main input_file output_file\n");
    return 0;
  }

  FILE *input, *output;

  int length, i, number;
  int *vect;
  unsigned long long rc;

  input = fopen(argv[1], "r");
  output = fopen(argv[2], "a");

  if (input == NULL) {
    printf("Error on opening input file\n");
    return 0;
  }

  if (output == NULL) {
    printf("Error on opening output file\n");
    return 0;
  }

  fscanf(input, "%d", &length);

  for (i = 0; i < length; i++) {
    fscanf(input, "%d", &number);

    if (number == 0) {
      fprintf(output, "Case #%d: INSOMNIA\n", i + 1);
    } else {
      int digits[10];

      initializeVector(digits, 10);

      rc = solve(number, output, digits);

      if (rc == -1) {
        fprintf(output, "Case #%d: INSOMNIA\n", i + 1);
      } else {
        fprintf(output, "Case #%d: %llu\n", i + 1, rc);
      }
    }
  }

  return 0;
}
