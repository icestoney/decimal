#include "s21_decimal_tests.h"

START_TEST(s21_negate_test_1) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal expected_value = {{10, 0, 0, -2147483648}};
  s21_decimal result_value = {0};

  int result = s21_negate(value_1, &result_value);
  printf("NEGATE TEST 1\n");
  printf("err_code: %d\n", result);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("r : %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_negate_test_2) {
  s21_decimal value_1 = {{10, 0, 0, -2147483648}};
  s21_decimal expected_value = {{10, 0, 0, 0}};
  s21_decimal result_value = {0};

  int result = s21_negate(value_1, &result_value);
  printf("NEGATE TEST 2\n");
  printf("err_code: %d\n", result);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("r : %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_negate_test_3) {
  s21_decimal value_1 = {{1610949695, -518105259, 54, -2146172928}};
  s21_decimal expected_value = {{1610949695, -518105259, 54, 1310720}};
  s21_decimal result_value = {0};

  int result = s21_negate(value_1, &result_value);
  printf("NEGATE TEST 3\n");
  printf("err_code: %d\n", result);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("r : %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_negate_test_4) {
  s21_decimal value_1 = {{1610949695, -518105259, 54, 1310720}};
  s21_decimal expected_value = {{1610949695, -518105259, 54, -2146172928}};
  s21_decimal result_value = {0};

  int result = s21_negate(value_1, &result_value);
  printf("NEGATE TEST 4\n");
  printf("err_code: %d\n", result);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("r : %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_negate_test_5) {
  s21_decimal value_1 = {{21, 0, 0, 0}};

  int result = s21_negate(value_1, NULL);
  printf("NEGATE TEST 5\n");
  printf("err_code: %d\n\n", result);

  ck_assert_int_eq(result, AF_CALCULATION_ERROR);
}
END_TEST

Suite *s21_negate_tests(void) {
  Suite *suite = suite_create("s21_negate_tests_suite");
  TCase *tcase = tcase_create("s21_negate_tests_tcase");

  tcase_add_test(tcase, s21_negate_test_1);
  tcase_add_test(tcase, s21_negate_test_2);
  tcase_add_test(tcase, s21_negate_test_3);
  tcase_add_test(tcase, s21_negate_test_4);
  tcase_add_test(tcase, s21_negate_test_5);

  suite_add_tcase(suite, tcase);
  return suite;
}