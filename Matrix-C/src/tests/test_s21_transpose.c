#include "./s21_matrix_tests.h"

START_TEST(transpose_success_1) {
  matrix_t A, expected, res;

  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;

  s21_create_matrix(3, 2, &expected);
  expected.matrix[0][0] = 1.0;
  expected.matrix[0][1] = 4.0;
  expected.matrix[1][0] = 2.0;
  expected.matrix[1][1] = 5.0;
  expected.matrix[2][0] = 3.0;
  expected.matrix[2][1] = 6.0;

  int status = s21_transpose(&A, &res);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&res, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose_success_2) {
  matrix_t A, expected, res;

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;

  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 1.0;
  expected.matrix[0][1] = 4.0;
  expected.matrix[0][2] = 7.0;
  expected.matrix[1][0] = 2.0;
  expected.matrix[1][1] = 5.0;
  expected.matrix[1][2] = 8.0;
  expected.matrix[2][0] = 3.0;
  expected.matrix[2][1] = 6.0;
  expected.matrix[2][2] = 9.0;

  int status = s21_transpose(&A, &res);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&res, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose_success_3) {
  matrix_t A, expected, res;

  s21_create_matrix(1, 3, &A);
  A.matrix[0][0] = 5.0;
  A.matrix[0][1] = 10.0;
  A.matrix[0][2] = 15.0;

  s21_create_matrix(3, 1, &expected);
  expected.matrix[0][0] = 5.0;
  expected.matrix[1][0] = 10.0;
  expected.matrix[2][0] = 15.0;

  int status = s21_transpose(&A, &res);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&res, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose_bad_matrix_1) {
  matrix_t expected, res;

  s21_create_matrix(3, 1, &expected);
  expected.matrix[0][0] = 5.0;
  expected.matrix[1][0] = 10.0;
  expected.matrix[2][0] = 15.0;

  int status = s21_transpose(NULL, &res);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(transpose_bad_matrix_2) {
  matrix_t A, expected, res;
  A.matrix = NULL;

  s21_create_matrix(3, 1, &expected);
  expected.matrix[0][0] = 5.0;
  expected.matrix[1][0] = 10.0;
  expected.matrix[2][0] = 15.0;

  int status = s21_transpose(&A, &res);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&expected);
}
END_TEST

Suite *get_suite_s21_transpose_matrix(void) {
  Suite *s = suite_create("\033[44m-=s21_transpose_matrix=-\033[0m");
  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, transpose_success_1);
  tcase_add_test(tc, transpose_success_2);
  tcase_add_test(tc, transpose_success_3);
  tcase_add_test(tc, transpose_bad_matrix_1);
  tcase_add_test(tc, transpose_bad_matrix_2);
  suite_add_tcase(s, tc);

  return s;
}