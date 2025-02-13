#include "../headers/s21_helpers.h"

// sign 1 (+), sign -1 (-)
void s21_arithmetic_big_decimal(s21_big_decimal value_1,
                                s21_big_decimal value_2, int sign,
                                s21_big_decimal *result) {
  int remainder_value = 0;
  int bit_add_result = 0;

  for (size_t i = 0; i < BIG_DEC_MANTISSA_SIZE; i++) {
    if (bit_add_result < 0) {
      remainder_value = -1;
    } else if (bit_add_result > 1) {
      remainder_value = 1;
    } else {
      remainder_value = 0;
    }
    bit_add_result = ((int)(s21_get_bit(value_1, i)) + remainder_value) +
                     ((int)(s21_get_bit(value_2, i)) * sign);
    s21_set_bit(result, i, bit_add_result);
  }
}

void s21_mul_by_ten_big_decimal(s21_big_decimal *value) {
  s21_big_decimal tmp_value = *value;
  s21_left_shift(&tmp_value, 3);
  s21_left_shift(value, 1);
  s21_arithmetic_big_decimal(*value, tmp_value, ARITHMETIC_SIGN_POSITIVE,
                             value);
}

s21_decimal __abs_decimal(s21_decimal value) {
  s21_set_sign_bit(&value, SIGN_POSITIVE);
  return value;
}

s21_big_decimal __abs_big_decimal(s21_big_decimal value) {
  s21_set_sign_bit(&value, SIGN_POSITIVE);
  return value;
}

// если l_value > r_value = 1; иначе 0
int s21_is_greater_big_decimal(s21_big_decimal l_value,
                               s21_big_decimal r_value) {
  s21_exponent_normalize_big_decimal(&l_value, &r_value);
  bool is_greater = false, is_zero = true;
  for (size_t i = 0; i < BIG_DEC_SIZE - 1; i++) {
    if (l_value.bits[i] > r_value.bits[i]) {
      is_greater = true;
    } else if (l_value.bits[i] < r_value.bits[i]) {
      is_greater = false;
    }
    is_zero = is_zero && (l_value.bits[i] == 0 && r_value.bits[i] == 0);
  }
  bool l_value_sign = s21_get_sign_bit(l_value);
  bool r_value_sign = s21_get_sign_bit(r_value);
  if (l_value_sign == SIGN_NEGATIVE && r_value_sign == SIGN_NEGATIVE &&
      !s21_is_equal_big_decimal(l_value, r_value)) {
    is_greater = !is_greater;
  } else if (l_value_sign == SIGN_POSITIVE && r_value_sign == SIGN_NEGATIVE &&
             !is_zero) {
    is_greater = true;
  } else if (l_value_sign == SIGN_NEGATIVE && r_value_sign == SIGN_POSITIVE) {
    is_greater = false;
  }
  return is_greater;
}

// если l_value == r_value = 1; иначе 0
int s21_is_equal_big_decimal(s21_big_decimal l_value, s21_big_decimal r_value) {
  s21_exponent_normalize_big_decimal(&l_value, &r_value);

  bool is_equal = true, is_zero = true;
  for (size_t i = 0; i < BIG_DEC_SIZE - 1; i++) {
    is_equal &= l_value.bits[i] == r_value.bits[i];
    is_zero &= l_value.bits[i] == 0 && r_value.bits[i] == 0;
  }
  return is_zero || (is_equal && s21_is_signs_equal(l_value, r_value));
}

// если l_value >= r_value = 1; иначе 0
int s21_is_greater_or_equal_big_decimal(s21_big_decimal l_value,
                                        s21_big_decimal r_value) {
  return s21_is_equal_big_decimal(l_value, r_value) ||
         s21_is_greater_big_decimal(l_value, r_value);
}

// если l_value < r_value = 1; иначе 0
int s21_is_less_big_decimal(s21_big_decimal l_value, s21_big_decimal r_value) {
  return s21_is_greater_big_decimal(r_value, l_value);
}

// если l_value <= r_value = 1; иначе 0
int s21_is_less_or_equal_big_decimal(s21_big_decimal l_value,
                                     s21_big_decimal r_value) {
  return s21_is_equal_big_decimal(l_value, r_value) ||
         s21_is_less_big_decimal(l_value, r_value);
}

