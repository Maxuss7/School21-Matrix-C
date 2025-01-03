#include "s21_matrix.h"

void s21_mult_checked_matrices(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      double value = 0.0;
      for (int k = 0; k < A->columns; k++) {
        value += A->matrix[i][k] * B->matrix[k][j];
      }
      result->matrix[i][j] = value;
    }
  }
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;

  if (!s21_is_a_good_matrix(A) || !s21_is_a_good_matrix(B)) {
    code = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    code = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, B->columns, result);
    if (code == OK) {
      s21_mult_checked_matrices(A, B, result);
    }
  }

  return code;
}
