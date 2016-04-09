/*
 * Author: Raul Vasile
 * Mail: vasile.raul@webmonsters.ro
 */

void initializeVector(int *vect, int length) {
  int i;

  for (i = 0; i < length; i++) {
    vect[i] = 0;
  }
}

int diffzero(int *vect, int length) {
  int i, valid = 1;

  for (i = 0; i < length; i++) {
    if (vect[i] == 0) {
      valid = 0;
    }
  }

  return valid;
}
