#include "./s21_matrix_tests.h"

START_TEST(mult_num_success_1) {
  matrix_t given;
  matrix_t result;
  matrix_t expected;
  int code1 = s21_create_matrix(5, 5, &given);
  int code2 = s21_create_matrix(5, 5, &expected);
  int mult_code;
  int eq_code;

  if (code1 == OK && code2 == OK) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        given.matrix[i][j] = 1.52;
        expected.matrix[i][j] = given.matrix[i][j] * 5;
      }
    }

    mult_code = s21_mult_number(&given, 5, &result);
    if (mult_code == OK) {
      eq_code = s21_eq_matrix(&result, &expected);
      s21_remove_matrix(&result);
    }
  }
  ck_assert_int_eq(mult_code, OK);
  ck_assert_int_eq(code1, OK);
  ck_assert_int_eq(code2, OK);
  ck_assert_int_eq(eq_code, SUCCESS);
  s21_remove_matrix(&given);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mult_num_success_2) {
  matrix_t given;
  matrix_t result;
  matrix_t expected;
  int code1 = s21_create_matrix(10, 100, &given);
  int code2 = s21_create_matrix(10, 100, &expected);
  int mult_code;
  int eq_code;

  if (code1 == OK && code2 == OK) {
    for (int i = 0; i < given.rows; i++) {
      for (int j = 0; j < given.columns; j++) {
        given.matrix[i][j] = 190414.14515151;
        expected.matrix[i][j] = given.matrix[i][j] * 222.123123;
      }
    }

    mult_code = s21_mult_number(&given, 222.123123, &result);
    if (mult_code == OK) {
      eq_code = s21_eq_matrix(&result, &expected);
    }
  }
  ck_assert_int_eq(mult_code, OK);
  ck_assert_int_eq(code1, OK);
  ck_assert_int_eq(code2, OK);
  ck_assert_int_eq(eq_code, SUCCESS);
  s21_remove_matrix(&given);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mult_num_fail_1) {
  matrix_t result;
  matrix_t expected;
  s21_create_matrix(10, 100, &expected);
  int mult_code;

  mult_code = s21_mult_number(NULL, 222.123123, &result);

  ck_assert_int_eq(mult_code, INCORRECT_MATRIX);

  s21_remove_matrix(&expected);
}
END_TEST

Suite *get_suite_s21_mult_number(void) {
  Suite *s = suite_create("\033[44m-=s21_mult_number=-\033[0m");
  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, mult_num_success_1);
  tcase_add_test(tc, mult_num_success_2);
  tcase_add_test(tc, mult_num_fail_1);

  suite_add_tcase(s, tc);

  return s;
}