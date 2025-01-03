#include "./s21_matrix_tests.h"

START_TEST(normal_sizes_1) {
  matrix_t m1;
  matrix_t m2;
  matrix_t res;

  s21_create_matrix(3, 3, &m1);
  s21_create_matrix(3, 3, &m2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      m1.matrix[i][j] = 1;
      m2.matrix[i][j] = 1;
    }
  }

  int result_code = s21_sum_matrix(&m1, &m2, &res);

  ck_assert_int_eq(result_code, OK);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      double expected = m1.matrix[i][j] + m2.matrix[i][j];
      ck_assert_double_eq(res.matrix[i][j], expected);
    }
  }

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(normal_sizes_2) {
  matrix_t m1;
  matrix_t m2;
  matrix_t res;

  s21_create_matrix(9, 10, &m1);
  s21_create_matrix(9, 10, &m2);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 10; j++) {
      m1.matrix[i][j] = 9.0123;
      m2.matrix[i][j] = 124;
    }
  }

  int result_code = s21_sum_matrix(&m1, &m2, &res);

  ck_assert_int_eq(result_code, OK);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 10; j++) {
      double expected = m1.matrix[i][j] + m2.matrix[i][j];
      ck_assert_double_eq(res.matrix[i][j], expected);
    }
  }

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(normal_sizes_3) {
  matrix_t m1;
  matrix_t m2;
  matrix_t res;

  s21_create_matrix(1, 1, &m1);
  s21_create_matrix(1, 1, &m2);

  m1.matrix[0][0] = 123.123;
  m2.matrix[0][0] = 10000.10241412;

  int result_code = s21_sum_matrix(&m1, &m2, &res);

  ck_assert_int_eq(result_code, OK);

  double expected = m1.matrix[0][0] + m2.matrix[0][0];
  ck_assert_double_eq(res.matrix[0][0], expected);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(weird_sizes_1) {
  matrix_t m1;
  matrix_t m2;
  matrix_t res;

  s21_create_matrix(4, 3, &m1);
  s21_create_matrix(3, 3, &m2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      m1.matrix[i][j] = 1;
      m2.matrix[i][j] = 1;
    }
  }

  int result_code = s21_sum_matrix(&m1, &m2, &res);

  ck_assert_int_eq(result_code, CALCULATION_ERROR);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(weird_sizes_2) {
  matrix_t m1;
  matrix_t m2;
  matrix_t res;

  m1.matrix = NULL;
  s21_create_matrix(3, 3, &m2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      m2.matrix[i][j] = 1;
    }
  }

  int result_code = s21_sum_matrix(&m1, &m2, &res);

  ck_assert_int_eq(result_code, INCORRECT_MATRIX);

  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(weird_sizes_3) {
  matrix_t m1;
  matrix_t m2;
  matrix_t res;

  s21_create_matrix(3, 4, &m1);
  s21_create_matrix(3, 3, &m2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      m1.matrix[i][j] = 1;
      m2.matrix[i][j] = 1;
    }
  }

  int result_code = s21_sum_matrix(&m1, &m2, &res);

  ck_assert_int_eq(result_code, CALCULATION_ERROR);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(weird_sizes_4) {
  matrix_t m1;
  matrix_t m2;
  matrix_t res;

  s21_create_matrix(4, 4, &m1);
  s21_create_matrix(3, 3, &m2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      m1.matrix[i][j] = 1;
      m2.matrix[i][j] = 1;
    }
  }

  int result_code = s21_sum_matrix(&m1, &m2, &res);

  ck_assert_int_eq(result_code, CALCULATION_ERROR);

  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(weird_sizes_5) {
  matrix_t m1;
  matrix_t m2;
  matrix_t res;

  m2.matrix = NULL;
  s21_create_matrix(3, 3, &m1);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      m1.matrix[i][j] = 1;
    }
  }

  int result_code = s21_sum_matrix(&m1, &m2, &res);

  ck_assert_int_eq(result_code, INCORRECT_MATRIX);

  s21_remove_matrix(&m1);
}
END_TEST

Suite *get_suite_s21_sum_matrix(void) {
  Suite *s = suite_create("\033[44m-=s21_sum_matrix=-\033[0m");
  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, normal_sizes_1);
  tcase_add_test(tc, normal_sizes_2);
  tcase_add_test(tc, normal_sizes_3);
  tcase_add_test(tc, weird_sizes_1);
  tcase_add_test(tc, weird_sizes_2);
  tcase_add_test(tc, weird_sizes_3);
  tcase_add_test(tc, weird_sizes_4);
  tcase_add_test(tc, weird_sizes_5);
  suite_add_tcase(s, tc);

  return s;
}