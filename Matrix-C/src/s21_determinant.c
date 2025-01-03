#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int code = OK;
  if (!s21_is_a_good_matrix(A)) {
    code = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    code = CALCULATION_ERROR;
  } else if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else if (A->rows > 2) {
    double det = 0.0;
    int sign = 1;
    for (int j = 0; j < A->columns; j++) {
      matrix_t minor;
      if (s21_create_matrix(A->rows - 1, A->columns - 1, &minor) != OK) {
        code = INCORRECT_MATRIX;
        break;
      }
      s21_minor(A, &minor, 0, j);
      double minor_det;
      s21_determinant(&minor, &minor_det);
      det += sign * A->matrix[0][j] * minor_det;
      sign = -sign;
      s21_remove_matrix(&minor);
    }
    *result = det;
  }
  return code;
}
