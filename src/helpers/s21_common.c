#include "../headers/s21_helpers.h"

void s21_decimal_reset(s21_decimal *result, int start_index) {
  for (size_t i = start_index; i < DEC_SIZE; i++) {
    result->bits[i] = 0;
  }
}

void s21_exponent_normalize_big_decimal(s21_big_decimal *value_1,
                                        s21_big_decimal *value_2) {
  unsigned int value_1_exp = s21_get_exponent(*value_1);
  unsigned int value_2_exp = s21_get_exponent(*value_2);
  if (value_2_exp < value_1_exp) {
    s21_set_exponent(value_2, value_1_exp);
    while (value_2_exp++ != value_1_exp) {
      s21_mul_by_ten_big_decimal(value_2);
    }
  } else if (value_1_exp < value_2_exp) {
    s21_set_exponent(value_1, value_2_exp);
    while (value_1_exp++ != value_2_exp) {
      s21_mul_by_ten_big_decimal(value_1);
    }
  }
}

void s21_from_decimal_to_big_decimal(s21_decimal src, s21_big_decimal *dst) {
  for (int i = 0; i < BIG_DEC_SIZE - 1; i++) {
    if (i < DEC_SIZE - 1) {
      dst->bits[i] = src.bits[i];
    } else {
      dst->bits[i] = 0;
    }
  }
  dst->bits[BIG_DEC_SIZE - 1] = src.bits[DEC_SIZE - 1];
}

void s21_decrease_big_decimal_to_decimal(s21_big_decimal src,
                                         s21_decimal *dst) {
  for (size_t i = 0; i < DEC_SIZE - 1; i++) dst->bits[i] = src.bits[i];
  dst->bits[DEC_SIZE - 1] = src.bits[BIG_DEC_SIZE - 1];
}

int s21_from_big_decimal_to_decimal(s21_big_decimal src, s21_decimal *dst) {
  int error_code = s21_arithmetic_error_code(&src);
  if (error_code == 0) s21_decrease_big_decimal_to_decimal(src, dst);
  return error_code;
}

void s21_round_after_mantis_overflow(s21_big_decimal *src) {
  unsigned exp = s21_get_exponent(*src);
  if (!s21_is_bits_zero(src, 3, 6) && exp > 0) {
    s21_big_decimal tmp = *src;
    *src = s21_div_ten_big_decimal(*src);
    s21_set_exponent(src, exp - 1);
    *src = s21_even_round_big_decimal(*src, tmp);
  }
}

void s21_bank_round_big_decimal(s21_big_decimal *src,            // 0.4
                                s21_big_decimal *origin_src,     // 0.45555
                                s21_big_decimal *prev_value2) {  // 0.45
  s21_big_decimal res = *src;
  s21_exponent_normalize_big_decimal(origin_src, &res);
  s21_arithmetic_big_decimal(*origin_src, res, ARITHMETIC_SIGN_NEGATIVE, &res);
  s21_big_decimal five = {.bits = {5}};
  if (s21_is_mantissas_equal_big_decimal(&res, &five))
    *src = s21_even_round_big_decimal(*src, *prev_value2);
  else
    *src = s21_com_round_big_decimal(*src, *prev_value2);
}

// Не вызывать округление, если value_1 == value_2
s21_big_decimal s21_even_round_big_decimal(s21_big_decimal value_1,
                                           s21_big_decimal value_2) {
  s21_big_decimal limit_value = {.bits = {5}};
  s21_big_decimal tmp = value_1;
  s21_set_exponent(&tmp, s21_get_exponent(value_1) + 1);
  s21_mul_by_ten_big_decimal(&tmp);
  s21_arithmetic_big_decimal(value_2, tmp, -1, &value_2);
  s21_set_exponent(&limit_value, s21_get_exponent(value_2));
  if (s21_is_greater_big_decimal(value_2, limit_value)) {
    s21_arithmetic_big_decimal(value_1, (s21_big_decimal){.bits = {1}}, 1,
                               &value_1);
  } else if (s21_is_equal_big_decimal(value_2, limit_value)) {
    if (s21_get_bit(value_1, 0) == 1) {
      s21_arithmetic_big_decimal(value_1, (s21_big_decimal){.bits = {1}}, 1,
                                 &value_1);
    }
  }

  return value_1;
}

