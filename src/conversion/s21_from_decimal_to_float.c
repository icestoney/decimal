#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (!dst || s21_get_exponent(src) > 28) return CP_CONVERTATION_ERROR;

  double tmp = 0.0;
  for (size_t i = 0; i < DEC_MANTISSA_SIZE; i++) {
    tmp += s21_get_bit(src, i) * pow(2, i);
  }

  tmp /= pow(10, s21_get_exponent(src));
  *dst = s21_get_sign_bit(src) ? -(float)tmp : (float)tmp;

  return OK;
}