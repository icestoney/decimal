#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (!dst) return CP_CONVERTATION_ERROR;

  s21_decimal_reset(dst, 1);

  dst->bits[0] = src < 0 ? -src : src;
  s21_set_sign_bit(dst, src < 0);

  return OK;
}