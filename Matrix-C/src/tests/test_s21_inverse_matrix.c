#include "./s21_matrix_tests.h"

START_TEST(inverse_2x2) {
  matrix_t A, result;
  int code = s21_create_matrix(2, 2, &A);

  if (code == OK) {
    A.matrix[0][0] = 4;
    A.matrix[0][1] = 7;
    A.matrix[1][0] = 2;
    A.matrix[1][1] = 6;

    int inv_code = s21_inverse_matrix(&A, &result);
    ck_assert_int_eq(inv_code, OK);
    ck_assert_double_eq_tol(result.matrix[0][0], 0.6, 1e-7);
    ck_assert_double_eq_tol(result.matrix[0][1], -0.7, 1e-7);
    ck_assert_double_eq_tol(result.matrix[1][0], -0.2, 1e-7);
    ck_assert_double_eq_tol(result.matrix[1][1], 0.4, 1e-7);
    s21_remove_matrix(&result);
    s21_remove_matrix(&A);
  }
}
END_TEST

START_TEST(inverse_3x3) {
  matrix_t A, result;
  int code = s21_create_matrix(3, 3, &A);

  if (code == OK) {
    // Исходная матрица A:
    A.matrix[0][0] = 2;
    A.matrix[0][1] = 5;
    A.matrix[0][2] = 7;
    A.matrix[1][0] = 6;
    A.matrix[1][1] = 3;
    A.matrix[1][2] = 4;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = -2;
    A.matrix[2][2] = -3;

    int inv_code = s21_inverse_matrix(&A, &result);
    ck_assert_int_eq(inv_code, OK);
    ck_assert_double_eq_tol(result.matrix[0][0], 1, 1e-7);
    ck_assert_double_eq_tol(result.matrix[0][1], -1, 1e-7);
    ck_assert_double_eq_tol(result.matrix[0][2], 1, 1e-7);
    ck_assert_double_eq_tol(result.matrix[1][0], -38, 1e-7);
    ck_assert_double_eq_tol(result.matrix[1][1], 41, 1e-7);
    ck_assert_double_eq_tol(result.matrix[1][2], -34, 1e-7);
    ck_assert_double_eq_tol(result.matrix[2][0], 27, 1e-7);
    ck_assert_double_eq_tol(result.matrix[2][1], -29, 1e-7);
    ck_assert_double_eq_tol(result.matrix[2][2], 24, 1e-7);
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_singular_matrix) {
  matrix_t A, result;
  int code = s21_create_matrix(2, 2, &A);

  if (code == OK) {
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[1][0] = 2;
    A.matrix[1][1] = 4;

    int inv_code = s21_inverse_matrix(&A, &result);

    ck_assert_int_eq(inv_code, CALCULATION_ERROR);
  }

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_readme_3x3) {
  matrix_t A, result;
  int code = s21_create_matrix(3, 3, &A);

  if (code == OK) {
    A.matrix[0][0] = 2;
    A.matrix[0][1] = 5;
    A.matrix[0][2] = 7;
    A.matrix[1][0] = 6;
    A.matrix[1][1] = 3;
    A.matrix[1][2] = 4;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = -2;
    A.matrix[2][2] = -3;

    int inv_code = s21_inverse_matrix(&A, &result);

    ck_assert_int_eq(inv_code, OK);
    ck_assert_double_eq_tol(result.matrix[0][0], 1, 1e-7);
    ck_assert_double_eq_tol(result.matrix[0][1], -1, 1e-7);
    ck_assert_double_eq_tol(result.matrix[0][2], 1, 1e-7);
    ck_assert_double_eq_tol(result.matrix[1][0], -38, 1e-7);
    ck_assert_double_eq_tol(result.matrix[1][1], 41, 1e-7);
    ck_assert_double_eq_tol(result.matrix[1][2], -34, 1e-7);
    ck_assert_double_eq_tol(result.matrix[2][0], 27, 1e-7);
    ck_assert_double_eq_tol(result.matrix[2][1], -29, 1e-7);
    ck_assert_double_eq_tol(result.matrix[2][2], 24, 1e-7);
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *get_suite_s21_inverse_matrix(void) {
  Suite *s = suite_create("\033[44m-=s21_inverse_matrix=-\033[0m");
  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, inverse_2x2);
  tcase_add_test(tc, inverse_3x3);
  tcase_add_test(tc, inverse_singular_matrix);
  tcase_add_test(tc, inverse_readme_3x3);

  suite_add_tcase(s, tc);

  return s;
}
