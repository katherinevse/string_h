#include <stdarg.h>

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
    char specifiers[] = "dfsgGeExXcuiopn";
    char *src = str;

    va_list arguments;
    va_start(arguments, format);

    while (*format) {
        if (*format == '%') {
            format++;
            Spec specs = {0};
            specs.number_system = 10;
            format = set_specs(&specs, format, &arguments);

            while (!s21_strchr(specifiers, *format)) format++;
            str = read_spec(str, src, format, specs, &arguments);
        } else {
            *str = *format;
            str++;
        }
        format++;
    }
    *str = '\0';
    va_end(arguments);
    return (str - src);
}

const char *get_specs(const char *format, Spec *specs) {
    while (format) {
        if (*format == '+') {
            specs->plus = 1;
        }
        if (*format == '-') {
            specs->minus = 1;
        }
        if (*format == '#') {
            specs->hash = 1;
        }
        if (*format == ' ') {
            specs->space = 1;
        }
        if (*format == '0') {
            specs->full_zero = 1;
        } else
            break;
        format++;
    }

    specs->space = (specs->space && !specs->plus);
    specs->full_zero = (specs->full_zero && !specs->minus);
    return format;
}

const char *get_width(const char *format, int *width, va_list *arguments) {
    *width = 0;
    if (*format == '*') {
        *width = va_arg(*arguments, int);
        format++;
    }

    while (format) {
        if ('0' <= *format && *format <= '9') {
            *width *= 10;
            *width += *format - '0';
        } else
            break;
        format++;
    }
    // точка находится вне
    return format;
}

//-+014.7 проверка set_specs
const char *set_specs(Spec *specs, const char *format, va_list *arguments) {
    format = get_specs(format, specs);
    format = get_width(format, &specs->width, arguments);
    if (*format == '.') {
        specs->dot = 1;
        specs->full_zero = 0;
        format += 1;
        format = get_width(format, &specs->accuracy, arguments);
    }
    if (*format == 'L') specs->length = 'L';
    if (*format == 'l')
        specs->length = 'l';
    else if (*format == '1')
        specs->length = '1';
    else if (*format == 'h')
        specs->length = 'h';
    if (specs->length != 0) format += 1;

    if (specs->width < 0) {
        specs->width = -specs->width;
        specs->minus = 1;
    }
    return format;
}

Spec place_number_system(Spec specs, char format) {
    if (format == 'o')
        specs.number_system = 8;
    else if (format == 'x' || format == 'X')
        specs.number_system = 16;
    if (format == 'X') specs.upper_case = 1;
    return specs;
}

Spec num_sys_double(Spec specs, char format) {
    if (format == 'g' || format == 'G') specs.g = 1;
        // setting registers for upper case and g e
    else if (format == 'e' || format == 'E')
        specs.e = 1;
    if (format == 'G' || format == 'E') specs.upper_case = 1;
    return specs;
}

//СПЕЦИФИКАТОРЫ!
char *read_spec(char *str, char *src, const char *format, Spec specs,
                va_list *arguments) {
//    if (*format == 'c') {
//        int symbol =
//        va_arg(*arguments, int);  // не работает с char или плохо работает
//        str = print_char(str, specs,
//                         symbol);  // не можем просто написать *str =  symbol ;
//    } else if (*format == 'd' || *format == 'i') {
//        str = print_decimal(str, specs, arguments);
//    } else if (*format == 'u' || *format == 'o' || *format == 'x' ||
//               *format == 'X') {
//        specs = place_number_system(specs, *format);
//        // filling the number-system
//        str = spec_print_u(str, specs, *(format - 1), arguments);
//        // transform number in str-format
    if (*format == 's') {
        str = print_s(str, specs, arguments);
    } else if (*format == 'p') {
//        str = print_p(str, &specs, arguments);
    } else if (*format == 'n') {
        int *n = va_arg(*arguments, int *);
        *n = (int)(str - src);
//    } else if (*format == 'f') {
//        specs = num_sys_double(specs, *format);
//        str = print_double(str, specs, *(format - 1), arguments);
//    } else if (*format == 'e' || *format == 'E' || *format == 'g' ||
//               *format == 'G') {
//        specs = num_sys_double(specs, *format);
//        str = print_e_g_double(str, specs, *(format - 1), arguments);
//    } else if (*format == '%') {
//        str = print_char(str, specs, '%');
    } else {
        str = NULL;
    }
    if (!str) *str = '\0';
    return str;
}


