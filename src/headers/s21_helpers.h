#ifndef S21_HELPERS_H
#define S21_HELPERS_H

#include "../s21_decimal.h"
#include "s21_helpers_generics.h"

void s21_decimal_reset(s21_decimal *result, int start_index);

bool __get_bit_decimal(s21_decimal value, unsigned int bit_index);
bool __get_bit_big_decimal(s21_big_decimal value, unsigned int bit_index);

bool __get_sign_bit_decimal(s21_decimal value);
bool __get_sign_bit_big_decimal(s21_big_decimal value);

void __set_bit_decimal(s21_decimal *value, unsigned int bit_index,
                       unsigned int bit_value);
void __set_bit_big_decimal(s21_big_decimal *value, unsigned int bit_index,
                           unsigned int bit_value);

void __set_sign_bit_decimal(s21_decimal *value, bool bit_value);
void __set_sign_bit_big_decimal(s21_big_decimal *value, bool bit_value);

unsigned int __get_exponent_decimal(s21_decimal value);
unsigned int __get_exponent_big_decimal(s21_big_decimal value);

void __set_exponent_decimal(s21_decimal *value, unsigned int exp);
void __set_exponent_big_decimal(s21_big_decimal *value, unsigned int exp);

int s21_is_signs_equal(s21_big_decimal value_1, s21_big_decimal value_2);

s21_decimal __abs_decimal(s21_decimal value);
s21_big_decimal __abs_big_decimal(s21_big_decimal value);
void s21_arithmetic_big_decimal(s21_big_decimal value_1,
                                s21_big_decimal value_2, int sign,
                                s21_big_decimal *result);
void s21_mul_by_ten_big_decimal(s21_big_decimal *value);
int s21_is_greater_big_decimal(s21_big_decimal l_value,
                               s21_big_decimal r_value);
int s21_is_equal_big_decimal(s21_big_decimal l_value, s21_big_decimal r_value);
int s21_is_not_equal_big_decimal(s21_big_decimal l_value,
                                 s21_big_decimal r_value);
int s21_is_greater_or_equal_big_decimal(s21_big_decimal l_value,
                                        s21_big_decimal r_value);
int s21_is_less_big_decimal(s21_big_decimal l_value, s21_big_decimal r_value);
int s21_is_less_or_equal_big_decimal(s21_big_decimal l_value,
                                     s21_big_decimal r_value);

s21_big_decimal s21_even_round_big_decimal(s21_big_decimal value_1,
                                           s21_big_decimal value_2);
s21_big_decimal s21_com_round_big_decimal(s21_big_decimal value_1,
                                          s21_big_decimal value_2);
void s21_round_after_mantis_overflow(s21_big_decimal *src);

void s21_exponent_normalize_big_decimal(s21_big_decimal *value_1,
                                        s21_big_decimal *value_2);

void __left_shift_big_decimal(s21_big_decimal *value, unsigned int shift);

void __right_shift_big_decimal(s21_big_decimal *value, unsigned int shift);

void s21_from_decimal_to_big_decimal(s21_decimal src, s21_big_decimal *dst);
int s21_from_big_decimal_to_decimal(s21_big_decimal src, s21_decimal *dst);
void s21_decrease_big_decimal_to_decimal(s21_big_decimal src, s21_decimal *dst);
void s21_swap_decimal(s21_decimal *value_1, s21_decimal *value_2);
int s21_arithmetic_error_code(s21_big_decimal *src);
s21_big_decimal s21_scaling_big_decimal(s21_big_decimal *src, unsigned int *exp,
                                        unsigned int range);
bool s21_is_bits_zero(s21_big_decimal *src, unsigned int r_min,
                      unsigned int r_max);
bool s21_is_mantissas_equal_decimal(s21_decimal *l_value, s21_decimal *r_value);
bool s21_is_mantissas_equal_big_decimal(s21_big_decimal *l_value,
                                        s21_big_decimal *r_value);

s21_big_decimal s21_div_big_decimal(s21_big_decimal dividend,
                                    s21_big_decimal divisor);
s21_big_decimal s21_div_ten_big_decimal(s21_big_decimal dividend);
unsigned s21_determine_divs(s21_big_decimal *dividend,
                            s21_big_decimal *divisor);

s21_big_decimal s21_mul_big_decimal(s21_big_decimal multiplier_l,
                                    s21_big_decimal multiplier_r);

int s21_exp_from_str(char *str);
s21_decimal s21_decimal_from_char(char c);
s21_decimal s21_str_to_decimal(char *str);
s21_decimal s21_pow_ten_decimal(int digits_counter);

#endif