#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int code = OK;
  if (!dst || isinf(src) || isnan(src) || (fabsf(src) > MAX_FLOAT_TO_CONVERT)) {
    code = CP_CONVERTATION_ERROR;
  } else if (src == 0.0) {
    code = OK;
    *dst = (s21_decimal){0};
    if (signbit(src) != 0) {
      s21_set_sign_bit(dst, SIGN_NEGATIVE);
    }
  } else if (fabsf(src) < MIN_FLOAT_TO_CONVERT) {
    code = CP_CONVERTATION_ERROR;
    *dst = (s21_decimal){0};
  } else {
    *dst = (s21_decimal){0};
    s21_decimal result = {0};
    char flt[64];

    sprintf(flt, "%.6E", fabsf(src));
    int exp = s21_exp_from_str(flt);
    if (exp <= -23) {
      int float_precision = exp + 28;
      sprintf(flt, "%.*E", float_precision, fabsf(src));
    }

    result = s21_str_to_decimal(flt);
    if (signbit(src) != 0) {
      s21_set_sign_bit(&result, SIGN_NEGATIVE);
    }

    *dst = result;
  }

  return code;
}