char *print_s(char *str, Spec specs, va_list *arguments) {
    char *ptr = str;
    char *string = va_arg(*arguments, char *);

    // усли удалось получить строку
    if (string) {
        int tmp = specs.width, i = 0;

        if ((s21_size_t)specs.width < s21_strlen(string)) {
            specs.width = s21_strlen(string);
        }
        int blank = specs.width - s21_strlen(string);

        if (specs.accuracy == 0) {
            specs.accuracy = specs.width;
        }
        if (specs.accuracy != 0 && specs.accuracy < tmp) {
            blank = tmp - specs.accuracy;
        }
        // заполняем пробелами слева
        while (blank && !specs.minus) {
            *str = ' ';
            str++;
            blank--;
        }
        // посимвольно копируем из переменной string в str
        while (*string != '\0') {
            if (!specs.accuracy) {
                break;
            }
            *str = *string;
            str++;
            string++;
            i++;
            specs.accuracy--;
        }
        //  если был указан флаг - тогда заполняем пробелами справа
        while (blank && specs.minus) {
            *str = ' ';
            str++;
            blank--;
        }
        // если не удалось получить строку из параметра пишем в нашу строку null
    } else {
        str = s21_memcpy(str, "(null)", 6);
        str += 6;
    }
    // присваиваем ptr str и возвращаем его что бы передвинуть указатель строки
    if (ptr) {
        ptr = str;
    }
    return ptr;
}

s21_size_t size_unsigned_decimal(Spec *specs, unsigned long int num) {
    s21_size_t result = 0;             // returning result
    unsigned long int copy_num = num;  // do not want to change num and break it
    while (copy_num > 0) {
        copy_num /= 10;
        result++;  // iterational changing of copy_num to count number of symbols in
        // it
    }
    if (copy_num == 0 && result == 0 &&
        (specs->accuracy || specs->width || specs->space))
        result++;
    // if we have one of these specs, we need to add one place to symbol even
    // result = 0
    if (result < (s21_size_t)specs->width) result = specs->width;
    // if width is bigger we need to get a bigger result to make it equal to width
    if (result < (s21_size_t)specs->accuracy) result = specs->accuracy;
    // analogical to accuracy
    if (specs->space || specs->plus) {
        specs->flag_size = 1;
        result++;
    }  // if we have spec to have additional one place to string or num have '-'
    // in start of it we need to have additional place
    if (result == 0 && copy_num == 0 && !specs->accuracy && !specs->width &&
        !specs->space && !specs->dot)
        result++;
    // if we still have result == 0 and other shit result should be 1 (for ex. we
    // had a number "0")
    return result;
}


char *print_p(char *str, Spec *specs, va_list *arguments) {
    // получаем адрес из аргументов
    unsigned long int ptr =
    (unsigned long int)va_arg(*arguments, unsigned long int);
    // устанавливаем параметры для 16- системы что бы строка имела вид 8х
    specs->number_system = 16;
    specs->hash = 1;
    specs->upper_case = 0;
    s21_size_t size_to_num = size_unsigned_decimal(
            specs, ptr);  //исправлено с size_unsigned_decimal указетель кричит
    char *buffer = malloc(sizeof(char) * size_to_num);
    //get_buf_size_unsigned_decimal
    if (buffer) {
        int i =
                unsigned_decimal_string(buffer, *specs, ptr, size_to_num);  //исправить
        // reversing buffer string to majot str
        for (int j = i - 1; j >= 0; j--) {
            *str = buffer[j];
            str++;
        }
        while (i < specs->width) {
            *str = ' ';
            str++;
            i++;  // i am not sure about this string (188), but i think without it we
            // will have eternal cycle
        }
    }
    if (buffer) free(buffer);
    return str;
}

int decimal_string(Spec specs, long int num, char *str_num,
                   s21_size_t size_decimal) {
    int flag = 0, i = 0;
    if (num < 0) {
        num = -num;
        flag = 1;
    }
    long int copy_num = num;
    i = decimal_string_zeros(specs, num, str_num, size_decimal, i, copy_num,
                             flag);
    // flags '+' '-' ' ' treatment
    i = decimal_string_helper(specs, num, str_num, size_decimal, i);
    return i;
}


