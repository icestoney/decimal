#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (!dst) return CP_CONVERTATION_ERROR;

  bool sign = s21_get_sign_bit(src);
  s21_truncate(src, &src);
  if (src.bits[2] > 0 || src.bits[1] > 0 || src.bits[0] >= INT_MAX) {
    *dst = sign ? INT_MIN : INT_MAX;
  } else {
    *dst = sign ? -src.bits[0] : src.bits[0];
  }

  return OK;
}