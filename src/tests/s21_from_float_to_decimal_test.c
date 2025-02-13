#include "s21_decimal_tests.h"

START_TEST(float_to_decimal_1) {
  float a = 1234567890123456789012345678.0;
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{83886080, 1649500280, 66926065, 0}};
  int result = s21_from_float_to_decimal(a, &result_value);
  printf("FTD TEST 1\n");
  printf("err_code: %d\n", result);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);
  ck_assert_int_eq(s21_is_equal(expected_value, result_value), CO_TRUE);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(float_to_decimal_2) {
  float a = 123456789012345678901234567.8;
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{8388608, -1982533620, 6692606, 0}};
  int result = s21_from_float_to_decimal(a, &result_value);
  printf("FTD TEST 2\n");
  printf("err_code: %d\n", result);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);
  ck_assert_int_eq(s21_is_equal(expected_value, result_value), CO_TRUE);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(float_to_decimal_3) {
  float a = 22.14836E+03f;
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{2214836, 0, 0, 131072}};
  int result = s21_from_float_to_decimal(a, &result_value);
  printf("FTD TEST 3\n");
  printf("err_code: %d\n", result);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);
  ck_assert_int_eq(s21_is_equal(expected_value, result_value), CO_TRUE);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(float_to_decimal_4) {
  float a = 1234.5678901234567890123456780;
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{1234568, 0, 0, 196608}};
  int result = s21_from_float_to_decimal(a, &result_value);
  printf("FTD TEST 4\n");
  printf("err_code: %d\n", result);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);
  ck_assert_int_eq(s21_is_equal(expected_value, result_value), CO_TRUE);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(float_to_decimal_5) {
  float a = 1e-30;
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{0, 0, 0, 0}};
  int result = s21_from_float_to_decimal(a, &result_value);
  printf("FTD TEST 5\n");
  printf("err_code: %d\n", result);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);
  ck_assert_int_eq(s21_is_equal(expected_value, result_value), CO_TRUE);
  ck_assert_int_eq(result, CP_CONVERTATION_ERROR);
}
END_TEST

START_TEST(float_to_decimal_6) {
  float a = (float)(1.0 / 0.0);
  s21_decimal result_value = {0};
  int result = s21_from_float_to_decimal(a, &result_value);
  printf("FTD TEST 6\n");
  printf("err_code: %d\n", result);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  ck_assert_int_eq(result, CP_CONVERTATION_ERROR);
}
END_TEST

START_TEST(float_to_decimal_7) {
  float a = MAX_FLOAT_TO_CONVERT;
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{536870912, -1282231782, -137, 0}};
  int result = s21_from_float_to_decimal(a, &result_value);
  printf("FTD TEST 7\n");
  printf("err_code: %d\n", result);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);
  ck_assert_int_eq(s21_is_equal(expected_value, result_value), CO_TRUE);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(float_to_decimal_8) {
  float a = MIN_FLOAT_TO_CONVERT;
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{1, 0, 0, 1835008}};
  int result = s21_from_float_to_decimal(a, &result_value);
  printf("FTD TEST 8\n");
  printf("err_code: %d\n", result);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);
  ck_assert_int_eq(s21_is_equal(expected_value, result_value), CO_TRUE);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(float_to_decimal_9) {
  float a = MIN_FLOAT_TO_CONVERT / 10;
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{0, 0, 0, 0}};
  int result = s21_from_float_to_decimal(a, &result_value);
  printf("FTD TEST 9\n");
  printf("err_code: %d\n", result);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);
  ck_assert_int_eq(s21_is_equal(expected_value, result_value), CO_TRUE);
  ck_assert_int_eq(result, CP_CONVERTATION_ERROR);
}
END_TEST

START_TEST(float_to_decimal_10) {
  float a = MAX_FLOAT_TO_CONVERT * 10;
  s21_decimal result_value = {{123}};
  int result = s21_from_float_to_decimal(a, &result_value);
  printf("FTD TEST 10\n");
  printf("err_code: %d\n", result);
  printf("r: %u %u %u %u\n\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  ck_assert_int_eq(result, CP_CONVERTATION_ERROR);
}
END_TEST

START_TEST(float_to_decimal_11) {
  float value = 0.0;
  s21_decimal expected_value = {{0, 0, 0, 0}};
  s21_decimal result_value = {{0, 0, 0, 0}};
  int result = s21_from_float_to_decimal(value, &result_value);
  printf("FTD TEST 11\n");
  printf("err_code: %d\n", result);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);
  ck_assert_int_eq(s21_is_equal(expected_value, result_value), CO_TRUE);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(float_to_decimal_12) {
  float a = -(0.0);
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{0, 0, 0, 2147483648}};
  int result = s21_from_float_to_decimal(a, &result_value);
  printf("FTD TEST 12\n");
  printf("err_code: %d\n", result);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);
  ck_assert_int_eq(s21_is_equal(expected_value, result_value), CO_TRUE);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(float_to_decimal_13) {
  float a = -(0.0);
  int result = s21_from_float_to_decimal(a, NULL);
  printf("FTD TEST 13\n");
  printf("err_code: %d\n", result);
  ck_assert_int_eq(result, CP_CONVERTATION_ERROR);
}
END_TEST

START_TEST(float_to_decimal_14) {
  float a = 0.0 / 0.0;
  s21_decimal result_value = {0};
  int result = s21_from_float_to_decimal(a, &result_value);
  printf("FTD TEST 14\n");
  printf("err_code: %d\n", result);
  ck_assert_int_eq(result, CP_CONVERTATION_ERROR);
}
END_TEST

Suite *s21_from_float_to_decimal_tests(void) {
  Suite *suite = suite_create("s21_from_float_to_decimal_tests_suite");
  TCase *tcase = tcase_create("s21_from_float_to_decimal_tests_tcase");

  tcase_add_test(tcase, float_to_decimal_1);
  tcase_add_test(tcase, float_to_decimal_2);
  tcase_add_test(tcase, float_to_decimal_3);
  tcase_add_test(tcase, float_to_decimal_4);
  tcase_add_test(tcase, float_to_decimal_5);
  tcase_add_test(tcase, float_to_decimal_6);
  tcase_add_test(tcase, float_to_decimal_7);
  tcase_add_test(tcase, float_to_decimal_8);
  tcase_add_test(tcase, float_to_decimal_9);
  tcase_add_test(tcase, float_to_decimal_10);
  tcase_add_test(tcase, float_to_decimal_11);
  tcase_add_test(tcase, float_to_decimal_12);
  tcase_add_test(tcase, float_to_decimal_13);
  tcase_add_test(tcase, float_to_decimal_14);

  suite_add_tcase(suite, tcase);
  return suite;
}