// Не вызывать округление, если value_1 == value_2
s21_big_decimal s21_com_round_big_decimal(s21_big_decimal value_1,
                                          s21_big_decimal value_2) {
  s21_big_decimal limit_value = {.bits = {5}};
  s21_big_decimal tmp = value_1;
  s21_set_exponent(&tmp, s21_get_exponent(value_1) + 1);
  s21_mul_by_ten_big_decimal(&tmp);
  s21_arithmetic_big_decimal(value_2, tmp, -1, &value_2);
  s21_set_exponent(&limit_value, s21_get_exponent(value_2));
  if (s21_is_greater_or_equal_big_decimal(value_2, limit_value)) {
    s21_arithmetic_big_decimal(value_1, (s21_big_decimal){.bits = {1}}, 1,
                               &value_1);
  }

  return value_1;
}

int s21_arithmetic_error_code(s21_big_decimal *src) {
  int error_code = OK;
  unsigned exp = s21_get_exponent(*src);
  s21_big_decimal prev_value1 = *src;
  s21_big_decimal origin_src = *src;
  if (exp >= 28) {
    prev_value1 = s21_scaling_big_decimal(src, &exp, DEC_MAX_EXP);
    if (s21_is_bits_zero(src, 0, 6)) {
      error_code += AO_SMALL_NUMBER;
    }
  }
  s21_big_decimal prev_value2 = s21_scaling_big_decimal(src, &exp, DEC_MIN_EXP);
  if (!s21_is_equal_big_decimal(*src, prev_value2)) {
    s21_bank_round_big_decimal(src, &origin_src, &prev_value2);
    s21_round_after_mantis_overflow(src);
  } else if (s21_get_exponent(*src) + 1 == s21_get_exponent(prev_value1) &&
             !s21_is_equal_big_decimal(*src, prev_value1)) {
    *src = s21_com_round_big_decimal(*src, prev_value1);
    s21_round_after_mantis_overflow(src);
  }

  if (!s21_is_bits_zero(src, 3, 6)) {
    error_code = AO_BIG_NUMBER;
  }
  return error_code;
}

void s21_swap_decimal(s21_decimal *value_1, s21_decimal *value_2) {
  s21_decimal tmp = *value_1;
  *value_1 = *value_2;
  *value_2 = tmp;
}

int s21_is_signs_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
  return s21_get_sign_bit(value_1) == s21_get_sign_bit(value_2);
}
// 😁😁😁😁😁
s21_big_decimal s21_scaling_big_decimal(s21_big_decimal *src, unsigned int *exp,
                                        unsigned int range) {
  s21_big_decimal value = *src;
  unsigned r_min = range == 0 ? 3 : 0;
  unsigned r_max = 6;
  while (!s21_is_bits_zero(src, r_min, r_max)) {
    if (*exp == range) break;
    value = *src;
    s21_set_exponent(&value, *exp);
    *src = s21_div_ten_big_decimal(*src);
    --(*exp);
  }
  s21_set_exponent(src, *exp);
  return value;
}

bool s21_is_bits_zero(s21_big_decimal *src, unsigned int r_min,
                      unsigned int r_max) {
  bool res = true;
  for (unsigned int i = r_min; i <= r_max; i++)
    if (src->bits[i] != 0) res = false;
  return res;
}

bool s21_is_mantissas_equal_decimal(s21_decimal *l_value,
                                    s21_decimal *r_value) {
  bool res = true;
  for (unsigned int i = 0; i <= 2; i++)
    if (l_value->bits[i] != r_value->bits[i]) res = false;
  return res;
}

