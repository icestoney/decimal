#include "s21_decimal_tests.h"

START_TEST(s21_comparison_test_1) {
  s21_decimal l_value = {{10, 0, 0, 0}};
  s21_decimal r_value = {{10, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_greater(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_less(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_greater_or_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_less_or_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_not_equal(l_value, r_value), CO_FALSE);
}
END_TEST

START_TEST(s21_comparison_test_2) {
  s21_decimal l_value = {{10, 0, 0, 0}};
  s21_decimal r_value = {{10, 0, 0, 0}};

  s21_set_sign_bit(&l_value, SIGN_NEGATIVE);  // -10

  ck_assert_int_eq(s21_is_equal(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_greater(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_less(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_greater_or_equal(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_less_or_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_not_equal(l_value, r_value), CO_TRUE);
}
END_TEST

START_TEST(s21_comparison_test_3) {
  s21_decimal l_value = {{10, 0, 0, 0}};
  s21_decimal r_value = {{10, 0, 0, 0}};

  s21_set_sign_bit(&r_value, SIGN_NEGATIVE);  // -10

  ck_assert_int_eq(s21_is_equal(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_greater(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_less(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_greater_or_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_less_or_equal(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_not_equal(l_value, r_value), CO_TRUE);
}
END_TEST

START_TEST(s21_comparison_test_4) {
  s21_decimal l_value = {{10, 0, 0, 0}};
  s21_decimal r_value = {{10, 0, 0, 0}};

  s21_set_sign_bit(&l_value, SIGN_NEGATIVE);  // -10
  s21_set_sign_bit(&r_value, SIGN_NEGATIVE);  // -10

  ck_assert_int_eq(s21_is_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_greater(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_less(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_greater_or_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_less_or_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_not_equal(l_value, r_value), CO_FALSE);
}
END_TEST

START_TEST(s21_comparison_test_5) {
  s21_decimal l_value = {0};
  s21_decimal r_value = {0};

  s21_set_sign_bit(&l_value, SIGN_NEGATIVE);  // -0

  ck_assert_int_eq(s21_is_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_greater(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_less(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_greater_or_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_less_or_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_not_equal(l_value, r_value), CO_FALSE);
}
END_TEST

START_TEST(s21_comparison_test_6) {
  s21_decimal l_value = {0};
  s21_decimal r_value = {0};

  s21_set_sign_bit(&r_value, SIGN_NEGATIVE);  // -0

  ck_assert_int_eq(s21_is_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_greater(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_less(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_greater_or_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_less_or_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_not_equal(l_value, r_value), CO_FALSE);
}
END_TEST

START_TEST(s21_comparison_test_7) {
  // 110680465017134.46847718589441
  s21_decimal l_value = {{400000001, 500000002, 600000003, 917504}};
  // 16
  s21_decimal r_value = {{16, 0, 0, 0}};

  ck_assert_int_eq(s21_is_equal(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_greater(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_less(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_greater_or_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_less_or_equal(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_not_equal(l_value, r_value), CO_TRUE);
}
END_TEST

START_TEST(s21_comparison_test_8) {
  // 79228162514264337593543950335
  s21_decimal l_value = {{-1, -1, -1, 0}};
  // 79228162514264337593543950335
  s21_decimal r_value = {{-1, -1, -1, 0}};

  ck_assert_int_eq(s21_is_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_greater(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_less(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_greater_or_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_less_or_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_not_equal(l_value, r_value), CO_FALSE);
}
END_TEST

START_TEST(s21_comparison_test_9) {
  // 79228162514264337593543950335
  s21_decimal l_value = {{-1, -1, -1, 0}};
  // 79228162514264337593543950335
  s21_decimal r_value = {{-1, -1, -1, 0}};

  s21_set_sign_bit(&l_value, SIGN_NEGATIVE);

  ck_assert_int_eq(s21_is_equal(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_greater(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_less(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_greater_or_equal(l_value, r_value), CO_FALSE);
  ck_assert_int_eq(s21_is_less_or_equal(l_value, r_value), CO_TRUE);
  ck_assert_int_eq(s21_is_not_equal(l_value, r_value), CO_TRUE);
}
END_TEST

START_TEST(test_comparison_positives_int) {
  s21_decimal val_1 = {{123, 0, 0, 0}};
  s21_decimal val_2 = {{0, 1, 0, 0}};
  ck_assert(s21_is_less(val_2, val_1) == 0);
  ck_assert(s21_is_less(val_1, val_2) == 1);
  ck_assert(s21_is_greater(val_2, val_1) == 1);
  ck_assert(s21_is_greater(val_1, val_2) == 0);
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  val_1.bits[1] = 1;
  val_2.bits[0] = 123;
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_equal(val_1, val_2) == 1);
  ck_assert(s21_is_equal(val_2, val_1) == 1);
  ck_assert(s21_is_not_equal(val_1, val_2) == 0);
  ck_assert(s21_is_not_equal(val_2, val_1) == 0);
}
END_TEST

START_TEST(test_comparison_negatives_int) {
  s21_decimal val_1 = {{123, 0, 0, 1 << 31}};
  s21_decimal val_2 = {{0, 1, 0, 1 << 31}};
  ck_assert(s21_is_less(val_2, val_1) == 1);
  ck_assert(s21_is_less(val_1, val_2) == 0);
  ck_assert(s21_is_greater(val_2, val_1) == 0);
  ck_assert(s21_is_greater(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  val_1.bits[1] = 1;
  val_2.bits[0] = 123;
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_equal(val_1, val_2) == 1);
  ck_assert(s21_is_equal(val_2, val_1) == 1);
  ck_assert(s21_is_not_equal(val_1, val_2) == 0);
  ck_assert(s21_is_not_equal(val_2, val_1) == 0);
}
END_TEST

START_TEST(test_comparison_combine_int_1) {
  s21_decimal val_1 = {{123, 0, 0, 1 << 31}};
  s21_decimal val_2 = {{0, 1, 0, 0}};
  ck_assert(s21_is_less(val_2, val_1) == 0);
  ck_assert(s21_is_less(val_1, val_2) == 1);
  ck_assert(s21_is_greater(val_2, val_1) == 1);
  ck_assert(s21_is_greater(val_1, val_2) == 0);
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  val_1.bits[1] = 1;
  val_2.bits[0] = 123;
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_equal(val_2, val_1) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  ck_assert(s21_is_not_equal(val_2, val_1) == 1);
}
END_TEST

START_TEST(test_comparison_combine_int_2) {
  s21_decimal val_1 = {{123, 0, 0, 0}};
  s21_decimal val_2 = {{0, 1, 0, 1 << 31}};
  ck_assert(s21_is_less(val_2, val_1) == 1);
  ck_assert(s21_is_less(val_1, val_2) == 0);
  ck_assert(s21_is_greater(val_2, val_1) == 0);
  ck_assert(s21_is_greater(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  val_1.bits[1] = 1;
  val_2.bits[0] = 123;
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_equal(val_2, val_1) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  ck_assert(s21_is_not_equal(val_2, val_1) == 1);
}
END_TEST

START_TEST(test_comparison_positives_float_int) {
  s21_decimal val_1 = {{123, 0, 0, 3 << 16}};
  s21_decimal val_2 = {{0, 1, 0, 0}};
  ck_assert(s21_is_less(val_2, val_1) == 0);
  ck_assert(s21_is_less(val_1, val_2) == 1);
  ck_assert(s21_is_greater(val_2, val_1) == 1);
  ck_assert(s21_is_greater(val_1, val_2) == 0);
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  val_1.bits[1] = 1;
  val_2.bits[0] = 123;
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_equal(val_2, val_1) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  ck_assert(s21_is_not_equal(val_2, val_1) == 1);
}
END_TEST

START_TEST(test_comparison_positives_int_float) {
  s21_decimal val_1 = {{123, 0, 0, 0}};
  s21_decimal val_2 = {{124, 0, 0, 1 << 16}};
  ck_assert(s21_is_less(val_2, val_1) == 1);
  ck_assert(s21_is_less(val_1, val_2) == 0);
  ck_assert(s21_is_greater(val_2, val_1) == 0);
  ck_assert(s21_is_greater(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  val_1.bits[0] = 124;
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_equal(val_2, val_1) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  ck_assert(s21_is_not_equal(val_2, val_1) == 1);
}
END_TEST

START_TEST(test_comparison_positives_float_float) {
  s21_decimal val_1 = {{123, 0, 0, 1 << 16}};
  s21_decimal val_2 = {{124, 0, 0, 1 << 16}};
  ck_assert(s21_is_less(val_2, val_1) == 0);
  ck_assert(s21_is_less(val_1, val_2) == 1);
  ck_assert(s21_is_greater(val_2, val_1) == 1);
  ck_assert(s21_is_greater(val_1, val_2) == 0);
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  val_1.bits[0] = 124;
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_equal(val_1, val_2) == 1);
  ck_assert(s21_is_equal(val_2, val_1) == 1);
  ck_assert(s21_is_not_equal(val_1, val_2) == 0);
  ck_assert(s21_is_not_equal(val_2, val_1) == 0);
}
END_TEST

START_TEST(test_comparison_negatives_float_int) {
  s21_decimal val_1 = {{123, 0, 0, (1 << 31) + (3 << 16)}};
  s21_decimal val_2 = {{0, 1, 0, 0}};
  ck_assert(s21_is_less(val_2, val_1) == 0);
  ck_assert(s21_is_less(val_1, val_2) == 1);
  ck_assert(s21_is_greater(val_2, val_1) == 1);
  ck_assert(s21_is_greater(val_1, val_2) == 0);
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  val_1.bits[1] = 1;
  val_2.bits[0] = 123;
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_equal(val_2, val_1) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  ck_assert(s21_is_not_equal(val_2, val_1) == 1);
}
END_TEST

START_TEST(test_comparison_negatives_int_float) {
  s21_decimal val_1 = {{123, 0, 0, 0}};
  s21_decimal val_2 = {{124, 0, 0, (1 << 31) + (3 << 16)}};
  ck_assert(s21_is_less(val_2, val_1) == 1);
  ck_assert(s21_is_less(val_1, val_2) == 0);
  ck_assert(s21_is_greater(val_2, val_1) == 0);
  ck_assert(s21_is_greater(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  val_1.bits[0] = 124;
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_equal(val_2, val_1) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  ck_assert(s21_is_not_equal(val_2, val_1) == 1);
}
END_TEST

START_TEST(test_comparison_negatives_float_float) {
  s21_decimal val_1 = {{123, 0, 0, (1 << 31) + (3 << 16)}};
  s21_decimal val_2 = {{124, 0, 0, (1 << 31) + (3 << 16)}};
  ck_assert(s21_is_less(val_2, val_1) == 1);
  ck_assert(s21_is_less(val_1, val_2) == 0);
  ck_assert(s21_is_greater(val_2, val_1) == 0);
  ck_assert(s21_is_greater(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 0);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 0);
  ck_assert(s21_is_equal(val_1, val_2) == 0);
  ck_assert(s21_is_not_equal(val_1, val_2) == 1);
  val_1.bits[0] = 124;
  ck_assert(s21_is_less_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_less_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_greater_or_equal(val_1, val_2) == 1);
  ck_assert(s21_is_greater_or_equal(val_2, val_1) == 1);
  ck_assert(s21_is_equal(val_1, val_2) == 1);
  ck_assert(s21_is_equal(val_2, val_1) == 1);
  ck_assert(s21_is_not_equal(val_1, val_2) == 0);
  ck_assert(s21_is_not_equal(val_2, val_1) == 0);
}
END_TEST

START_TEST(test_comparison_weird_cases) {
  s21_decimal val_1 = {{4294967295, 4294967295, 4294967295, 3 << 16}};
  s21_decimal val_2 = {{4294967295, 4294967295, 4294967295, 6 << 16}};
  ck_assert(s21_is_equal(val_1, val_2) == 0);
}
END_TEST

START_TEST(test_comparison_zero) {
  s21_decimal val_1 = {{0, 0, 0, 0}};
  s21_decimal val_2 = {{0, 0, 0, 1 << 31}};
  ck_assert(s21_is_equal(val_1, val_2) == 1);
}

START_TEST(test_comparison_no_exp) {
  s21_decimal val_1 = {{1, 2, 3, 0}};
  s21_decimal val_2 = {{3, 2, 1, 0}};
  ck_assert(s21_is_equal(val_1, val_2) == 0);
}

START_TEST(test_comparison_normalize) {
  s21_decimal val_1 = {{1230, 0, 0, 1 << 16}};
  s21_decimal val_2 = {{123, 0, 0, 0}};
  ck_assert(s21_is_equal(val_1, val_2) == 1);
}

START_TEST(s21_is_greater_test_1) {
  float a = Rand_R(-10e20, 10e20);
  float b = Rand_R(-10e20, 10e20);

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_greater(_a, _b), a > b);
}
END_TEST

START_TEST(s21_is_greater_test_2) {
  float a = Rand_R(-10e1, 10e1);
  float b = Rand_R(-10e1, 10e1);

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_greater(_a, _b), a > b);
}
END_TEST

START_TEST(s21_is_greater_test_3) {
  float a = -25.158531;
  float b = -39.425785;

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_greater(_a, _b), a > b);
}

START_TEST(s21_is_greater_or_equal_test_1) {
  float a = Rand_R(-10e20, 10e20);
  float b = Rand_R(-10e20, 10e20);

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_greater_or_equal(_a, _b), a >= b);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_2) {
  float a = Rand_R(-10e1, 10e1);
  float b = Rand_R(-10e1, 10e1);

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_greater_or_equal(_a, _b), a >= b);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_3) {
  float a = -25.158531;
  float b = -39.425785;

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_greater_or_equal(_a, _b), a >= b);
}
END_TEST

START_TEST(s21_is_greater_or_equal_test_4) {
  float a = Rand_R(-10e20, 10e20);

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(a, &_b);
  ck_assert_int_eq(s21_is_greater_or_equal(_a, _b), 1);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_1) {
  float a = Rand_R(-10e20, 10e20);
  float b = Rand_R(-10e20, 10e20);

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_less_or_equal(_a, _b), a <= b);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_2) {
  float a = Rand_R(-10e1, 10e1);
  float b = Rand_R(-10e1, 10e1);

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_less_or_equal(_a, _b), a <= b);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_3) {
  float a = -25.158531;
  float b = -39.425785;

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_less_or_equal(_a, _b), a <= b);
}
END_TEST

START_TEST(s21_is_less_or_equal_test_4) {
  float a = Rand_R(-10e20, 10e20);

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(a, &_b);
  ck_assert_int_eq(s21_is_less(_a, _b), 0);
}
END_TEST

START_TEST(s21_is_less_test_1) {
  float a = Rand_R(-10e20, 10e20);
  float b = Rand_R(-10e20, 10e20);

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_less(_a, _b), a < b);
}
END_TEST

START_TEST(s21_is_less_test_2) {
  float a = Rand_R(-10e1, 10e1);
  float b = Rand_R(-10e1, 10e1);

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_less(_a, _b), a < b);
}
END_TEST

START_TEST(s21_is_less_test_3) {
  float a = -25.158531;
  float b = -39.425785;

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_less(_a, _b), a < b);
}
END_TEST

START_TEST(s21_is_less_test_4) {
  float a = Rand_R(-10e20, 10e20);

  s21_decimal _a;
  s21_decimal _b;
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(a, &_b);
  ck_assert_int_eq(s21_is_less(_a, _b), 0);
}
END_TEST

Suite *s21_comparison_tests(void) {
  Suite *suite = suite_create("s21_comparison_tests_suite");
  TCase *tcase = tcase_create("s21_comparison_tests_tcase");

  tcase_add_test(tcase, s21_comparison_test_1);
  tcase_add_test(tcase, s21_comparison_test_2);
  tcase_add_test(tcase, s21_comparison_test_3);
  tcase_add_test(tcase, s21_comparison_test_4);
  tcase_add_test(tcase, s21_comparison_test_5);
  tcase_add_test(tcase, s21_comparison_test_6);
  tcase_add_test(tcase, s21_comparison_test_7);
  tcase_add_test(tcase, s21_comparison_test_8);
  tcase_add_test(tcase, s21_comparison_test_9);
  tcase_add_test(tcase, test_comparison_positives_int);
  tcase_add_test(tcase, test_comparison_negatives_int);
  tcase_add_test(tcase, test_comparison_combine_int_1);
  tcase_add_test(tcase, test_comparison_combine_int_2);
  tcase_add_test(tcase, test_comparison_positives_float_int);
  tcase_add_test(tcase, test_comparison_positives_int_float);
  tcase_add_test(tcase, test_comparison_positives_float_float);
  tcase_add_test(tcase, test_comparison_negatives_float_int);
  tcase_add_test(tcase, test_comparison_negatives_int_float);
  tcase_add_test(tcase, test_comparison_negatives_float_float);
  tcase_add_test(tcase, test_comparison_weird_cases);
  tcase_add_test(tcase, test_comparison_no_exp);
  tcase_add_test(tcase, test_comparison_zero);
  tcase_add_test(tcase, test_comparison_normalize);
  tcase_add_loop_test(tcase, s21_is_greater_test_1, 0, 10);
  tcase_add_loop_test(tcase, s21_is_greater_test_2, 0, 10);
  tcase_add_test(tcase, s21_is_greater_test_3);
  tcase_add_loop_test(tcase, s21_is_greater_or_equal_test_1, 0, 10);
  tcase_add_loop_test(tcase, s21_is_greater_or_equal_test_2, 0, 10);
  tcase_add_test(tcase, s21_is_greater_or_equal_test_3);
  tcase_add_loop_test(tcase, s21_is_greater_or_equal_test_4, 0, 10);
  tcase_add_loop_test(tcase, s21_is_less_or_equal_test_1, 0, 10);
  tcase_add_loop_test(tcase, s21_is_less_or_equal_test_2, 0, 10);
  tcase_add_test(tcase, s21_is_less_or_equal_test_3);
  tcase_add_loop_test(tcase, s21_is_less_or_equal_test_4, 0, 10);
  tcase_add_loop_test(tcase, s21_is_less_test_1, 0, 10);
  tcase_add_loop_test(tcase, s21_is_less_test_2, 0, 10);
  tcase_add_test(tcase, s21_is_less_test_3);
  tcase_add_loop_test(tcase, s21_is_less_test_4, 0, 10);

  suite_add_tcase(suite, tcase);
  return suite;
}