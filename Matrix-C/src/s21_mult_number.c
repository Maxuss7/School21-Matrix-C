#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int code = OK;
  if (!s21_is_a_good_matrix(A)) {
    code = INCORRECT_MATRIX;
  } else {
    code = s21_create_matrix(A->rows, A->columns, result);
    if (code == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return code;
}
