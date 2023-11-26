#include "s21_string.h"

//s21_sprintf(str1, "hello %-14d %d", 148, 56);
int s21_sprintf(char *str, const char *format, ...) {
    char specifiers[] = "dfsgGeExXcuiopn";
    char *src = str; 

    va_list arguments;  // считывание ..., записываются туда переменные
    va_start(arguments, format);  // после  format

    while (*format) {
        if (*format == '%') {
            format++;
            Spec specs = {0};
            specs.number_system = 10;  // десятичная система счисления
            format = set_specs(&specs, format, &arguments); // все распарсить

            while (!s21_strchr(specifiers, *format)) format++; // ищем спецификатор
            str = read_spec(str,src, format, specs, &arguments);
        } else {
            *str = *format;
            str++;
        }
        format++;
    }
    *str = '\0';
    va_end(arguments);
    return (str - src);  // возвращаем кол-во записанных символов
}
// проверка между % и спецификатором
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
    // не может быть одновременно и плюс и пробел
    specs->space = (specs->space && !specs->plus); //зануляем
    specs->full_zero = (specs->full_zero && !specs->minus); // ноль и минус
    return format;
}

const char *get_width(const char *format, int *width, va_list *arguments) {
    *width = 0;
    // ширина через звездочку
    if (*format == '*') {
        *width = va_arg(*arguments, int);
        format++;
    }
    //преобразовываем из char в int
    //потом доходим до точности(точка) -> выходим из цикла
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

//-+014.7 проверка 
const char *set_specs(Spec *specs, const char *format, va_list *arguments) {
    format = get_specs(format, specs);
    format = get_width(format, &specs->width, arguments);
    if (*format == '.') {
        specs->dot = 1;
        specs->full_zero = 0;  // не может быть одновременно и точность и ноль
        format += 1;           //????
        format = get_width(format, &specs->accuracy, arguments);  // 2 аргумент почему такой?
    }
    if (*format == 'L')
        specs->length = 'L';
    if (*format == 'l')
        specs->length = 'l';
    else if (*format == '1')
        specs->length = '1';
    else if (*format == 'h')
        specs->length = 'h';
    if (specs->length != 0) format += 1;

//    if (specs->width < 0) {
//        specs->width = -specs->width;
//        specs->minus = 1;
//    }
    return format;
}

//СПЕЦИФИКАТОРЫ!
char *read_spec(char *str, char *src, const char *format, Spec specs, va_list *arguments) {
  if (*format == 'd' || *format == 'i') {
    str = print_decimal(str, specs, arguments);
  } else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X') {
    specs = set_number_system(specs, *format);
    str = print_u(str, specs, *(format - 1), arguments);
  } else if (*format == 'c') {
    int symbol = va_arg(*arguments, int);
    str = print_char(str, specs, symbol);
  } else if (*format == 's') {
    str = print_s(str, specs, arguments);
  } else if (*format == 'p') {
    str = print_p(str, &specs, arguments);
  } else if (*format == 'n') {
    int *n = va_arg(*arguments, int *);
    *n = (int)(str - src);
  } else if (*format == 'f' || *format == 'F') {
    specs = set_num_sys_double(specs, *format);
    str = print_double(str, specs, *(format - 1), arguments);
  } else if (*format == 'e' || *format == 'E' || *format == 'g' ||
             *format == 'G') {
    specs = set_num_sys_double(specs, *format);
    str = print_e_g(str, specs, *(format - 1), arguments);
  } else if (*format == '%') {
    str = print_c(str, specs, '%');
  } else {
    str = NULL;
  }
  if (!str) *str = '\0';
  return str;
}

