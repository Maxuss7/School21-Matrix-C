#include "./s21_matrix_tests.h"

START_TEST(remove_matrix_success_1) {
  matrix_t result;
  int rows = 5, columns = 5;
  int code = s21_create_matrix(rows, columns, &result);

  if (code == OK) {
    s21_remove_matrix(&result);
    ck_assert_ptr_null(result.matrix);
  }
}
END_TEST

START_TEST(remove_matrix_success_2) {
  matrix_t result;
  int rows = 100, columns = 90;
  int code = s21_create_matrix(rows, columns, &result);

  if (code == OK) {
    s21_remove_matrix(&result);
    ck_assert_ptr_null(result.matrix);
  }
}
END_TEST

START_TEST(remove_matrix_success_3) {
  matrix_t result;
  int rows = 1, columns = 300;
  int code = s21_create_matrix(rows, columns, &result);

  if (code == OK) {
    s21_remove_matrix(&result);
    ck_assert_ptr_null(result.matrix);
  }
}
END_TEST

START_TEST(remove_null_matrix_1) {
  matrix_t result;
  result.matrix = NULL;

  s21_remove_matrix(&result);
  ck_assert_ptr_null(result.matrix);
}
END_TEST

START_TEST(remove_null_matrix_2) {
  matrix_t result;
  result.matrix = NULL;

  s21_remove_matrix(NULL);
  ck_assert_ptr_null(result.matrix);
}
END_TEST

Suite *get_suite_s21_remove_matrix(void) {
  Suite *s = suite_create("\033[44m-=s21_remove_matrix=-\033[0m");
  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, remove_matrix_success_1);
  tcase_add_test(tc, remove_matrix_success_2);
  tcase_add_test(tc, remove_matrix_success_3);
  tcase_add_test(tc, remove_null_matrix_1);
  tcase_add_test(tc, remove_null_matrix_2);
  suite_add_tcase(s, tc);

  return s;
}