#ifndef S21_DEFINES_H
#define S21_DEFINES_H

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Convertors and parsers
#define CP_CONVERTATION_ERROR 1  // convertation error
#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

// Another functions
#define AF_CALCULATION_ERROR 1  // calculation error

#define BIG_DEC_MANTISSA_SIZE 224
#define DEC_MANTISSA_SIZE 96
#define DEC_MAX_EXP 28
#define DEC_MIN_EXP 0
#define BIG_DEC_MANTISSA(src)                                               \
  (s21_big_decimal) {                                                       \
    {                                                                       \
      src->bits[0], src->bits[1], src->bits[2], src->bits[3], src->bits[4], \
          src->bits[5], src->bits[6], 0                                     \
    }                                                                       \
  }

enum decimal_size { DEC_SIZE = 4, BIG_DEC_SIZE = 8 };

enum sign_bit_value { SIGN_POSITIVE, SIGN_NEGATIVE };
enum sign_bit_index { DEC_SIGN_BIT_INDEX = 127, BIG_DEC_SIGN_BIT_INDEX = 255 };

// Arithmetic Operators
enum arithmetic_error {
  OK,
  AO_BIG_NUMBER,    // the number is too large or equal to infinity
  AO_SMALL_NUMBER,  // the number is too small or equal to negative infinity
  AO_ZERO_DIVISION  // division by 0
};
enum arithmetic_sign_value {
  ARITHMETIC_SIGN_NEGATIVE = -1,
  ARITHMETIC_SIGN_POSITIVE = 1
};

// Comparison Operators
enum comparsion_error { CO_FALSE, CO_TRUE };

typedef struct {
  unsigned int bits[DEC_SIZE];
} s21_decimal;

typedef struct {
  unsigned int bits[BIG_DEC_SIZE];
} s21_big_decimal;

#endif