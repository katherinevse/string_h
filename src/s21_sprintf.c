#include<stdarg.h>



typedef struct {
    int minus; //к левому краю
    int plus; //знак
    int space; //+символ под знак
    int hash; // вывод 16 и 8 ричных чисел в формате 0х и 0 соответсвенно
    int full_zero; // заполнить нулями а не пробелами
    int width; // ширина после точки
    int accuracy; // точность
    char length; //тип переменной ld,lf, Lf и тд
    int number_system; // система начисления
    int flag_size; // если число отрицательное или есть + или space
    int dot; // наличие точки, говорит про  accuracy
    int upper_case; // если спецификатор - буква в верхнем
    int g; //спецификатор g
    int e; // если необходимо запиать число в научной
} Spec;


int s21_sprintf(char *str, const char *format, ...){
    char specifiers[] = "dfsgGeExXcuiopn";
    сhar *src = str; //изначальное положение str записываем в src чтобы узнать кол-во записанных символов

    va_list arguments; // считывание ..., записываются туда переменные
    va_start(arguments,format); // в формат записываем последнюю известную переменную


    while (*format){
        if(*format == '%'){
            format++;
            Spec specs = {0};
            specs.number_system = 10; //десятичная система счисления
            format = set_specs(&specs, format, &arguments);


        } else{
            *str = *format;
            str++;
        }
        format++




    }




    va_end(arguments);










    return(str-src); //возвращаем кол-во записанных символов
}

const char *get_specs(const char *format,Spec *specs){
    while(format){
        if(*format =='+'){
            specs->plus = 1;
        }
        if(*format == '-'){
            specs->minus = 1
        }
        if(*format =='#'){
            specs->hash = 1;
        }
        if(*format ==' '){
            specs->space = 1;
        }
        if(*format =='0'){
            specs->full_zero = 1;
        } else
            break;
        format++;
    }

}

const char *set_specs(Spec *specs, const char *format, va_list *arguments){
    format = get_specs(format,specs);



}