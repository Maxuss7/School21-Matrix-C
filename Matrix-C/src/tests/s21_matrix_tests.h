#ifndef SRC_S21_DECIMAL_TESTS_H
#define SRC_S21_DECIMAL_TESTS_H

#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

Suite *get_suite_s21_create_matrix(void);
Suite *get_suite_s21_remove_matrix(void);
Suite *get_suite_s21_sum_matrix(void);
Suite *get_suite_s21_sub_matrix(void);
Suite *get_suite_s21_eq_matrix(void);
Suite *get_suite_s21_mult_number(void);
Suite *get_suite_s21_mult_matrix(void);
Suite *get_suite_s21_transpose_matrix(void);
Suite *get_suite_s21_determinant(void);
Suite *get_suite_s21_calc_complements(void);
Suite *get_suite_s21_inverse_matrix(void);

#endif
