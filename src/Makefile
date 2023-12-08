CC = gcc -g
CFLAGS = -Wall -Werror -Wextra
GCOV_FLAG = --coverage
CHECK_FLAG = -lcheck
SOURCES = s21_string_tests.c s21_string.c

all:
	$(CC) $(CFLAGS) s21_sprintf.c s21_string.c

check:
	clang-format -n *.c *.h

style:
	clang-format -i *.c *.h
	
test:
	rm -rf a.out    
	$(CC) $(CFLAGS) s21_string.c s21_string_tests.c s21_sprintf.c -lcheck

gcov_report:	$(SOURCES)
	$(CC) $(SOURCES)	$(CHECK_FLAG)	$(COV_FLAG)
	
clean:
	rm -rf s21_sprintf

rebuild:
	make clean
	make all