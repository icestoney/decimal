#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!result) return AF_CALCULATION_ERROR;
  s21_big_decimal divisor = {0};
  s21_from_decimal_to_big_decimal(value_2, &divisor);

  if (s21_is_equal_big_decimal((s21_big_decimal){0}, divisor))
    return AO_ZERO_DIVISION;

  s21_big_decimal dividend = {0};
  s21_from_decimal_to_big_decimal(value_1, &dividend);

  s21_big_decimal ans = {0};
  if (!s21_is_bits_zero(&dividend, 0, 6))
    ans = s21_div_big_decimal(dividend, divisor);
  else
    s21_set_sign_bit(&ans, !s21_is_signs_equal(dividend, divisor));
  return s21_from_big_decimal_to_decimal(ans, result);
}