#include "../s21_decimal.h"

int s21_is_not_equal(s21_decimal l_value, s21_decimal r_value) {
  s21_big_decimal l_value_big = {0};
  s21_big_decimal r_value_big = {0};
  s21_from_decimal_to_big_decimal(l_value, &l_value_big);
  s21_from_decimal_to_big_decimal(r_value, &r_value_big);
  return s21_is_not_equal_big_decimal(l_value_big, r_value_big);
}