/*
 * Author: Raul Vasile
 * Mail: vasile.raul@webmonsters.ro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solve(char *line, int steps) {
  int length = strlen(line) - 1;
  int done = 0;
  int i;

  while (done == 0) {
    if (length <= 0) {
      done = 1;
    }

    if (line[length] == '+') {
      while (line[length] == '+') {
        length--;
      }
      if (length < 0) {
        done = 1;

        return steps;
      }
    }

    if (length >= 0) {
      if (line[0] == '-') {
        for (i = 0; i <= length; i++) {
          if (line[i] == '+') {
            line[i] = '-';
          } else {
            line[i] = '+';
          }
        }

        steps++;
      } else {
        int index = 0;

        while(line[index] == '+') {
          line[index] = '-';

          index++;
        }

        steps++;
      }
    }
  }

  return steps;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Error: too few arguments\n");

    return 0;
  }

  FILE *input, *output;

  int length, i, rc;
  char *line;

  line = (char *) malloc (101 * sizeof(char));

  input = fopen(argv[1], "r");
  output = fopen(argv[2], "w");

  if (input == NULL) {
    printf("Error on opening input file\n");
    return 0;
  }

  if (output == NULL) {
    printf("Error on opening output file\n");
    return 0;
  }

  fgets(line, 101, input);

  length = atoi(line);

  for (i = 0; i < length; i++) {
    int steps = 0;

    fgets(line, 101, input);

    line[strlen(line) - 1] = '\0';

    rc = solve(line, steps);

    fprintf(output, "Case #%d: %d\n", i + 1, rc);
  }

  fclose(input);
  fclose(output);

  return 0;
}
