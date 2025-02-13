#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  if (!result) return AF_CALCULATION_ERROR;

  bool sign = s21_get_sign_bit(value);
  value = s21_abs(value);
  s21_decimal tmp = {0};

  //обрезаем дробную часть
  s21_truncate(value, &tmp);
  if (s21_is_mantissas_equal_decimal(&value, &tmp)) {
    *result = value;
  } else {
    //получаем дробную часть
    s21_sub(value, tmp, &value);
    //умножаем на 10, чтобы получить ближайшую цифру дробной части
    s21_mul(value, (s21_decimal){.bits = {10}}, &value);
    //получаем ближайшую цифру дробной части
    s21_truncate(value, &value);
    if (s21_is_greater_or_equal(value, (s21_decimal){.bits = {5}})) {
      s21_add(tmp, (s21_decimal){.bits = {1}}, result);
    } else {
      *result = tmp;
    }
  }
  s21_set_sign_bit(result, sign);

  return OK;
}