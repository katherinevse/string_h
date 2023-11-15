


typedef struct {
    int minus; //к левому краю
    int plus; //знак
    int space_plus; //+символ под знак
    int hash; // вывод 16 и 8 ричных чисел в формате 0х и 0 соответсвенно
    int full_zero; // заполнить нулями а не пробелами
    int width; // ширина после точки я так понимаю
    int accuracy; // точность
    char length; //тип переменной ld,lf, Lf и тд
    int number_system;
    int flag_size;
    int dot;
    int upper_case;
    int g;
    int e;
} Spec;

