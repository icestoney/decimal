#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (!result) return AF_CALCULATION_ERROR;

  bool sign = s21_get_sign_bit(value);
  value = s21_abs(value);
  s21_truncate(value, result);
  if (sign) {
    if (!s21_is_mantissas_equal_decimal(&value, result)) {
      s21_decimal one = {.bits = {1}};
      s21_add(*result, one, result);
    }
    s21_set_sign_bit(result, sign);
  }

  return OK;
}