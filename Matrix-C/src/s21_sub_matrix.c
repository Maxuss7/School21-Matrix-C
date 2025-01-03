#include "s21_matrix.h"

void s21_sub_checked_matrices(matrix_t *A, matrix_t *B, matrix_t *result) {
  int rows = A->rows;
  int columns = A->columns;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;
  if (!s21_is_a_good_matrix(A) || !s21_is_a_good_matrix(B)) {
    code = INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    code = CALCULATION_ERROR;
  } else {
    code = s21_create_matrix(A->rows, A->columns, result);
    if (code == OK) {
      s21_sub_checked_matrices(A, B, result);
    }
  }
  return code;
}
