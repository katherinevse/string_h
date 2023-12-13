LFLAGS= -lcheck
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c11
GCOV_FLAGS=-lgcov --coverage
CC=gcc


# Определение переменной для идентификации текущей операционной системы
UNAME_S := $(shell uname -s)

# Параметры компиляции для разных операционных систем
ifeq ($(UNAME_S),Linux)
    LFLAGS += -L. libs21_string.a -lm -lsubunit
endif

.PHONY: clean all rebuild

all: s21_string.a

test: libs21_string.a s21_string_tests.o
	$(CC) $^ $(LFLAGS) -o $@

gcov_report: s21_string.c s21_string_tests.c  s21_sprintf.c libs21_string.a
	$(CC) $(CFLAGS) $^ $(LFLAGS) $(GCOV_FLAGS)
	./a.out
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report

libs21_string.a: s21_string.a
	mv s21_string.a libs21_string.a

s21_string.a: s21_string.o s21_sprintf.o
	ar -rcs $@ $^

s21_string.o: s21_string.c 
	$(CC) -c $(CFLAGS) $^
	
s21_sprintf.o: s21_sprintf.c
	$(CC) -c $(CFLAGS) $^

s21_string_tests.o: s21_string_tests.c
	$(CC) -c $(CFLAGS) $^

clean:
	rm -rf *.o test gcov_report *.gcda *.gcno coverage.info *.a a.out

rebuild: clean all


man:
	$(CC) -g s21_string.c s21_sprintf.c test.c -o test