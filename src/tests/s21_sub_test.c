#include "s21_decimal_tests.h"

START_TEST(s21_sub_test_1) {
  s21_decimal value_1 = {.bits = {10}};
  s21_decimal value_2 = {.bits = {10}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {.bits = {0}};

  int result = s21_sub(value_1, value_2, &result_value);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("v2: %u %u %u %u\n", value_2.bits[0], value_2.bits[1], value_2.bits[2],
         value_2.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_sub_test_2) {
  s21_decimal value_1 = {.bits = {10}};
  s21_decimal value_2 = {.bits = {10}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {.bits = {20}};

  s21_set_sign_bit(&expected_value, SIGN_NEGATIVE);
  s21_set_sign_bit(&value_1, SIGN_NEGATIVE);

  int result = s21_sub(value_1, value_2, &result_value);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("v2: %u %u %u %u\n", value_2.bits[0], value_2.bits[1], value_2.bits[2],
         value_2.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_sub_test_3) {
  s21_decimal value_1 = {.bits = {10}};
  s21_decimal value_2 = {.bits = {10}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {.bits = {20}};

  s21_set_sign_bit(&value_2, SIGN_NEGATIVE);

  int result = s21_sub(value_1, value_2, &result_value);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("v2: %u %u %u %u\n", value_2.bits[0], value_2.bits[1], value_2.bits[2],
         value_2.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_sub_test_4) {
  s21_decimal value_1 = {{10, 20, 30, 0}};
  s21_decimal value_2 = {{40, 50, 60, 0}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{400000001, 500000002, 600000003, 917504}};

  s21_set_exponent(&value_1, 15);
  s21_set_exponent(&value_2, 7);
  s21_set_sign_bit(&value_2, SIGN_NEGATIVE);

  int result = s21_sub(value_1, value_2, &result_value);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("v2: %u %u %u %u\n", value_2.bits[0], value_2.bits[1], value_2.bits[2],
         value_2.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_sub_test_5) {
  s21_decimal value_1 = {{10, 20, 30, 0}};
  s21_decimal value_2 = {{40, 50, 60, 0}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{50, 70, 90, 0}};

  s21_set_exponent(&value_1, 15);
  s21_set_exponent(&value_2, 15);
  s21_set_sign_bit(&value_1, SIGN_NEGATIVE);
  s21_set_exponent(&expected_value, 15);
  s21_set_sign_bit(&expected_value, SIGN_NEGATIVE);

  int result = s21_sub(value_1, value_2, &result_value);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("v2: %u %u %u %u\n", value_2.bits[0], value_2.bits[1], value_2.bits[2],
         value_2.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_sub_test_6) {
  s21_decimal value_1 = {{10, 20, 30, 0}};
  s21_decimal value_2 = {{40, 50, 60, 0}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{50, 70, 90, 0}};

  s21_set_exponent(&value_1, 15);
  s21_set_exponent(&value_2, 15);
  s21_set_sign_bit(&value_2, SIGN_NEGATIVE);
  s21_set_exponent(&expected_value, 15);

  int result = s21_sub(value_1, value_2, &result_value);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("v2: %u %u %u %u\n", value_2.bits[0], value_2.bits[1], value_2.bits[2],
         value_2.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_sub_test_7) {
  s21_decimal value_1 = {{10, 20, 30, 0}};
  s21_decimal value_2 = {{11, 20, 30, 0}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{0, 0, 0, 0}};

  s21_set_sign_bit(&expected_value, SIGN_NEGATIVE);
  s21_set_exponent(&value_1, 29);
  s21_set_exponent(&value_2, 29);

  int result = s21_sub(value_1, value_2, &result_value);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("v2: %u %u %u %u\n", value_2.bits[0], value_2.bits[1], value_2.bits[2],
         value_2.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, AO_SMALL_NUMBER);
}
END_TEST

START_TEST(s21_sub_test_8) {
  s21_decimal value_1 = {{10, 20, 30, 0}};
  s21_decimal value_2 = {{40, 50, 60, 0}};

  s21_set_exponent(&value_1, 29);
  s21_set_exponent(&value_2, 31);

  int result = s21_sub(value_1, value_2, NULL);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("v2: %u %u %u %u\n", value_2.bits[0], value_2.bits[1], value_2.bits[2],
         value_2.bits[3]);

  ck_assert_int_eq(result, AF_CALCULATION_ERROR);
}
END_TEST

Suite *s21_sub_tests(void) {
  Suite *suite = suite_create("s21_sub_tests_suite");
  TCase *tcase = tcase_create("s21_sub_tests_tcase");

  tcase_add_test(tcase, s21_sub_test_1);
  tcase_add_test(tcase, s21_sub_test_2);
  tcase_add_test(tcase, s21_sub_test_3);
  tcase_add_test(tcase, s21_sub_test_4);
  tcase_add_test(tcase, s21_sub_test_5);
  tcase_add_test(tcase, s21_sub_test_6);
  tcase_add_test(tcase, s21_sub_test_7);
  tcase_add_test(tcase, s21_sub_test_8);

  suite_add_tcase(suite, tcase);
  return suite;
}