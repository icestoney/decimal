#include "s21_decimal_tests.h"

int main() {
  tests_run();
  return 0;
}

void tests_run() {
  Suite *tests_list[] = {s21_add_tests(),
                         s21_sub_tests(),
                         s21_mul_tests(),
                         s21_div_tests(),
                         s21_comparison_tests(),
                         s21_from_decimal_to_float_tests(),
                         s21_from_decimal_to_int_tests(),
                         s21_from_float_to_decimal_tests(),
                         s21_from_int_to_decimal_tests(),
                         s21_floor_tests(),
                         s21_round_tests(),
                         s21_truncate_tests(),
                         s21_negate_tests(),
                         NULL};

  for (Suite **current_test = tests_list; *current_test != NULL;
       current_test++) {
    putchar('\n');
    testcase_run(*current_test);
  }
}

void testcase_run(Suite *test) {
  SRunner *srunner = srunner_create(test);
  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_NORMAL);
  srunner_free(srunner);
}

float Rand_R(float a, float b) {
  float m = (float)rand() / RAND_MAX;
  float num = a + m * (b - a);
  return num;
}