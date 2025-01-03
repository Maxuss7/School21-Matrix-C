#include "./s21_matrix_tests.h"

START_TEST(complements_2x2) {
  matrix_t A, result;
  int code = s21_create_matrix(2, 2, &A);

  if (code == OK) {
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[1][0] = 3;
    A.matrix[1][1] = 4;

    int comp_code = s21_calc_complements(&A, &result);

    ck_assert_int_eq(comp_code, OK);
    ck_assert_double_eq(result.matrix[0][0], 4);
    ck_assert_double_eq(result.matrix[0][1], -3);
    ck_assert_double_eq(result.matrix[1][0], -2);
    ck_assert_double_eq(result.matrix[1][1], 1);
    s21_remove_matrix(&A);
  }
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_3x3) {
  matrix_t A, result;
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

    int comp_code = s21_calc_complements(&A, &result);

    ck_assert_int_eq(comp_code, OK);
    ck_assert_double_eq(result.matrix[0][0], 24);
    ck_assert_double_eq(result.matrix[0][1], 5);
    ck_assert_double_eq(result.matrix[0][2], -4);
    ck_assert_double_eq(result.matrix[1][0], -12);
    ck_assert_double_eq(result.matrix[1][1], 3);
    ck_assert_double_eq(result.matrix[1][2], 2);
    ck_assert_double_eq(result.matrix[2][0], -2);
    ck_assert_double_eq(result.matrix[2][1], -5);
    ck_assert_double_eq(result.matrix[2][2], 4);
    s21_remove_matrix(&A);
  }
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_incorrect_matrix) {
  matrix_t A, result;
  int code = s21_create_matrix(2, 3, &A);

  if (code == OK) {
    int comp_code = s21_calc_complements(&A, &result);
    s21_remove_matrix(&A);
    ck_assert_int_eq(comp_code, CALCULATION_ERROR);
  }
}
END_TEST

START_TEST(complements_incorrect_matrix2) {
  matrix_t result;
  int comp_code = s21_calc_complements(NULL, &result);
  ck_assert_int_eq(comp_code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(complements_large_matrix) {
  matrix_t A, result;
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

    int comp_code = s21_calc_complements(&A, &result);

    ck_assert_int_eq(comp_code, OK);
    ck_assert_double_eq(result.matrix[0][0], 0);
    ck_assert_double_eq(result.matrix[0][1], 0);
    ck_assert_double_eq(result.matrix[0][2], 0);
    ck_assert_double_eq(result.matrix[0][3], 0);
    ck_assert_double_eq(result.matrix[1][0], 0);
    ck_assert_double_eq(result.matrix[1][1], 0);
    ck_assert_double_eq(result.matrix[1][2], 0);
    ck_assert_double_eq(result.matrix[1][3], 0);
    ck_assert_double_eq(result.matrix[2][0], 0);
    ck_assert_double_eq(result.matrix[2][1], 0);
    ck_assert_double_eq(result.matrix[2][2], 0);
    ck_assert_double_eq(result.matrix[2][3], 0);
    ck_assert_double_eq(result.matrix[3][0], 0);
    ck_assert_double_eq(result.matrix[3][1], 0);
    ck_assert_double_eq(result.matrix[3][2], 0);
    ck_assert_double_eq(result.matrix[3][3], 0);
    s21_remove_matrix(&A);
  }
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_readme_3x3) {
  matrix_t A, result;
  int code = s21_create_matrix(3, 3, &A);

  if (code == OK) {
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;
    A.matrix[1][0] = 0;
    A.matrix[1][1] = 4;
    A.matrix[1][2] = 2;
    A.matrix[2][0] = 5;
    A.matrix[2][1] = 2;
    A.matrix[2][2] = 1;

    int comp_code = s21_calc_complements(&A, &result);

    ck_assert_int_eq(comp_code, OK);

    ck_assert_double_eq(result.matrix[0][0], 0);
    ck_assert_double_eq(result.matrix[0][1], 10);
    ck_assert_double_eq(result.matrix[0][2], -20);
    ck_assert_double_eq(result.matrix[1][0], 4);
    ck_assert_double_eq(result.matrix[1][1], -14);
    ck_assert_double_eq(result.matrix[1][2], 8);
    ck_assert_double_eq(result.matrix[2][0], -8);
    ck_assert_double_eq(result.matrix[2][1], -2);
    ck_assert_double_eq(result.matrix[2][2], 4);
    s21_remove_matrix(&A);
  }

  s21_remove_matrix(&result);
}
END_TEST

Suite *get_suite_s21_calc_complements(void) {
  Suite *s = suite_create("\033[44m-=s21_calc_complements=-\033[0m");
  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, complements_2x2);
  tcase_add_test(tc, complements_3x3);
  tcase_add_test(tc, complements_incorrect_matrix);
  tcase_add_test(tc, complements_incorrect_matrix2);
  tcase_add_test(tc, complements_large_matrix);
  tcase_add_test(tc, complements_readme_3x3);

  suite_add_tcase(s, tc);

  return s;
}
