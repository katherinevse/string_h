CC = gcc
CFLAGS = -Wall -Werror -Wextra
GCOV_FLAG = --coverage
CHECK_FLAG = -lcheck
SOURCES = s21_string_tests.c s21_string.c
LIB_NAME = s21_string.a

# Определение переменной для идентификации текущей операционной системы
UNAME_S := $(shell uname -s)

# Параметры компиляции для разных операционных систем
ifeq ($(UNAME_S),Linux)
    CFLAGS += -DLINUX
endif

all: $(LIB_NAME)

$(LIB_NAME): $(SOURCES:.c=.o)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

check:
	clang-format -n *.c *.h

style:
	clang-format -i *.c *.h

test: $(LIB_NAME)
	rm -rf test_executable
	$(CC) $(CFLAGS) s21_string_tests.c $(LIB_NAME) -o test_executable $(CHECK_FLAG)
	./test_executable

gcov_report: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) $(CHECK_FLAG) $(GCOV_FLAG)
	./test_executable
	gcov $(SOURCES)

clean:
	rm -rf *.o *.a test_executable *.gcov *.gcda *.gcno

rebuild:
	make clean
	make all
