.PHONY: all clean test clang

CC := gcc
CC_FLAGS := -Wall -Werror -Wextra -pedantic -std=c11 -Iheaders
GCOVR := gcovr
GCOVR_FLAGS := --html --html-details --html-medium-threshold 79.9 --html-high-threshold 80.0
COV_FLAGS = -fprofile-arcs -ftest-coverage -fPIC --coverage

CF := clang-format
CF_FLAGS := -n -style='{BasedOnStyle: Google}'

VG := valgrind
VG_FLAGS := --tool=memcheck --leak-check=full --show-leak-kinds=all

SRC := $(wildcard arithmetic/s21_*.c conversion/s21_*.c comparison/s21_*.c other/s21_*.c helpers/s21_*.c)
HEADER := $(wildcard ./s21_decimal.h headers/s21_*.h)
OBJ := $(patsubst %.c, %.o, $(SRC))
TEST_DIR := tests
TEST_SRC := $(wildcard $(TEST_DIR)/s21_*.c)
TEST_HEADER := $(wildcard $(TEST_DIR)/s21_*.h)
TEST_TARGET := s21_decimal_tests

RM := rm -rf
KERNEL := $(shell uname -s)

ifeq ($(KERNEL), Linux)
	LIBS := -lcheck -lrt -lsubunit -lm -lcheck_pic
endif

ifeq ($(KERNEL), Darwin)
	LIBS := -lcheck
endif

all: clean s21_decimal.a test

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@ $(LIBS)

s21_decimal.a: $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

test: $(SRC) $(TEST_SRC) s21_decimal.a
	$(CC) $(CC_FLAGS) -g $(COV_FLAGS) $^ -o $(TEST_DIR)/$(TEST_TARGET) $(LIBS)
	$(RM) *.o
	./$(TEST_DIR)/$(TEST_TARGET)
	$(RM) $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno

test_gcov: $(SRC) $(TEST_SRC) s21_decimal.a
	$(CC) $(CC_FLAGS) -g $(COV_FLAGS) $^ -o $(TEST_DIR)/$(TEST_TARGET) $(LIBS)
	./$(TEST_DIR)/$(TEST_TARGET)
	$(RM) *.o $(TEST_DIR)/*_test.gcno $(TEST_DIR)/*_test.gcda $(TEST_DIR)/*_tests.gcno $(TEST_DIR)/*_tests.gcda

gcov_report: clean test_gcov
	mkdir $@
	$(GCOVR) -d $(TEST_DIR) $(GCOVR_FLAGS) -o $@/report.html
	$(RM) $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno

clang: $(SRC) $(HEADER) $(TEST_SRC) $(TEST_HEADER)
	$(CF) $(CF_FLAGS) $^

clean:
	$(RM) $(OBJ) $(TEST_DIR)/*.o \
	$(TEST_DIR)/$(TEST_TARGET) \
	*.gcno $(TEST_DIR)/*.gcno *.gcda $(TEST_DIR)/*.gcda \
	gcov_report \
	*.a

valgrind: clean test $(TEST_DIR)/$(TEST_TARGET)
	$(VG) $(VG_FLAGS) ./$(TEST_DIR)/$(TEST_TARGET)