#include "s21_decimal_tests.h"

// normal
START_TEST(s21_from_int_to_decimal_test_1) {
  int value_1 = 10;
  s21_decimal value_2 = {0};
  int expected_value = 10;

  int result = s21_from_int_to_decimal(value_1, &value_2);

  ck_assert_int_eq(value_2.bits[0], expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_2) {
  int value_1 = -10;
  s21_decimal value_2 = {0};
  int expected_value = 10;

  int result = s21_from_int_to_decimal(value_1, &value_2);

  ck_assert_int_eq(s21_get_sign_bit(value_2), SIGN_NEGATIVE);
  ck_assert_int_eq(value_2.bits[0], expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_3) {
  int value_1 = INT_MAX;
  s21_decimal value_2 = {0};
  int expected_value = INT_MAX;

  int result = s21_from_int_to_decimal(value_1, &value_2);

  ck_assert_int_eq(value_2.bits[0], expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_4) {
  int value_1 = INT_MIN;
  s21_decimal value_2 = {0};
  unsigned int expected_value = 2147483648U;

  int result = s21_from_int_to_decimal(value_1, &value_2);

  ck_assert_int_eq(s21_get_sign_bit(value_2), SIGN_NEGATIVE);
  ck_assert_int_eq(value_2.bits[0], expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

// convertaion error
START_TEST(s21_from_int_to_decimal_test_5) {
  int value_1 = 10;
  int result = s21_from_int_to_decimal(value_1, NULL);

  ck_assert_int_eq(result, CP_CONVERTATION_ERROR);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_6) {
  int result = s21_from_int_to_decimal((unsigned int)0x7FFFFFFF + 1, NULL);

  ck_assert_int_eq(result, CP_CONVERTATION_ERROR);
}
END_TEST

// lol
START_TEST(s21_from_int_to_decimal_test_7) {
  int value_1 = 0;
  s21_decimal value_2 = {0};
  int expected_value = 0;

  int result = s21_from_int_to_decimal(value_1, &value_2);

  ck_assert_int_eq(value_2.bits[0], expected_value);
  ck_assert_int_eq(result, OK);
}
END_TEST

Suite *s21_from_int_to_decimal_tests(void) {
  Suite *suite = suite_create("s21_from_int_to_decimal_tests_suite");
  TCase *tcase = tcase_create("s21_from_int_to_decimal_tests_tcase");

  tcase_add_test(tcase, s21_from_int_to_decimal_test_1);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_2);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_3);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_4);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_5);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_6);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_7);

  suite_add_tcase(suite, tcase);
  return suite;
}