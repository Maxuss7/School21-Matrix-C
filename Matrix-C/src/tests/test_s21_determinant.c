#include "./s21_matrix_tests.h"

START_TEST(determinant_1x1) {
  matrix_t A;
  double result;
  int code = s21_create_matrix(1, 1, &A);

  if (code == OK) {
    A.matrix[0][0] = 5;
    int det_code = s21_determinant(&A, &result);

    ck_assert_int_eq(det_code, OK);
    ck_assert_double_eq(result, 5);
  }

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2x2) {
  matrix_t A;
  double result;
  int code = s21_create_matrix(2, 2, &A);

  if (code == OK) {
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[1][0] = 3;
    A.matrix[1][1] = 4;

    int det_code = s21_determinant(&A, &result);

    ck_assert_int_eq(det_code, OK);
    ck_assert_double_eq(result, -2);
  }

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3x3) {
  matrix_t A;
  double result;
  int code = s21_create_matrix(3, 3, &A);

  if (code == OK) {
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;
    A.matrix[1][0] = 0;
    A.matrix[1][1] = 4;
    A.matrix[1][2] = 5;
    A.matrix[2][0] = 1;
    A.matrix[2][1] = 0;
    A.matrix[2][2] = 6;

    int det_code = s21_determinant(&A, &result);

    ck_assert_int_eq(det_code, OK);
    ck_assert_double_eq(result, 22);
  }

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_incorrect_matrix) {
  matrix_t A;
  double result;
  int code = s21_create_matrix(2, 3, &A);

  if (code == OK) {
    int det_code = s21_determinant(&A, &result);

    ck_assert_int_eq(det_code, CALCULATION_ERROR);
  }

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_incorrect_matrix2) {
  double result;
  int det_code = s21_determinant(NULL, &result);
  ck_assert_int_eq(det_code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_large_matrix) {
  matrix_t A;
  double result;
  int code = s21_create_matrix(4, 4, &A);

  if (code == OK) {
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;
    A.matrix[0][3] = 4;
    A.matrix[1][0] = 5;
    A.matrix[1][1] = 6;
    A.matrix[1][2] = 7;
    A.matrix[1][3] = 8;
    A.matrix[2][0] = 9;
    A.matrix[2][1] = 10;
    A.matrix[2][2] = 11;
    A.matrix[2][3] = 12;
    A.matrix[3][0] = 13;
    A.matrix[3][1] = 14;
    A.matrix[3][2] = 15;
    A.matrix[3][3] = 16;

    int det_code = s21_determinant(&A, &result);

    ck_assert_int_eq(det_code, OK);
    ck_assert_double_eq(result, 0);
  }

  s21_remove_matrix(&A);
}
END_TEST

Suite *get_suite_s21_determinant(void) {
  Suite *s = suite_create("\033[44m-=s21_determinant=-\033[0m");
  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, determinant_1x1);
  tcase_add_test(tc, determinant_2x2);
  tcase_add_test(tc, determinant_3x3);
  tcase_add_test(tc, determinant_incorrect_matrix);
  tcase_add_test(tc, determinant_incorrect_matrix2);
  tcase_add_test(tc, determinant_large_matrix);

  suite_add_tcase(s, tc);

  return s;
}