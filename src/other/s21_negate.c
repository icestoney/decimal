#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  if (!result) return AF_CALCULATION_ERROR;

  *result = value;
  s21_set_sign_bit(result, !s21_get_sign_bit(value));
  return OK;
}