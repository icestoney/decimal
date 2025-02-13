#include "s21_decimal_tests.h"

START_TEST(s21_add_test_1) {
  s21_decimal value_1 = {.bits = {10}};
  s21_decimal value_2 = {.bits = {10}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {.bits = {20}};

  int result = s21_add(value_1, value_2, &result_value);
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

START_TEST(s21_add_test_2) {
  s21_decimal value_1 = {.bits = {10}};
  s21_decimal value_2 = {.bits = {10}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {0};

  s21_set_sign_bit(&value_1, SIGN_NEGATIVE);
  int result = s21_add(value_1, value_2, &result_value);
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

START_TEST(s21_add_test_3) {
  s21_decimal value_1 = {.bits = {10}};
  s21_decimal value_2 = {.bits = {10}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {0};

  s21_set_sign_bit(&value_2, SIGN_NEGATIVE);
  int result = s21_add(value_1, value_2, &result_value);
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

START_TEST(s21_add_test_4) {
  s21_decimal value_1 = {{10, 20, 30, 0}};
  s21_decimal value_2 = {{40, 50, 60, 0}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{400000001, 500000002, 600000003, 917504}};

  s21_set_exponent(&value_1, 15);
  s21_set_exponent(&value_2, 7);

  int result = s21_add(value_1, value_2, &result_value);
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

START_TEST(s21_add_test_5) {
  s21_decimal value_1 = {{10, 20, 30, 0}};
  s21_decimal value_2 = {{40, 50, 60, 0}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{30, 30, 30, 983040}};

  s21_set_exponent(&value_1, 15);
  s21_set_exponent(&value_2, 15);
  s21_set_sign_bit(&value_1, SIGN_NEGATIVE);

  int result = s21_add(value_1, value_2, &result_value);
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

START_TEST(s21_add_test_6) {
  s21_decimal value_1 = {{10, 20, 30, 0}};
  s21_decimal value_2 = {{40, 50, 60, 0}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{30, 30, 30, 2148466688}};

  s21_set_exponent(&value_1, 15);
  s21_set_exponent(&value_2, 15);
  s21_set_sign_bit(&value_2, SIGN_NEGATIVE);

  int result = s21_add(value_1, value_2, &result_value);
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

START_TEST(s21_add_test_7) {
  s21_decimal value_1 = {{10, 20, 30, 0}};
  s21_decimal value_2 = {{40, 50, 60, 0}};
  s21_decimal result_value = {0};
  s21_decimal expected_value = {{3478923511, 257698039, 3, 1835008}};

  s21_set_exponent(&value_1, 29);
  s21_set_exponent(&value_2, 31);

  int result = s21_add(value_1, value_2, &result_value);
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

START_TEST(s21_add_test_8) {
  s21_decimal value_1 = {{10, 20, 30, 0}};
  s21_decimal value_2 = {{40, 50, 60, 0}};

  s21_set_exponent(&value_1, 29);
  s21_set_exponent(&value_2, 31);

  int result = s21_add(value_1, value_2, NULL);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("v2: %u %u %u %u\n\n", value_2.bits[0], value_2.bits[1],
         value_2.bits[2], value_2.bits[3]);

  ck_assert_int_eq(result, AF_CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_add_test_9) {
  // 7922816251426433759354395033.4
  s21_decimal value_1 = {{-2, -1, -1, 65536}};
  // 0.05
  s21_decimal value_2 = {{5, 0, 0, 131072}};
  s21_decimal result_value = {0};
  // 7922816251426433759354395033.4
  s21_decimal expected_value = {{-2, -1, -1, 65536}};

  int result = s21_add(value_1, value_2, &result_value);
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

START_TEST(s21_add_test_10) {
  // 7922816251426433759354395033.5
  s21_decimal value_1 = {{-1, -1, -1, 65536}};
  // 0.05
  s21_decimal value_2 = {{5, 0, 0, 131072}};
  s21_decimal result_value = {0};
  // 7922816251426433759354395034
  s21_decimal expected_value = {{-1717986918, -1717986919, 429496729, 0}};

  int result = s21_add(value_1, value_2, &result_value);
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

Suite *s21_add_tests(void) {
  Suite *suite = suite_create("s21_add_tests_suite");
  TCase *tcase = tcase_create("s21_add_tests_tcase");

  tcase_add_test(tcase, s21_add_test_1);
  tcase_add_test(tcase, s21_add_test_2);
  tcase_add_test(tcase, s21_add_test_3);
  tcase_add_test(tcase, s21_add_test_4);
  tcase_add_test(tcase, s21_add_test_5);
  tcase_add_test(tcase, s21_add_test_6);
  tcase_add_test(tcase, s21_add_test_7);
  tcase_add_test(tcase, s21_add_test_8);
  tcase_add_test(tcase, s21_add_test_9);
  tcase_add_test(tcase, s21_add_test_10);

  suite_add_tcase(suite, tcase);
  return suite;
}