bool s21_is_mantissas_equal_big_decimal(s21_big_decimal *l_value,
                                        s21_big_decimal *r_value) {
  bool res = true;
  for (unsigned int i = 0; i <= 6; i++)
    if (l_value->bits[i] != r_value->bits[i]) res = false;
  return res;
}

/*
    Получаем степень числа float в виде строки в научной нотации
    Например:
    1.435412E-04 - получим -4
    1.435412E+03 - получим 3
    Если получить степень  не получится, то функция вернет 0
*/
int s21_exp_from_str(char *str) {
  int result = 0;
  char *ptr = str;
  while (*ptr++) {
    if (*ptr == 'E') {
      ptr++;
      result = strtol(ptr, NULL, 10);
      break;
    }
  }
  return result;
}

/*
Переводит строку с научной нотацией float в decimal.
Научная нотация должна содержать не более 6 цифр после запятой
Например:
5.123456E+2 - обрабатываем каждую цифру и прибавляем к результату:
result = 0;
5: result += 5 * 1000000
1: result += 1 * 100000
2: result += 2 * 10000
3: result += 3 * 1000
4: result += 4 * 100
5: result += 5 * 10
6: result += 6 * 1
Итого: 5123456

Далее корректируем decimal, анализируя степень float (умножая или деля decimal):
5123456 / 10000 = 512.3456
Если float содержит меньше цифр, то:
5.1E+2 - обрабатываем каждую цифру и прибавляем к результату:
result = 0;
5: result += 5 * 1000000
1: result += 1 * 100000
Итого: 5100000
Корректируем decimal:
5100000 / 10000 = 510.0000

Валидация данных не осуществляется.
На вход поступают уже проверенные данные из диапазона представимых в decimal
чисел
*/
s21_decimal s21_str_to_decimal(char *str) {
  int digits_counter = 6;
  s21_decimal result = {0};
  char *ptr = str;

  // Получаем заново степень float из научной записи, а не передаем полученную
  // ранее в s21_from_float_to_decimal, т.к. она могла измениться из-за
  // округления
  int exp = s21_exp_from_str(str);

  while (*ptr != 'E') {
    if (*ptr == '.') {
      // Точку игнорируем, итоговую степень decimal мы будем отдельно считать
      ptr++;
    } else if (*ptr >= '0' && *ptr <= '9') {
      // Переводим цифры в строке в decimal, начиная с первой, используя
      // арифметику decimal
      s21_decimal tmp = {0};
      s21_mul(s21_decimal_from_char(*ptr), s21_pow_ten_decimal(digits_counter),
              &tmp);
      s21_add(result, tmp, &result);
      digits_counter--;
      ptr++;
    }
  }
  // Учитываем, что в научной записи степень уже сдвинута, чтобы далее корректно
  // выставить степень decimal
  exp -= 6;

  if (exp > 0) {
    // Для положительной степени производим умножение на 10^exp
    s21_mul(result, s21_pow_ten_decimal(exp), &result);
  } else if (exp < 0) {
    // Для отрицательной степени производим деление на 10^exp
    if (exp < -28) {
      // Отдельно обрабатываем очень маленькие степени, т.к. мы не сможем
      // поделить больше чем на 10^28
      s21_div(result, s21_pow_ten_decimal(28), &result);
      exp += 28;
    }
    s21_div(result, s21_pow_ten_decimal(-exp), &result);
  }

  return result;
}

/*
    Возвращает число в виде decimal, соответствующее цифре в виде char
    Допустимые значения char c: '0' - '9'
    Валидация данных не осуществляется и должна происходить за пределами функции
*/
s21_decimal s21_decimal_from_char(char c) {
  s21_decimal result = {0};
  int i = c - '0';
  s21_from_int_to_decimal(i, &result);
  return result;
}

s21_decimal s21_pow_ten_decimal(int digits_counter) {
  s21_decimal tmp = {.bits = {1}};
  for (int i = digits_counter; i > 0; i--) {
    s21_mul(tmp, (s21_decimal){.bits = {10}}, &tmp);
  }
  return tmp;
}