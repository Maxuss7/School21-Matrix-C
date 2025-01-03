#include "./s21_matrix_tests.h"

START_TEST(create_matrix_failed_malloc) {
  matrix_t result;
  int res = s21_create_matrix(999999999, 999999999, &result);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_matrix_success) {
  matrix_t result;
  int rows = 23, columns = 10;
  int res = s21_create_matrix(rows, columns, &result);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(result.rows, rows);
  ck_assert_int_eq(result.columns, columns);

  for (int i = 0; i < rows; i++) {
    ck_assert_ptr_nonnull(result.matrix[i]);
  }

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_matrix_incorrect_size) {
  matrix_t result;

  int res = s21_create_matrix(0, 3, &result);  // Ноль строк
  ck_assert_int_eq(res, INCORRECT_MATRIX);

  res = s21_create_matrix(3, 0, &result);  // Ноль столбцов
  ck_assert_int_eq(res, INCORRECT_MATRIX);

  res = s21_create_matrix(-3, 3, &result);  // Отрицательные строки
  ck_assert_int_eq(res, INCORRECT_MATRIX);

  res = s21_create_matrix(7, -1, &result);  // Отрицательные столбцы
  ck_assert_int_eq(res, INCORRECT_MATRIX);

  res = s21_create_matrix(-10, -4, &result);  // Отрицательные строки и столбцы
  ck_assert_int_eq(res, INCORRECT_MATRIX);

  res =
      s21_create_matrix(0, -2, &result);  // Ноль строк и отрицательные столбцы
  ck_assert_int_eq(res, INCORRECT_MATRIX);

  res = s21_create_matrix(0, -4,
                          &result);  // Ноль столбцов и отрицательные строки
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

Suite *get_suite_s21_create_matrix(void) {
  Suite *s = suite_create("\033[44m-=s21_create_matrix=-\033[0m");
  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, create_matrix_success);
  tcase_add_test(tc, create_matrix_incorrect_size);
  tcase_add_test(tc, create_matrix_failed_malloc);
  suite_add_tcase(s, tc);

  return s;
}