// если l_value != r_value = 1; иначе 0
int s21_is_not_equal_big_decimal(s21_big_decimal l_value,
                                 s21_big_decimal r_value) {
  return !s21_is_equal_big_decimal(l_value, r_value);
}

s21_big_decimal s21_div_ten_big_decimal(s21_big_decimal dividend) {
  s21_big_decimal ans = {0};
  s21_big_decimal divisor = (s21_big_decimal){.bits = {10}};

  unsigned exp = s21_get_exponent(dividend);
  bool sign = s21_get_sign_bit(dividend);

  dividend = s21_abs(dividend);
  divisor = s21_abs(divisor);
  s21_set_exponent(&dividend, 0);

  while (s21_is_greater_or_equal_big_decimal(dividend, divisor)) {
    s21_big_decimal shifts = {.bits = {1}};
    s21_big_decimal curr = divisor;
    int small_bro =
        dividend
            .bits[0];  // 10101111 10101111 10101111 11111111 10101111 10101111
                       // 10101111 11111111 10101111 10101111 10101111 (11111111
                       // 10101111 10101111 10101111 11111111)
    s21_right_shift(&dividend,
                    1);  // (0)10101111 10101111 10101111 11111111 10101111
                         // 10101111 10101111 11111111 10101111 10101111
                         // 10101111 11111111 10101111 10101111 10101111 1111111

    while (s21_is_less_or_equal_big_decimal(curr, dividend)) {
      s21_left_shift(&curr, 1);
      s21_left_shift(&shifts, 1);
    }

    s21_left_shift(&dividend,
                   1);  // 10101111 10101111 10101111 11111111 10101111 10101111
                        // 10101111 11111111 10101111 10101111 10101111 11111111
                        // 10101111 10101111 10101111 1111111(0)
    dividend.bits[0] =
        small_bro;  // 10101111 10101111 10101111 11111111 10101111 10101111
                    // 10101111 11111111 10101111 10101111 10101111 (11111111
                    // 10101111 10101111 10101111 11111111)
    s21_arithmetic_big_decimal(ans, shifts, ARITHMETIC_SIGN_POSITIVE, &ans);
    s21_arithmetic_big_decimal(dividend, curr, ARITHMETIC_SIGN_NEGATIVE,
                               &dividend);
  }

  s21_set_sign_bit(&ans, sign);
  s21_set_exponent(&ans, exp);

  return ans;
}

/*
Маштабирует dividend, сводя 4 случая к 1, когда мантиса и экспонента
dividend >= divisor mantissa1, exp1 >= mantissa2 exp2
0       0       1       1
0       1       1       0
1       0       0       1
1       1       0       0    <-
1. normalizemantissa : dvd * 10, dvdexp + 1 while dvdmantis < dvsmantis
mantissa1 exp1 >= mantissa2 exp2
1       0       0       1
1       1       0       0
2. leftexpnormalize : dvd * 10, dvdexp + 1 while dvdexp < dvsexp
mantis1 exp1 >= mantis2 exp2
1       1       0       0
123     0.12345
12300000e-5  12345e-5 =12345 * 10^-5
1230
123e+1 = 123 * 10^1
dvdmantis < dvsmantis || dvdexp < dvsexp
dividend делимое
divisor делитель
*/
unsigned s21_determine_divs(s21_big_decimal *dividend,
                            s21_big_decimal *divisor) {
  unsigned int dvdexp = s21_get_exponent(*dividend);
  unsigned int dvsexp = s21_get_exponent(*divisor);
  unsigned int freeinc = 0;

  s21_set_exponent(dividend, 0);
  s21_set_exponent(divisor, 0);

  while (s21_is_less_big_decimal(BIG_DEC_MANTISSA(dividend),
                                 BIG_DEC_MANTISSA(divisor)) ||
         dvdexp < dvsexp) {
    s21_mul_by_ten_big_decimal(dividend);
    freeinc++;
    dvdexp++;
  }

  s21_set_exponent(dividend, dvdexp);

  return freeinc;
}

