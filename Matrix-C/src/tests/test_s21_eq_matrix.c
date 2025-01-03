#include "./s21_matrix_tests.h"

START_TEST(eq_success_1) {
  matrix_t A;
  matrix_t B;
  int code1 = s21_create_matrix(3, 3, &A);
  int code2 = s21_create_matrix(3, 3, &B);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = 5.123321;
      B.matrix[i][j] = 5.123321;
    }
  }

  int result_code;
  if (code1 == OK && code2 == OK) {
    result_code = s21_eq_matrix(&A, &B);
  }
  ck_assert_int_eq(result_code, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_success_2) {
  matrix_t A;
  matrix_t B;
  int code1 = s21_create_matrix(5, 10, &A);
  int code2 = s21_create_matrix(5, 10, &B);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      A.matrix[i][j] = 10000;
      B.matrix[i][j] = 10000;
    }
  }

  int result_code;
  if (code1 == OK && code2 == OK) {
    result_code = s21_eq_matrix(&A, &B);
  }
  ck_assert_int_eq(result_code, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_failure_1) {
  matrix_t A;
  matrix_t B;
  int code1 = s21_create_matrix(5, 10, &A);
  int code2 = s21_create_matrix(5, 10, &B);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      A.matrix[i][j] = 10000;
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      B.matrix[i][j] = 100;
    }
  }

  int result_code;
  if (code1 == OK && code2 == OK) {
    result_code = s21_eq_matrix(&A, &B);
  }

  ck_assert_int_eq(result_code, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_bad_matrix_1) {
  matrix_t A;
  matrix_t B;
  A.matrix = NULL;
  s21_create_matrix(5, 10, &B);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      B.matrix[i][j] = 100;
    }
  }

  int result_code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result_code, FAILURE);

  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_bad_matrix_2) {
  matrix_t A;
  matrix_t B;
  B.matrix = NULL;
  s21_create_matrix(5, 10, &A);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      A.matrix[i][j] = 100;
    }
  }

  int result_code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result_code, FAILURE);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(eq_bad_rows_cols_1) {
  matrix_t A;
  matrix_t B;
  int code1 = s21_create_matrix(3, 10, &A);
  int code2 = s21_create_matrix(5, 10, &B);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 10; j++) {
      A.matrix[i][j] = 10000;
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      B.matrix[i][j] = 100;
    }
  }

  int result_code;
  if (code1 == OK && code2 == OK) {
    result_code = s21_eq_matrix(&A, &B);
  }

  ck_assert_int_eq(result_code, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_bad_rows_cols_2) {
  matrix_t A;
  matrix_t B;
  int code1 = s21_create_matrix(3, 7, &A);
  int code2 = s21_create_matrix(5, 10, &B);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 7; j++) {
      A.matrix[i][j] = 10000;
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      B.matrix[i][j] = 100;
    }
  }

  int result_code;
  if (code1 == OK && code2 == OK) {
    result_code = s21_eq_matrix(&A, &B);
  }

  ck_assert_int_eq(result_code, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_bad_rows_cols_3) {
  matrix_t A;
  matrix_t B;
  int code1 = s21_create_matrix(1, 7, &A);
  int code2 = s21_create_matrix(1, 10, &B);

  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 7; j++) {
      A.matrix[i][j] = 10000;
    }
  }

  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 10; j++) {
      B.matrix[i][j] = 100;
    }
  }

  int result_code;
  if (code1 == OK && code2 == OK) {
    result_code = s21_eq_matrix(&A, &B);
  }

  ck_assert_int_eq(result_code, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(correct_eq_double_1) {
  matrix_t A;
  matrix_t B;
  int code1 = s21_create_matrix(5, 10, &A);
  int code2 = s21_create_matrix(5, 10, &B);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      A.matrix[i][j] = 1.12345678;
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      B.matrix[i][j] = 1.123456789;
    }
  }

  int result_code;
  if (code1 == OK && code2 == OK) {
    result_code = s21_eq_matrix(&A, &B);
  }

  ck_assert_int_eq(result_code, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(correct_eq_double_2) {
  matrix_t A;
  matrix_t B;
  int code1 = s21_create_matrix(5, 10, &A);
  int code2 = s21_create_matrix(5, 10, &B);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      A.matrix[i][j] = 1.12345679999;
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      B.matrix[i][j] = 1.1234567;
    }
  }

  int result_code;
  if (code1 == OK && code2 == OK) {
    result_code = s21_eq_matrix(&A, &B);
  }

  ck_assert_int_eq(result_code, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(incorrect_eq_double_1) {
  matrix_t A;
  matrix_t B;
  int code1 = s21_create_matrix(5, 10, &A);
  int code2 = s21_create_matrix(5, 10, &B);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      A.matrix[i][j] = 1.123456;
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      B.matrix[i][j] = 1.1234567;
    }
  }

  int result_code;
  if (code1 == OK && code2 == OK) {
    result_code = s21_eq_matrix(&A, &B);
  }

  ck_assert_int_eq(result_code, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *get_suite_s21_eq_matrix(void) {
  Suite *s = suite_create("\033[44m-=s21_eq_matrix=-\033[0m");
  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, eq_success_1);
  tcase_add_test(tc, eq_success_2);
  tcase_add_test(tc, eq_failure_1);
  tcase_add_test(tc, eq_bad_matrix_1);
  tcase_add_test(tc, eq_bad_matrix_2);
  tcase_add_test(tc, eq_bad_rows_cols_1);
  tcase_add_test(tc, eq_bad_rows_cols_2);
  tcase_add_test(tc, eq_bad_rows_cols_3);
  tcase_add_test(tc, correct_eq_double_1);
  tcase_add_test(tc, correct_eq_double_2);
  tcase_add_test(tc, incorrect_eq_double_1);

  suite_add_tcase(s, tc);

  return s;
}