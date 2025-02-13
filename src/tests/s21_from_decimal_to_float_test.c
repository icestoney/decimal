#include "s21_decimal_tests.h"

START_TEST(s21_from_decimal_to_float_test_1) {
  s21_decimal value = {{314, 0, 0, 131072}};
  float expected_value = 3.14;
  float result_value = 0;
  int result = s21_from_decimal_to_float(value, &result_value);
  printf("\nDTF TEST 1\n");
  printf("err_code: %d\n", result);
  printf("v : %u %u %u %u\n", value.bits[0], value.bits[1], value.bits[2],
         value.bits[3]);
  printf("r : %f\n", result_value);
  printf("ex: %f\n", expected_value);
  ck_assert_float_eq(expected_value, result_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_2) {
  s21_decimal value = {{0, 0, -256, 0}};
  float expected_value = MAX_FLOAT_TO_CONVERT;
  float result_value = 0;
  int result = s21_from_decimal_to_float(value, &result_value);
  printf("\nDTF TEST 2\n");
  printf("err_code: %d\n", result);
  printf("v : %u %u %u %u\n", value.bits[0], value.bits[1], value.bits[2],
         value.bits[3]);
  printf("r : %f\n", result_value);
  printf("ex: %f\n", expected_value);
  ck_assert_float_eq(expected_value, result_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_3) {
  s21_decimal value = {{1, 0, 0, 1835008}};
  float expected_value = MIN_FLOAT_TO_CONVERT;
  float result_value = 0;
  int result = s21_from_decimal_to_float(value, &result_value);
  printf("\nDTF TEST 3\n");
  printf("err_code: %d\n", result);
  printf("v : %u %u %u %u\n", value.bits[0], value.bits[1], value.bits[2],
         value.bits[3]);
  printf("r : %f\n", result_value);
  printf("ex: %f\n", expected_value);
  ck_assert_float_eq(expected_value, result_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_4) {
  s21_decimal value = {{1, 0, 0, 458752}};
  float expected_value = 1E-07;
  float result_value = 0;
  int result = s21_from_decimal_to_float(value, &result_value);
  printf("\nDTF TEST 4\n");
  printf("err_code: %d\n", result);
  printf("v : %u %u %u %u\n", value.bits[0], value.bits[1], value.bits[2],
         value.bits[3]);
  printf("r : %f\n", result_value);
  printf("ex: %f\n", expected_value);
  ck_assert_float_eq(expected_value, result_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_5) {
  s21_decimal value = {{1, 0, 0, -2147024896}};
  float expected_value = -1E-07;
  float result_value = 0;
  int result = s21_from_decimal_to_float(value, &result_value);
  printf("\nDTF TEST 5\n");
  printf("err_code: %d\n", result);
  printf("v : %u %u %u %u\n", value.bits[0], value.bits[1], value.bits[2],
         value.bits[3]);
  printf("r : %f\n", result_value);
  printf("ex: %f\n", expected_value);
  ck_assert_float_eq(expected_value, result_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_6) {
  s21_decimal value = {{100000101, 0, 0, 0}};
  float expected_value = 100000101.f;
  float result_value = 0;
  int result = s21_from_decimal_to_float(value, &result_value);
  printf("\nDTF TEST 6\n");
  printf("err_code: %d\n", result);
  printf("v : %u %u %u %u\n", value.bits[0], value.bits[1], value.bits[2],
         value.bits[3]);
  printf("r : %f\n", result_value);
  printf("ex: %f\n", expected_value);
  ck_assert_float_eq(expected_value, result_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_7) {
  s21_decimal value = {{100000101, 0, 0, -2147483648}};
  float expected_value = -100000101.f;
  float result_value = 0;
  int result = s21_from_decimal_to_float(value, &result_value);
  printf("\nDTF TEST 7\n");
  printf("err_code: %d\n", result);
  printf("v : %u %u %u %u\n", value.bits[0], value.bits[1], value.bits[2],
         value.bits[3]);
  printf("r : %f\n", result_value);
  printf("ex: %f\n", expected_value);
  ck_assert_float_eq(expected_value, result_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_8) {
  s21_decimal value = {0};
  int result = s21_from_decimal_to_float(value, NULL);
  printf("\nDTF TEST 8\n");
  printf("err_code: %d\n", result);
  ck_assert_int_eq(result, CP_CONVERTATION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_9) {
  s21_decimal value = {{1, 0, 0, 0}};
  float expected_value = 0;
  float result_value = 0;
  s21_set_exponent(&value, 29);
  int result = s21_from_decimal_to_float(value, &result_value);
  printf("\nDTF TEST 9\n");
  printf("err_code: %d\n", result);
  printf("v : %u %u %u %u\n", value.bits[0], value.bits[1], value.bits[2],
         value.bits[3]);
  printf("r : %f\n", result_value);
  printf("ex: %f\n", expected_value);
  ck_assert_float_eq(expected_value, result_value);
  ck_assert_int_eq(result, CP_CONVERTATION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_10) {
  s21_decimal value = {{1, 0, 0, 393216}};
  float expected_value = 1E-06;
  float result_value = 0;
  int result = s21_from_decimal_to_float(value, &result_value);
  printf("\nDTF TEST 10\n");
  printf("err_code: %d\n", result);
  printf("v : %u %u %u %u\n", value.bits[0], value.bits[1], value.bits[2],
         value.bits[3]);
  printf("r : %f\n", result_value);
  printf("ex: %f\n", expected_value);
  ck_assert_float_eq(expected_value, result_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_11) {
  s21_decimal value = {{1, 0, 0, -2147090432}};
  float expected_value = -1E-06;
  float result_value = 0;
  int result = s21_from_decimal_to_float(value, &result_value);
  printf("\nDTF TEST 11\n");
  printf("err_code: %d\n", result);
  printf("v : %u %u %u %u\n", value.bits[0], value.bits[1], value.bits[2],
         value.bits[3]);
  printf("r : %f\n", result_value);
  printf("ex: %f\n", expected_value);
  ck_assert_float_eq(expected_value, result_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_12) {
  s21_decimal value = {{-1, -1, -1, 0}};
  float expected_value = 79228162514264337593543950335.f;
  float result_value = 0;
  int result = s21_from_decimal_to_float(value, &result_value);
  printf("\nDTF TEST 12\n");
  printf("err_code: %d\n", result);
  printf("v : %u %u %u %u\n", value.bits[0], value.bits[1], value.bits[2],
         value.bits[3]);
  printf("r : %f\n", result_value);
  printf("ex: %f\n\n", expected_value);
  ck_assert_float_eq(expected_value, result_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

Suite *s21_from_decimal_to_float_tests(void) {
  Suite *suite = suite_create("s21_from_decimal_to_float_tests_suite");
  TCase *tcase = tcase_create("s21_from_decimal_to_float_tests_tcase");

  tcase_add_test(tcase, s21_from_decimal_to_float_test_1);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_2);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_3);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_4);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_5);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_6);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_7);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_8);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_9);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_10);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_11);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_12);

  suite_add_tcase(suite, tcase);
  return suite;
}