s21_big_decimal s21_div_big_decimal(s21_big_decimal dividend,
                                    s21_big_decimal divisor) {
  s21_big_decimal ans = {0};
  s21_big_decimal tmp = divisor;

  unsigned expinc = 0;
  bool sign = !s21_is_signs_equal(dividend, divisor);

  dividend = s21_abs(dividend);
  divisor = s21_abs(divisor);
  s21_determine_divs(&dividend, &divisor);
  int resexp = (int)(s21_get_exponent(dividend) - s21_get_exponent(tmp));
  s21_set_exponent(&dividend, 0);
  s21_set_exponent(&divisor, 0);

  while (expinc <= 29 && !s21_is_bits_zero(&dividend, 0, 6)) {
    while (s21_is_greater_or_equal_big_decimal(dividend, divisor)) {
      s21_big_decimal shifts = {.bits = {1}};
      s21_big_decimal curr = divisor;

      int small_bro = dividend.bits[0];  // 10101111 10101111 10101111 11111111
                                         // 10101111 10101111 10101111 11111111
                                         // 10101111 10101111 10101111 (11111111
                                         // 10101111 10101111 10101111 11111111)
      s21_right_shift(
          &dividend,
          1);  // (0)10101111 10101111 10101111 11111111 10101111 10101111
               // 10101111 11111111 10101111 10101111 10101111 11111111 10101111
               // 10101111 10101111 1111111
      // dec
      // 11111/100
      //  -100|1
      //  -100?2
      //  -100|10
      //  -100|100
      //  -100|111
      // 11100|111
      //    11
      // ans = 111*10^0 + 11*10^-2 = 111.11
      // bin
      // 110111
      // 11011/111
      //  1110|10|2
      //-----------
      //  1101|111
      //   111|1
      //   110
      // 110110+1
      // 110111
      // 11100
      //
      while (s21_is_less_or_equal_big_decimal(curr, dividend)) {
        s21_left_shift(&curr, 1);
        s21_left_shift(&shifts, 1);
      }
      s21_left_shift(
          &dividend,
          1);  // 10101111 10101111 10101111 11111111 10101111 10101111 10101111
               // 11111111 10101111 10101111 10101111 11111111 10101111 10101111
               // 10101111 1111111(0)
      dividend.bits[0] =
          small_bro;  // 10101111 10101111 10101111 11111111 10101111 10101111
                      // 10101111 11111111 10101111 10101111 10101111 (11111111
                      // 10101111 10101111 10101111 11111111)
      s21_arithmetic_big_decimal(ans, shifts, ARITHMETIC_SIGN_POSITIVE, &ans);
      s21_arithmetic_big_decimal(dividend, curr, ARITHMETIC_SIGN_NEGATIVE,
                                 &dividend);
    }

    while (!s21_is_bits_zero(&dividend, 0, 6) &&
           s21_is_less_big_decimal(dividend, divisor)) {
      s21_mul_by_ten_big_decimal(&dividend);
      s21_mul_by_ten_big_decimal(&ans);
      expinc++;
    }
  }

  s21_set_exponent(&ans, (unsigned)(resexp) + expinc);
  s21_set_sign_bit(&ans, sign);

  return ans;
}

s21_big_decimal s21_mul_big_decimal(s21_big_decimal multiplier_l,
                                    s21_big_decimal multiplier_r) {
  s21_big_decimal ans = {0};

  bool sign = !s21_is_signs_equal(multiplier_l, multiplier_r);
  bool skip_zeroes = true;
  unsigned resexp =
      s21_get_exponent(multiplier_l) + s21_get_exponent(multiplier_r);
  /*
   *      1010
   *      1100
   *   1010
   *    1010
   *     0000
   *      0000
   */

  for (int i = DEC_MANTISSA_SIZE - 1; i >= 0; i--) {
    if (!skip_zeroes || s21_get_bit(multiplier_r, i)) {
      skip_zeroes = false;
      bool cur_bit = s21_get_bit(multiplier_r, i);
      if (cur_bit)
        s21_arithmetic_big_decimal(ans, multiplier_l, ARITHMETIC_SIGN_POSITIVE,
                                   &ans);  // 101 -> ans = 1*2^2 + 0*2^1 + 1*2^0
      if (i) s21_left_shift(&ans, 1);
    }
  }

  s21_set_exponent(&ans, resexp);
  s21_set_sign_bit(&ans, sign);

  return ans;
}