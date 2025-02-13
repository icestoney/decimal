#include "s21_decimal_tests.h"

START_TEST(s21_div_test_2) {
  // 110680465017134.46847718589441
  s21_decimal value_1 = {{400000001, 500000002, 600000003, 917504}};
  // 16
  s21_decimal value_2 = {{16, 0, 0, 0}};
  s21_decimal result_value = {0};
  // 6917529063570.9042798241184006
  s21_decimal expected_value = {{352516358, 2051258189, 3750000019, 1048576}};

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
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

START_TEST(s21_div_test_1) {
  // 49
  s21_decimal value_1 = {{49, 0, 0, 0}};
  // 16
  s21_decimal value_2 = {{16, 0, 0, 0}};
  s21_decimal result_value = {0};
  // 3.0625
  s21_decimal expected_value = {{30625, 0, 0, 262144}};

  s21_set_exponent(&value_1, 1);
  s21_set_exponent(&expected_value, 5);

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
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

START_TEST(s21_div_test_3) {
  // 200
  s21_decimal value_1 = {{200, 0, 0, 0}};
  // 10.0000000000000000000001
  s21_decimal value_2 = {{4135583745, 46653770, 5421, 1441792}};
  s21_decimal result_value = {0};
  // 19.9999999999999999999998
  s21_decimal expected_value = {{3976200190, 93307541, 10842, 1441792}};

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
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

START_TEST(s21_div_test_4) {
  // 48
  s21_decimal value_1 = {{48, 0, 0, 0}};
  // 63
  s21_decimal value_2 = {{63, 0, 0, 0}};
  s21_decimal result_value = {0};
  // 0.7619047619047619047619047619
  s21_decimal expected_value = {{-1022611261, 180804925, 413029399, 1835008}};

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
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

START_TEST(s21_div_test_5) {
  // 7922816251426433759354395032.8
  s21_decimal value_1 = {{-8, -1, -1, 65536}};
  // 10.000000000000000000000000001
  s21_decimal value_2 = {{268435457, 1042612833, 542101086, 1769472}};
  s21_decimal result_value = {0};
  // 792281625142643375935439503.2
  s21_decimal expected_value = {{-1717986920, -1717986919, 429496729, 65536}};

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
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

START_TEST(s21_div_test_6) {
  // 7922816251426433759354395032.8
  s21_decimal value_1 = {{-8, -1, -1, 65536}};
  // 10
  s21_decimal value_2 = {.bits = {10}};
  s21_decimal result_value = {0};
  // 792281625142643375935439503.28
  s21_decimal expected_value = {{4294967288, 4294967295, 4294967295, 131072}};

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
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

START_TEST(s21_div_test_7) {
  // 49.000000000000000000000000001
  s21_decimal value_1 = {{1744830465, -1763144792, -1638671974, 1769472}};
  // 1.6000000000000000000000000001
  s21_decimal value_2 = {{-2147483647, -49806386, 867361737, 1835008}};
  s21_decimal result_value = {0};
  // 30.624999999999999999999999999
  s21_decimal expected_value = {{1090519039, -1638836407, 1660184576, 1769472}};

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
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

START_TEST(s21_div_test_8) {
  // 1111.2222
  s21_decimal value_1 = {{11112222, 0, 0, 262144}};
  // 33333.44444
  s21_decimal value_2 = {{3333344444, 0, 0, 327680}};
  s21_decimal result_value = {0};
  // 0.0333365548825952653334615905
  s21_decimal expected_value = {{276633441, 2634730587, 18071782, 1835008}};

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
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

START_TEST(s21_div_test_9) {
  // 10.000000000000000000000000001
  s21_decimal value_1 = {{268435457, 1042612833, 542101086, 1769472}};
  // 7922816251426433759354395032.8
  s21_decimal value_2 = {{-8, -1, -1, 65536}};
  s21_decimal result_value = {0};
  // 0.0000000000000000000000000013
  s21_decimal expected_value = {{13, 0, 0, 1835008}};

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
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

START_TEST(s21_div_test_10) {
  // 0.0000000000000000000000000008
  s21_decimal value_1 = {{8, 0, 0, 1835008}};
  // 0.0000000000000000000000000008
  s21_decimal value_2 = {{8, 0, 0, 1835008}};
  s21_decimal result_value = {0};
  // 1
  s21_decimal expected_value = {{1, 0, 0, 0}};

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
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

START_TEST(s21_div_test_11) {
  // 79228162514264337593543950335
  s21_decimal value_1 = {{-1, -1, -1, 0}};
  // 0.0000000000000000000000000001
  s21_decimal value_2 = {{1, 0, 0, 1835008}};
  s21_decimal result_value = {0};
  // 1
  s21_decimal expected_value = {{0, 0, 0, 0}};

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("v2: %u %u %u %u\n", value_2.bits[0], value_2.bits[1], value_2.bits[2],
         value_2.bits[3]);
  printf("r: %u %u %u %u\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);
  printf("ex: %u %u %u %u\n\n", expected_value.bits[0], expected_value.bits[1],
         expected_value.bits[2], expected_value.bits[3]);

  ck_assert_int_eq(s21_is_equal(expected_value, result_value), true);
  ck_assert_int_eq(result, AO_BIG_NUMBER);
}
END_TEST

START_TEST(s21_div_test_12) {
  // 0.0000000000000000000000000001
  s21_decimal value_1 = {{1, 0, 0, 1835008}};
  // 79228162514264337593543950328
  s21_decimal value_2 = {{-8, -1, -1, 0}};
  s21_decimal result_value = {0};
  // 1
  s21_decimal expected_value = {{0, 0, 0, 0}};

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
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

START_TEST(s21_div_test_13) {
  // 0.000000000000000000000000008
  s21_decimal value_1 = {{8, 0, 0, 1769472}};
  // 79.228162514264337593543950335
  s21_decimal value_2 = {{-1, -1, -1, 1769472}};
  s21_decimal result_value = {0};
  // 0.0000000000000000000000000001
  s21_decimal expected_value = {{1, 0, 0, 1835008}};

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
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

START_TEST(s21_div_test_14) {
  // 0.000000000000000000000000008
  s21_decimal value_1 = {{8, 0, 0, 1769472}};
  // 792.28162514264337593543950335
  s21_decimal value_2 = {{-1, -1, -1, 1703936}};
  s21_decimal result_value = {0};
  // 1
  s21_decimal expected_value = {{0, 0, 0, 0}};

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
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

START_TEST(s21_div_test_15) {
  // 0.000000000000000000000000000
  s21_decimal value_1 = {{0, 0, 0, 0}};
  // 792.28162514264337593543950335
  s21_decimal value_2 = {{-1, -1, -1, 1703936}};
  s21_decimal result_value = {0};
  // 1
  s21_decimal expected_value = {{0, 0, 0, 0}};

  s21_set_sign_bit(&value_1, 1);
  s21_set_sign_bit(&expected_value, 1);

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
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

START_TEST(s21_div_test_16) {
  s21_decimal value_1 = {{10, 20, 30, 0}};
  s21_decimal value_2 = {{40, 50, 60, 0}};
  s21_decimal result_value = {{123}};

  s21_set_exponent(&value_1, 29);
  s21_set_exponent(&value_2, 31);

  int result = s21_div(value_1, value_2, NULL);
  printf("err_code: %d\n", result);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("v2: %u %u %u %u\n", value_2.bits[0], value_2.bits[1], value_2.bits[2],
         value_2.bits[3]);
  printf("r : %u %u %u %u\n\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);

  ck_assert_int_eq(result, AF_CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_div_test_17) {
  s21_decimal value_1 = {{10, 20, 30, 0}};
  s21_decimal value_2 = {0};
  s21_decimal result_value = {{123}};

  s21_set_exponent(&value_1, 29);

  int result = s21_div(value_1, value_2, &result_value);
  printf("err_code: %d\n", result);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("v2: %u %u %u %u\n", value_2.bits[0], value_2.bits[1], value_2.bits[2],
         value_2.bits[3]);
  printf("r : %u %u %u %u\n\n", result_value.bits[0], result_value.bits[1],
         result_value.bits[2], result_value.bits[3]);

  ck_assert_int_eq(result, AO_ZERO_DIVISION);
}
END_TEST

Suite *s21_div_tests(void) {
  Suite *suite = suite_create("s21_div_tests_suite");
  TCase *tcase = tcase_create("s21_div_tests_tcase");

  tcase_add_test(tcase, s21_div_test_1);
  tcase_add_test(tcase, s21_div_test_2);
  tcase_add_test(tcase, s21_div_test_3);
  tcase_add_test(tcase, s21_div_test_4);
  tcase_add_test(tcase, s21_div_test_5);
  tcase_add_test(tcase, s21_div_test_6);
  tcase_add_test(tcase, s21_div_test_7);
  tcase_add_test(tcase, s21_div_test_8);
  tcase_add_test(tcase, s21_div_test_9);
  tcase_add_test(tcase, s21_div_test_10);
  tcase_add_test(tcase, s21_div_test_11);
  tcase_add_test(tcase, s21_div_test_12);
  tcase_add_test(tcase, s21_div_test_13);
  tcase_add_test(tcase, s21_div_test_14);
  tcase_add_test(tcase, s21_div_test_15);
  tcase_add_test(tcase, s21_div_test_16);
  tcase_add_test(tcase, s21_div_test_17);

  suite_add_tcase(suite, tcase);
  return suite;
}