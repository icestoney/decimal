#include "../headers/s21_helpers.h"

// принимает абсолютное число
bool __get_bit_decimal(s21_decimal value, unsigned int bit_index) {
  return value.bits[bit_index / 32] >> (bit_index % 32) & 1;
}

// принимает абсолютное число
bool __get_bit_big_decimal(s21_big_decimal value, unsigned int bit_index) {
  return value.bits[bit_index / 32] >> (bit_index % 32) & 1;
}

bool __get_sign_bit_decimal(s21_decimal value) {
  return s21_get_bit(value, DEC_SIGN_BIT_INDEX);
}

bool __get_sign_bit_big_decimal(s21_big_decimal value) {
  return s21_get_bit(value, BIG_DEC_SIGN_BIT_INDEX);
}

void __set_bit_decimal(s21_decimal *value, unsigned int bit_index,
                       unsigned int bit_value) {
  value->bits[bit_index / 32] =
      (value->bits[bit_index / 32] & ~(1U << (bit_index % 32))) |
      (bit_value) << (bit_index % 32);
}
void __set_bit_big_decimal(s21_big_decimal *value, unsigned int bit_index,
                           unsigned int bit_value) {
  value->bits[bit_index / 32] =
      (value->bits[bit_index / 32] & ~(1U << (bit_index % 32))) |
      (bit_value) << (bit_index % 32);
}

void __set_sign_bit_decimal(s21_decimal *value, bool bit_value) {
  s21_set_bit(value, DEC_SIGN_BIT_INDEX, bit_value);
}

void __set_sign_bit_big_decimal(s21_big_decimal *value, bool bit_value) {
  s21_set_bit(value, BIG_DEC_SIGN_BIT_INDEX, bit_value);
}

unsigned int __get_exponent_decimal(s21_decimal value) {
  return value.bits[DEC_SIZE - 1] >> 16 & 0xFF;
}

unsigned int __get_exponent_big_decimal(s21_big_decimal value) {
  return value.bits[BIG_DEC_SIZE - 1] >> 16 & 0xFF;
}

void __set_exponent_decimal(s21_decimal *value, unsigned int exp) {
  value->bits[DEC_SIZE - 1] =
      (value->bits[DEC_SIZE - 1] & ~(0xFF << 16)) | exp << 16;
}

void __set_exponent_big_decimal(s21_big_decimal *value, unsigned int exp) {
  value->bits[BIG_DEC_SIZE - 1] =
      (value->bits[BIG_DEC_SIZE - 1] & ~(0xFF << 16)) | exp << 16;
}

void __left_shift_big_decimal(s21_big_decimal *value, unsigned int shift) {
  unsigned int decimal_field_size = sizeof(value->bits[0]) * 8;
  for (size_t i = 0; i < shift; i++) {
    for (size_t j = BIG_DEC_SIZE - 2; j > 0; j--) {
      value->bits[j] <<= 1;
      s21_set_bit(value, decimal_field_size * j,
                  s21_get_bit(*value, decimal_field_size * j - 1));
    }
    value->bits[0] <<= 1;
  }
}

void __right_shift_big_decimal(s21_big_decimal *value, unsigned int shift) {
  unsigned int decimal_field_size = sizeof(value->bits[0]) * 8;
  for (size_t i = 0; i < shift; i++) {
    for (size_t j = 0; j < BIG_DEC_SIZE - 2; j++) {
      value->bits[j] >>= 1;
      s21_set_bit(value, decimal_field_size * (j + 1) - 1,
                  s21_get_bit(*value, decimal_field_size * (j + 1)));
    }
    value->bits[BIG_DEC_SIZE - 2] >>= 1;
  }
}