const char* print_char(char *str,Spec specs,int symbol){
    char *ptr = S21_NULL;
    int i = 0; //подсчет символов 

    //проверка на ширину и минус 
    while(specs.width - 1 > 0 && !specs.minus) { 
        *str = ' ';
        str++;
        i++;
        specs.width--;
    }
    if (symbol <= 127)
    {
        *str = symbol;
        str++;
        i++;
        while (specs.width - 1 > 0 && specs.minus){
            *str = ' ';
            str++;
            i++;
            specs.width--;
        }
        ptr = str; 
    }
    return ptr;
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

char *print_p(char *str, Spec *specs, va_list arguments) {
  // получаем адрес из аргументов
  unsigned long int ptr =
      (unsigned long int)va_arg(arguments, unsigned long int);
  // устанавливаем параметры для 16- системы что бы строка имела вид 8х
  specs->number_system = 16;
  specs->hash = 1;
  specs->upper_case = 0;

  s21_size_t size_to_num = get_buf_size_unsigned_decimal(*specs, ptr);
  char *buffer = malloc(sizeof(char) * size_to_num);
  if (buffer) {
    int i = unsigned_decimal_to_string(buffer, *specs, ptr, size_to_num);
    str += add_buffer_to_string(specs->width, &i, buffer, str);
  }
  if (buffer) free(buffer);
  return str;
}

char spec_print_u(char *str, Spec specs, char format, va_list *arguments) {
    unsigned long int num = 0;
    //по типу переменной разбираем текущий спецификатор (long, short, int) with "unsigned" word
    if (format == 'l') num = (unsigned long int)va_arg(*arguments,unsigned long int);
    else if (format == 'h') num = (unsigned short int)va_arg(*arguments,unsigned short);
    else num = (unsigned int)va_arg(*arguments,unsigned int);

    s21_size_t size_num = size_unsigned_decimal(&specs, num); //почему такой размер? 
    char *buf_str = malloc(sizeof(char) * size_num); //указатель на какой-то участок памяти 
    if (buf_str) {
        int i = decimal_string(buf_str, specs, num, size_num);
        //reversing buffer string to majot str
        for (int j = i - 1; j >= 0; j--) {
            *str = buf_str[j];
            str++;
        }
        while (i < specs.width) {
            *str = ' ';
            str++;
            i++;//i am not sure about this string (188), but i think without it we will have eternal cycle
        }
    }
    if (buf_str) free(buf_str);
    return str;
}


//подсчет, сколько памяти под аргумент в str1
int decimal_string(char *buf_str,Spec specs, unsigned long int num,s21_size_t size_num) {
    int flag = 0,
    i = 0; //для чего нам нжуен i???
    if (specs.hash && specs.number_system == 8) specs.flag_size = 1;
    //review of # spec and number-system
    else if (specs.hash && specs.number_system == 16) specs.flag_size = 2;
    long int copy_num = num;
    i = decimal_string_zeros(specs, num, buf_str, size_num, i, copy_num, flag);
    //flags '+' '-' ' ' treatment
    i = unsigned_decimal_string_helper(specs, num, buf_str, size_num, i);
    return i;
}

//???
int decimal_string_zeros(Spec specs, long int num, char *str_num, s21_size_t size_decimal, int i, int copy_num, int flag) {
    //printing number in a mass if it is 0
    if (((copy_num == 0) && (specs.accuracy || specs.width || specs.space)) || (copy_num == 0 && !specs.accuracy && !specs.width && !specs.space && !specs.dot)) {
        char symbol = copy_num % specs.number_system + '0';
        //transforming num to sym by dividing to numerical system and adding 0 symbol
        str_num[i] = symbol;
        i++;
        size_decimal--;
        copy_num /= 10;
    }
    //printing number in a mass if it is not 0
    while (copy_num && str_num && size_decimal) {
        char symbol = get_num_char(copy_num % specs.number_system, specs.upper_case);
        str_num[i] = symbol;
        i++;
        size_decimal--;
        copy_num /= 10;
    }
    if (flag) num = -num;
    //at the start of func we had a flag to negative number
    //flag '0' treatment review
    if (specs.accuracy > i) {//accuracy is bigger than number of already printed numbers in str
        specs.accuracy -= i;
        specs.full_zero = 1;
    }
    else flag = 1;
    //if we don't have place for zeros turning off flag '0'
    if (size_decimal == 1 && specs.full_zero == 1 && specs.flag_size == 1) specs.full_zero = 0;
    //flag '0' treatment
    while (specs.full_zero && str_num && (size_decimal - specs.flag_size > 0) && (specs.accuracy || flag)) {
        if (size_decimal == 1 && specs.flag_size == 1) break;
        str_num[i] = '0';
        i++;
        size_decimal--;
        specs.accuracy--;
    }
    return i;
}




