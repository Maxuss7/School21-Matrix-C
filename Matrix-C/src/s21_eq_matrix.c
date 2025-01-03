#include <math.h>

#include "s21_matrix.h"

#define EPSILON 1e-7

int s21_eq_checked_matrices(matrix_t *A, matrix_t *B) {
  int rows = A->rows;
  int columns = A->columns;
  int is_equal = SUCCESS;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= EPSILON) {
        is_equal = FAILURE;
        break;
      }
    }
    if (is_equal == FAILURE) {
      break;
    }
  }

  return is_equal;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int code;
  int both_matrix_are_good = s21_is_a_good_matrix(A) && s21_is_a_good_matrix(B);

  if (both_matrix_are_good && (A->rows == B->rows) &&
      (A->columns == B->columns)) {
    code = s21_eq_checked_matrices(A, B);
  } else {
    code = FAILURE;
  }

  return code;
}
