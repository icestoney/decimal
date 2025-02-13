#ifndef S21_DECIMAL_TESTS_H
#define S21_DECIMAL_TESTS_H

#include <check.h>
#include <stdio.h>

#include "../s21_decimal.h"

Suite *s21_add_tests(void);
Suite *s21_sub_tests(void);
Suite *s21_mul_tests(void);
Suite *s21_div_tests(void);

Suite *s21_comparison_tests(void);

Suite *s21_from_int_to_decimal_tests(void);
Suite *s21_from_decimal_to_int_tests(void);
Suite *s21_from_float_to_decimal_tests(void);
Suite *s21_from_decimal_to_float_tests(void);

Suite *s21_floor_tests(void);
Suite *s21_round_tests(void);
Suite *s21_truncate_tests(void);
Suite *s21_negate_tests(void);

void testcase_run(Suite *test);
void tests_run();

float Rand_R(float a, float b);

#endif