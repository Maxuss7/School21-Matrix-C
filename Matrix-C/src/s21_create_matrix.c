#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int code = OK;
  result->rows = rows;
  result->columns = columns;

  if (rows <= 0 || columns <= 0) {
    code = INCORRECT_MATRIX;
  } else {
    result->matrix = malloc(rows * sizeof(double *));
    if (result->matrix == NULL) {
      code = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = malloc(columns * sizeof(double));
        if (result->matrix[i] == NULL) {
          for (int j = 0; j < i; j++) {
            free(result->matrix[j]);
          }
          free(result->matrix);
          code = INCORRECT_MATRIX;
          break;
        }
      }
    }
  }
  return code;
}
