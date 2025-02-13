#include "s21_decimal_tests.h"

START_TEST(s21_floor_test_1) {
  s21_decimal value_1 = {{49, 0, 0, 0}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{4, 0, 0, 0}};

  s21_set_exponent(&value_1, 1);

  int result = s21_floor(value_1, &result_value);
  printf("FLOOR TEST 1\n");
  printf("err_code: %d\n", result);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_floor_test_2) {
  s21_decimal value_1 = {{49, 0, 0, 0}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{49, 0, 0, 0}};

  int result = s21_floor(value_1, &result_value);
  printf("FLOOR TEST 2\n");
  printf("err_code: %d\n", result);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_floor_test_3) {
  s21_decimal value_1 = {{49, 0, 0, 0}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{0, 0, 0, 0}};

  s21_set_exponent(&value_1, 2);

  int result = s21_floor(value_1, &result_value);
  printf("FLOOR TEST 3\n");
  printf("err_code: %d\n", result);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_floor_test_4) {
  // 10.000000000000000000000000001
  s21_decimal value_1 = {{268435457, 1042612833, 542101086, 1769472}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{11, 0, 0, 0}};

  s21_set_sign_bit(&value_1, SIGN_NEGATIVE);
  s21_set_sign_bit(&expected_value, SIGN_NEGATIVE);

  int result = s21_floor(value_1, &result_value);
  printf("FLOOR TEST 4\n");
  printf("err_code: %d\n", result);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_floor_test_5) {
  // 0.7619047619047619047619047619
  s21_decimal value_1 = {{-1022611261, 180804925, 413029399, 1835008}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{1, 0, 0, 0}};

  s21_set_sign_bit(&value_1, SIGN_NEGATIVE);
  s21_set_sign_bit(&expected_value, SIGN_NEGATIVE);

  int result = s21_floor(value_1, &result_value);
  printf("FLOOR TEST 5\n");
  printf("err_code: %d\n", result);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_floor_test_6) {
  // 0.0333365548825952653334615905
  s21_decimal value_1 = {{276633441, 2634730587, 18071782, 1835008}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{1, 0, 0, 0}};

  s21_set_sign_bit(&value_1, SIGN_NEGATIVE);
  s21_set_sign_bit(&expected_value, SIGN_NEGATIVE);

  int result = s21_floor(value_1, &result_value);
  printf("FLOOR TEST 6\n");
  printf("err_code: %d\n", result);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_floor_test_7) {
  s21_decimal value_1 = {{49, 0, 0, 0}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{49, 0, 0, 0}};

  s21_set_sign_bit(&value_1, SIGN_NEGATIVE);
  s21_set_sign_bit(&expected_value, SIGN_NEGATIVE);

  int result = s21_floor(value_1, &result_value);
  printf("FLOOR TEST 7\n");
  printf("err_code: %d\n", result);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_floor_test_8) {
  s21_decimal value_1 = {{21, 0, 0, 0}};

  int result = s21_floor(value_1, NULL);
  printf("FLOOR TEST 8\n");
  printf("err_code: %d\n", result);

  ck_assert_int_eq(result, AF_CALCULATION_ERROR);
}
END_TEST

Suite *s21_floor_tests(void) {
  Suite *suite = suite_create("s21_floor_tests_suite");
  TCase *tcase = tcase_create("s21_floor_tests_tcase");

  tcase_add_test(tcase, s21_floor_test_1);
  tcase_add_test(tcase, s21_floor_test_2);
  tcase_add_test(tcase, s21_floor_test_3);
  tcase_add_test(tcase, s21_floor_test_4);
  tcase_add_test(tcase, s21_floor_test_5);
  tcase_add_test(tcase, s21_floor_test_6);
  tcase_add_test(tcase, s21_floor_test_7);
  tcase_add_test(tcase, s21_floor_test_8);

  suite_add_tcase(suite, tcase);
  return suite;
}