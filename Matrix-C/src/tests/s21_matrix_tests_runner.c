#include <stdlib.h>

#include "s21_matrix_tests.h"

int main() {
  int failed_tests = 0;

  Suite *s = get_suite_s21_create_matrix();
  SRunner *sr = srunner_create(s);

  srunner_add_suite(sr, get_suite_s21_remove_matrix());
  srunner_add_suite(sr, get_suite_s21_sum_matrix());
  srunner_add_suite(sr, get_suite_s21_sub_matrix());
  srunner_add_suite(sr, get_suite_s21_eq_matrix());
  srunner_add_suite(sr, get_suite_s21_mult_number());
  srunner_add_suite(sr, get_suite_s21_mult_matrix());
  srunner_add_suite(sr, get_suite_s21_transpose_matrix());
  srunner_add_suite(sr, get_suite_s21_determinant());
  srunner_add_suite(sr, get_suite_s21_calc_complements());
  srunner_add_suite(sr, get_suite_s21_inverse_matrix());

  srunner_run_all(sr, CK_VERBOSE);
  failed_tests = srunner_ntests_failed(sr);
  printf("=== FAILED TESTS: %d ===\n", failed_tests);

  srunner_free(sr);
  return (failed_tests == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
