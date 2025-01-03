#include "s21_matrix.h"

void s21_transpose_checked_matrix(matrix_t *A, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int code = OK;
  if (!s21_is_a_good_matrix(A)) {
    code = INCORRECT_MATRIX;
  } else {
    code = s21_create_matrix(A->columns, A->rows, result);
    if (code == OK) {
      s21_transpose_checked_matrix(A, result);
    }
  }
  return code;
}