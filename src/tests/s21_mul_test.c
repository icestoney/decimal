#include "s21_decimal_tests.h"

START_TEST(s21_mul_test_1) {
  // 49
  s21_decimal value_1 = {{49, 0, 0, 0}};
  // 16
  s21_decimal value_2 = {{16, 0, 0, 0}};
  s21_decimal result_value = {0};
  // 3.0625
  s21_decimal expected_value = {{784, 0, 0, 0}};

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_2) {
  // 110680465017134.46847718589441
  s21_decimal value_1 = {{400000001, 500000002, 600000003, 917504}};
  // 16
  s21_decimal value_2 = {{16, 0, 0, 0}};
  s21_decimal result_value = {0};
  // 1770887440274151.4956349743106
  s21_decimal expected_value = {{640000002, -58993456, 960000004, 851968}};

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_3) {
  // 200
  s21_decimal value_1 = {{200, 0, 0, 0}};
  // 10.0000000000000000000001
  s21_decimal value_2 = {{4135583745, 46653770, 5421, 1441792}};
  s21_decimal result_value = {0};
  // 2000.0000000000000000000200
  s21_decimal expected_value = {{-1811939128, 740819600, 1084202, 1441792}};

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_4) {
  // 48
  s21_decimal value_1 = {{48, 0, 0, 0}};
  // 63
  s21_decimal value_2 = {{63, 0, 0, 0}};
  s21_decimal result_value = {0};
  // 3024
  s21_decimal expected_value = {{3024, 0, 0, 0}};

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_5) {
  // 792281625142643375935439503.28
  s21_decimal value_1 = {{-8, -1, -1, 131072}};
  // 1.0000000000000000000000000001
  s21_decimal value_2 = {{268435457, 1042612833, 542101086, 1835008}};
  s21_decimal result_value = {0};
  // 792281625142643375935439503.4
  s21_decimal expected_value = {{-1717986918, -1717986919, 429496729, 65536}};

  int result = s21_mul(value_1, value_2, &result_value);
  printf("MUL TEST 5\n");
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

START_TEST(s21_mul_test_51) {
  // 792281625142643375935439503.25
  s21_decimal value_1 = {{-11, -1, -1, 131072}};
  // 1.0000000000000000000000000001
  s21_decimal value_2 = {{268435457, 1042612833, 542101086, 1835008}};
  s21_decimal result_value = {0};
  // 792281625142643375935439503.33
  s21_decimal expected_value = {{-3, -1, -1, 131072}};

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_52) {
  // 792281625142643375935439503.28
  s21_decimal value_1 = {{-8, -1, -1, 131072}};
  // 10.000000000000000000000000001
  s21_decimal value_2 = {{268435457, 1042612833, 542101086, 1769472}};
  s21_decimal result_value = {0};
  // 7922816251426433759354395034
  s21_decimal expected_value = {{-1717986918, -1717986919, 429496729, 0}};

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_6) {
  // 7922816251426433759354395032.8
  s21_decimal value_1 = {{-8, -1, -1, 65536}};
  // 10
  s21_decimal value_2 = {.bits = {10}};
  s21_decimal result_value = {0};
  // 79228162514264337593543950328
  s21_decimal expected_value = {{-8, -1, -1, 0}};

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_7) {
  // 49.000000000000000000000000001
  s21_decimal value_1 = {{1744830465, -1763144792, -1638671974, 1769472}};
  // 1.6000000000000000000000000001
  s21_decimal value_2 = {{-2147483647, -49806386, 867361737, 1835008}};
  s21_decimal result_value = {0};
  // 78.400000000000000000000000007
  s21_decimal expected_value = {{1073741831, 614942170, -44894780, 1769472}};

  int result = s21_mul(value_1, value_2, &result_value);
  printf("MUL TEST 7\n");
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

START_TEST(s21_mul_test_8) {
  // 1111.2222
  s21_decimal value_1 = {{11112222, 0, 0, 262144}};
  // 33333.44444
  s21_decimal value_2 = {{3333344444, 0, 0, 327680}};
  s21_decimal result_value = {0};
  // 37040863.464194568
  s21_decimal expected_value = {{351601160, 8624248, 0, 589824}};

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_9) {
  // 10.000000000000000000000000001
  s21_decimal value_1 = {{268435457, 1042612833, 542101086, 1769472}};
  // 792281625142643375935439503.28
  s21_decimal value_2 = {{-8, -1, -1, 131072}};
  s21_decimal result_value = {0};
  // 7922816251426433759354395034
  s21_decimal expected_value = {{-1717986918, -1717986919, 429496729, 0}};

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_10) {
  // 0.0000000000000000000000000008
  s21_decimal value_1 = {{8, 0, 0, 1835008}};
  // 0.0000000000000000000000000008
  s21_decimal value_2 = {{8, 0, 0, 1835008}};
  s21_decimal result_value = {0};
  // 0
  s21_decimal expected_value = {{0, 0, 0, 0}};

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_11) {
  // 79228162514264337593543950335
  s21_decimal value_1 = {{-1, -1, -1, 0}};
  // 0.0000000000000000000000000001
  s21_decimal value_2 = {{1, 0, 0, 1835008}};
  s21_decimal result_value = {0};
  // 7.9228162514264337593543950335
  s21_decimal expected_value = {{-1, -1, -1, 1835008}};

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_12) {
  // 0.0000000000000000000000000001
  s21_decimal value_1 = {{1, 0, 0, 1835008}};
  // 79228162514264337593543950328
  s21_decimal value_2 = {{-8, -1, -1, 0}};
  s21_decimal result_value = {0};
  // 7.9228162514264337593543950328
  s21_decimal expected_value = {{-8, -1, -1, 1835008}};

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_13) {
  // 0.0000000000000000000000000008
  s21_decimal value_1 = {{8, 0, 0, 1835008}};
  // 7.9228162514264337593543950335
  s21_decimal value_2 = {{-1, -1, -1, 1835008}};
  s21_decimal result_value = {0};
  // 0.0000000000000000000000000063
  s21_decimal expected_value = {{63, 0, 0, 1835008}};

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_14) {
  // 0.000000000000000000000000008
  s21_decimal value_1 = {{8, 0, 0, 1769472}};
  // 792.28162514264337593543950335
  s21_decimal value_2 = {{-1, -1, -1, 1703936}};
  s21_decimal result_value = {0};
  // 0.0000000000000000000000063383
  s21_decimal expected_value = {{63383, 0, 0, 1835008}};

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_15) {
  // 0.000000000000000000000000000
  s21_decimal value_1 = {{0, 0, 0, 0}};
  // 792.28162514264337593543950335
  s21_decimal value_2 = {{-1, -1, -1, 1703936}};
  s21_decimal result_value = {0};
  // 1
  s21_decimal expected_value = {{0, 0, 0, 0}};

  s21_set_sign_bit(&value_1, 1);
  s21_set_sign_bit(&expected_value, 1);

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_16) {
  // 792.28162514264337593543950335
  s21_decimal value_1 = {{-1, -1, -1, 1703936}};
  // 0.000000000000000000000000000
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result_value = {0};
  // 1
  s21_decimal expected_value = {{0, 0, 0, 0}};

  s21_set_sign_bit(&value_1, 1);
  s21_set_sign_bit(&expected_value, 1);

  int result = s21_mul(value_1, value_2, &result_value);
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

START_TEST(s21_mul_test_17) {
  s21_decimal value_1 = {{10, 20, 30, 0}};
  s21_decimal value_2 = {{40, 50, 60, 0}};

  s21_set_exponent(&value_1, 29);
  s21_set_exponent(&value_2, 31);

  int result = s21_mul(value_1, value_2, NULL);
  printf("v1: %u %u %u %u\n", value_1.bits[0], value_1.bits[1], value_1.bits[2],
         value_1.bits[3]);
  printf("v2: %u %u %u %u\n", value_2.bits[0], value_2.bits[1], value_2.bits[2],
         value_2.bits[3]);

  ck_assert_int_eq(result, AF_CALCULATION_ERROR);
}
END_TEST

Suite *s21_mul_tests(void) {
  Suite *suite = suite_create("s21_mul_tests_suite");
  TCase *tcase = tcase_create("s21_mul_tests_tcase");

  tcase_add_test(tcase, s21_mul_test_1);
  tcase_add_test(tcase, s21_mul_test_2);
  tcase_add_test(tcase, s21_mul_test_3);
  tcase_add_test(tcase, s21_mul_test_4);
  tcase_add_test(tcase, s21_mul_test_5);
  tcase_add_test(tcase, s21_mul_test_51);
  tcase_add_test(tcase, s21_mul_test_52);
  tcase_add_test(tcase, s21_mul_test_6);
  tcase_add_test(tcase, s21_mul_test_7);
  tcase_add_test(tcase, s21_mul_test_8);
  tcase_add_test(tcase, s21_mul_test_9);
  tcase_add_test(tcase, s21_mul_test_10);
  tcase_add_test(tcase, s21_mul_test_11);
  tcase_add_test(tcase, s21_mul_test_12);
  tcase_add_test(tcase, s21_mul_test_13);
  tcase_add_test(tcase, s21_mul_test_14);
  tcase_add_test(tcase, s21_mul_test_15);
  tcase_add_test(tcase, s21_mul_test_16);
  tcase_add_test(tcase, s21_mul_test_17);

  suite_add_tcase(suite, tcase);
  return suite;
}