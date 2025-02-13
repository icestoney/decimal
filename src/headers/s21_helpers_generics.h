#ifndef S21_HELPERS_GENERICS_H
#define S21_HELPERS_GENERICS_H

#include "s21_defines.h"

#define s21_get_bit(value, bit_index)           \
  _Generic((value), s21_decimal                 \
           : __get_bit_decimal, s21_big_decimal \
           : __get_bit_big_decimal)(value, bit_index)

// возвращает 0, если число положительное, иначе 1
#define s21_get_sign_bit(value)                      \
  _Generic((value), s21_decimal                      \
           : __get_sign_bit_decimal, s21_big_decimal \
           : __get_sign_bit_big_decimal)(value)

#define s21_set_bit(value, bit_index, bit_value)  \
  _Generic((value), s21_decimal *                 \
           : __set_bit_decimal, s21_big_decimal * \
           : __set_bit_big_decimal)(value, bit_index, bit_value)

#define s21_set_sign_bit(value, bit_value)             \
  _Generic((value), s21_decimal *                      \
           : __set_sign_bit_decimal, s21_big_decimal * \
           : __set_sign_bit_big_decimal)(value, bit_value)

#define s21_get_exponent(value)                      \
  _Generic((value), s21_decimal                      \
           : __get_exponent_decimal, s21_big_decimal \
           : __get_exponent_big_decimal)(value)

#define s21_set_exponent(value, exp)                   \
  _Generic((value), s21_decimal *                      \
           : __set_exponent_decimal, s21_big_decimal * \
           : __set_exponent_big_decimal)(value, exp)

#define s21_left_shift(value, shift) \
  _Generic((value), s21_big_decimal * : __left_shift_big_decimal)(value, shift)

#define s21_right_shift(value, shift) \
  _Generic((value), s21_big_decimal * : __right_shift_big_decimal)(value, shift)

#define s21_abs(value)                      \
  _Generic((value), s21_decimal             \
           : __abs_decimal, s21_big_decimal \
           : __abs_big_decimal)(value)

#endif