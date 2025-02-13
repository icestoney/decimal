#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!result) return AF_CALCULATION_ERROR;

  s21_big_decimal multiplier_l = {0};
  s21_big_decimal multiplier_r = {0};
  s21_from_decimal_to_big_decimal(value_1, &multiplier_l);
  s21_from_decimal_to_big_decimal(value_2, &multiplier_r);

  s21_big_decimal ans = {0};
  if (s21_is_bits_zero(&multiplier_l, 0, 6) ||
      s21_is_bits_zero(&multiplier_r, 0, 6)) {
    s21_set_sign_bit(&ans, !s21_is_signs_equal(multiplier_l, multiplier_r));
  } else {
    ans = s21_mul_big_decimal(multiplier_l, multiplier_r);
  }

  return s21_from_big_decimal_to_decimal(ans, result);
}