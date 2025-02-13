#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (!result) return AF_CALCULATION_ERROR;

  s21_big_decimal big_decimal_value = {0};
  s21_from_decimal_to_big_decimal(value, &big_decimal_value);
  unsigned exp = s21_get_exponent(big_decimal_value);

  // обрезает значение числа до целого. убирает дробную часть, пока экспонента
  // > 0
  while (exp > 0) {
    big_decimal_value = s21_div_ten_big_decimal(big_decimal_value);
    exp--;
  }
  s21_set_exponent(&big_decimal_value, exp);
  s21_from_big_decimal_to_decimal(big_decimal_value, result);

  s21_set_sign_bit(result, s21_get_sign_bit(value));
  return OK;
}