#include "s21_matrix.h"

int s21_is_a_good_matrix(matrix_t *A) {
  int boolean = 1;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    boolean = 0;
  }
  return boolean;
}

int s21_copy_matrix(matrix_t *source, matrix_t *destination) {
  int code = OK;

  if (!s21_is_a_good_matrix(source)) {
    return INCORRECT_MATRIX;
  }

  code = s21_create_matrix(source->rows, source->columns, destination);
  if (code == OK) {
    for (int i = 0; i < source->rows; i++) {
      for (int j = 0; j < source->columns; j++) {
        destination->matrix[i][j] = source->matrix[i][j];
      }
    }
  }

  return code;
}

int s21_minor(matrix_t *A, matrix_t *minor, int row, int column) {
  int minor_row = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i != row) {
      int minor_col = 0;
      for (int j = 0; j < A->columns; j++) {
        if (j != column) {
          // Записываем в матрицу миноров значения, которые не оказались на
          // поданной строке/столбце
          minor->matrix[minor_row][minor_col] = A->matrix[i][j];
          minor_col++;
        }
      }
      minor_row++;
    }
  }
  return 0;
}

int s21_is_matrix_square(matrix_t *A) {
  if (A == NULL) {
    return 0;
  }
  return A->rows == A->columns ? 1 : 0;
}
