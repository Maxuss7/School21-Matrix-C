#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = OK;
  if (!s21_is_a_good_matrix(A)) {
    code = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    code = CALCULATION_ERROR;
  } else {
    code = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && code == OK; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor;
        code = s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        if (code != OK) break;
        s21_minor(A, &minor, i, j);
        // Определитель минора
        double minor_det = 0.0;
        s21_determinant(&minor, &minor_det);
        // Знаки в шахматном порядке
        result->matrix[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * minor_det;
        s21_remove_matrix(&minor);
      }
    }
  }
  return code;
}
