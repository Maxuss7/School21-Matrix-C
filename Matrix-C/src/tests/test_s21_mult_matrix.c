#include "./s21_matrix_tests.h"

void print_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      printf("%lf ", A->matrix[i][j]);
    }
    printf("\n");
  }
}

START_TEST(mult_success_1) {
  matrix_t A, B, result, expected;

  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 7;
  B.matrix[0][1] = 8;
  B.matrix[1][0] = 9;
  B.matrix[1][1] = 10;
  B.matrix[2][0] = 11;
  B.matrix[2][1] = 12;

  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 58;
  expected.matrix[0][1] = 64;
  expected.matrix[1][0] = 139;
  expected.matrix[1][1] = 154;

  int status = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status, OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mult_success_2) {
  matrix_t A, B, result, expected;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.5;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.5;

  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 7.5;
  B.matrix[1][1] = 8.5;

  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 22.5;
  expected.matrix[0][1] = 26.0;
  expected.matrix[1][0] = 48.75;
  expected.matrix[1][1] = 56.25;

  int status = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mult_success_3) {
  matrix_t A, B, result, expected;

  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 5.0;
  A.matrix[2][0] = 3.0;
  A.matrix[2][1] = 6.0;

  s21_create_matrix(2, 3, &B);
  B.matrix[0][0] = 7.0;
  B.matrix[0][1] = 8.0;
  B.matrix[0][2] = 9.0;
  B.matrix[1][0] = 10.0;
  B.matrix[1][1] = 11.0;
  B.matrix[1][2] = 12.0;

  s21_create_matrix(3, 3, &expected);
  expected.matrix[0][0] = 47.0;
  expected.matrix[0][1] = 52.0;
  expected.matrix[0][2] = 57.0;
  expected.matrix[1][0] = 64.0;
  expected.matrix[1][1] = 71.0;
  expected.matrix[1][2] = 78.0;
  expected.matrix[2][0] = 81.0;
  expected.matrix[2][1] = 90.0;
  expected.matrix[2][2] = 99.0;

  int status = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mult_success_4) {
  matrix_t A, B, result, expected;

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.1234567;
  A.matrix[0][1] = 2.3456789;
  A.matrix[1][0] = 3.9876543;
  A.matrix[1][1] = 4.7654321;

  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 5.8765432;
  B.matrix[0][1] = 6.6543210;
  B.matrix[1][0] = 7.4321098;
  B.matrix[1][1] = 8.1234567;

  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 1.1234567 * 5.8765432 + 2.3456789 * 7.4321098;
  expected.matrix[0][1] = 1.1234567 * 6.6543210 + 2.3456789 * 8.1234567;
  expected.matrix[1][0] = 3.9876543 * 5.8765432 + 4.7654321 * 7.4321098;
  expected.matrix[1][1] = 3.9876543 * 6.6543210 + 4.7654321 * 8.1234567;

  int status = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mult_null_1) {
  matrix_t B, result;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 10;

  int status = s21_mult_matrix(NULL, &B, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_null_2) {
  matrix_t A, result;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 10;
  int status = s21_mult_matrix(&A, NULL, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_null_3) {
  matrix_t result;

  int status = s21_mult_matrix(NULL, NULL, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_null_4) {
  matrix_t A, B, result;
  A.matrix = NULL;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 10.123;

  int status = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_null_5) {
  matrix_t A, B, result;
  B.matrix = NULL;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 10.123;

  int status = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_bad_rows_cols_1) {
  matrix_t A, B, result;
  A.rows = -1;
  A.matrix = NULL;
  A.columns = -1;
  B.rows = -1;
  B.matrix = NULL;
  B.columns = -1;

  int status = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_bad_rows_cols_2) {
  matrix_t A, B, result;
  A.rows = 4;
  A.matrix = NULL;
  A.columns = -1;
  B.rows = -1;
  B.matrix = NULL;
  B.columns = -1;

  int status = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status, INCORRECT_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_bad_rows_cols_3) {
  matrix_t A, B, result;

  s21_create_matrix(2, 1, &A);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 3;

  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 7;
  B.matrix[0][1] = 8;
  B.matrix[1][0] = 9;
  B.matrix[1][1] = 10;
  B.matrix[2][0] = 11;
  B.matrix[2][1] = 12;

  int status = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *get_suite_s21_mult_matrix(void) {
  Suite *s = suite_create("\033[44m-=s21_mult_matrix=-\033[0m");
  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, mult_success_1);
  tcase_add_test(tc, mult_success_2);
  tcase_add_test(tc, mult_success_3);
  tcase_add_test(tc, mult_success_4);
  tcase_add_test(tc, mult_null_1);
  tcase_add_test(tc, mult_null_2);
  tcase_add_test(tc, mult_null_3);
  tcase_add_test(tc, mult_null_4);
  tcase_add_test(tc, mult_null_5);
  tcase_add_test(tc, mult_bad_rows_cols_1);
  tcase_add_test(tc, mult_bad_rows_cols_2);
  tcase_add_test(tc, mult_bad_rows_cols_3);

  suite_add_tcase(s, tc);

  return s;
}