#include "s21_decimal_tests.h"

// normal
START_TEST(s21_from_decimal_to_int_test_1) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  int value_2 = 0;
  int expected_value = 10;

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_2) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  int value_2 = 0;
  int expected_value = -10;
  s21_set_sign_bit(&value_1, SIGN_NEGATIVE);

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_3) {
  s21_decimal value_1 = {{INT_MAX, 0, 0, 0}};
  int value_2 = 0;
  int expected_value = INT_MAX;

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_4) {
  s21_decimal value_1 = {{INT_MAX, 0, 0, 0}};
  int value_2 = 0;
  int expected_value = INT_MIN;
  s21_set_sign_bit(&value_1, SIGN_NEGATIVE);

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

// convertaion error
START_TEST(s21_from_decimal_to_int_test_5) {
  s21_decimal value_1 = {{10, 0, 0, 0}};

  int result = s21_from_decimal_to_int(value_1, NULL);

  ck_assert_int_eq(result, CP_CONVERTATION_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_6) {
  s21_decimal value_1 = {{10, 0, 1, 0}};
  int value_2 = 0;
  int expected_value = INT_MAX;

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_7) {
  s21_decimal value_1 = {{10, 1, 1, 0}};
  int value_2 = 0;
  int expected_value = INT_MAX;

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_8) {
  s21_decimal value_1 = {{10, 1, 0, 0}};
  int value_2 = 0;
  int expected_value = INT_MAX;

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_9) {
  s21_decimal value_1 = {{-10, 0, 0, 0}};
  int value_2 = 0;
  int expected_value = INT_MAX;

  int result = s21_from_decimal_to_int(value_1, &value_2);
  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_10) {
  s21_decimal value_1 = {{(unsigned int)0x7FFFFFFF + 1, 0, 0, 0}};
  int value_2 = 0;
  int expected_value = INT_MAX;

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_11) {
  s21_decimal value_1 = {{0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0}};
  int value_2 = 0;
  int expected_value = INT_MAX;

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

// normal with float
START_TEST(s21_from_decimal_to_int_test_12) {
  s21_decimal value_1 = {0};
  s21_from_float_to_decimal(10.95, &value_1);
  int value_2 = 0;
  int expected_value = 10;

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

// normal with neg float
START_TEST(s21_from_decimal_to_int_test_13) {
  s21_decimal value_1 = {0};
  s21_from_float_to_decimal(-10.95, &value_1);
  int value_2 = 0;
  int expected_value = -10;

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

// normal with double
START_TEST(s21_from_decimal_to_int_test_14) {
  s21_decimal value_1 = {0};
  s21_from_float_to_decimal(10.98765432123456789, &value_1);
  int value_2 = 0;
  int expected_value = 10;

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

// normal with neg double
START_TEST(s21_from_decimal_to_int_test_15) {
  s21_decimal value_1 = {0};
  s21_from_float_to_decimal(-10.98765432123456789, &value_1);
  int value_2 = 0;
  int expected_value = -10;

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

// lol
START_TEST(s21_from_decimal_to_int_test_16) {
  s21_decimal value_1 = {0};
  int value_2 = 0;
  int expected_value = 0;

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_decimal_to_int_test_17) {
  s21_decimal value_1 = {{21}};
  int value_2 = 0;
  int expected_value = 2;

  s21_set_exponent(&value_1, 1);

  int result = s21_from_decimal_to_int(value_1, &value_2);

  ck_assert_int_eq(value_2, expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

Suite *s21_from_decimal_to_int_tests(void) {
  Suite *suite = suite_create("s21_from_decimal_to_int_tests_suite");
  TCase *tcase = tcase_create("s21_from_decimal_to_int_tests_tcase");

  tcase_add_test(tcase, s21_from_decimal_to_int_test_1);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_2);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_3);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_4);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_5);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_6);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_7);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_8);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_9);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_10);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_11);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_12);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_13);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_14);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_15);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_16);
  tcase_add_test(tcase, s21_from_decimal_to_int_test_17);

  suite_add_tcase(suite, tcase);
  return suite;
}