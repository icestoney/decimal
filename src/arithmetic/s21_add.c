#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!result) return AF_CALCULATION_ERROR;

  s21_big_decimal value_1_big_decimal = {0};
  s21_big_decimal value_2_big_decimal = {0};

  // (+1 -1 = -); (-1 +1 = -); (+1 +1 = +); (-1 -1 = +);
  int sign_arithmetic =
      s21_get_sign_bit(value_1) == s21_get_sign_bit(value_2) ? 1 : -1;

  if (s21_is_less(s21_abs(value_1), s21_abs(value_2))) {
    s21_swap_decimal(&value_1, &value_2);
  }
  // (+2 -1 = +); (-2 +1 = -); (+2 +1 = +); (-2 -1 = +);
  int sign_result = (s21_get_sign_bit(value_1) >= s21_get_sign_bit(value_2)) &&
                            (s21_get_sign_bit(value_1) == true)
                        ? 1
                        : 0;
  s21_from_decimal_to_big_decimal(value_1, &value_1_big_decimal);
  s21_from_decimal_to_big_decimal(value_2, &value_2_big_decimal);

  s21_exponent_normalize_big_decimal(&value_1_big_decimal,
                                     &value_2_big_decimal);
  s21_big_decimal result_big_decimal = {{0, 0, 0, 0, 0, 0, 0, 0}};
  s21_arithmetic_big_decimal(value_1_big_decimal, value_2_big_decimal,
                             sign_arithmetic, &result_big_decimal);
  if (!s21_is_bits_zero(&result_big_decimal, 0, 6))
    s21_set_sign_bit(&result_big_decimal, sign_result);

  s21_set_exponent(&result_big_decimal, s21_get_exponent(value_1_big_decimal));
  return s21_from_big_decimal_to_decimal(result_big_decimal, result);
}