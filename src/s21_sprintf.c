


typedef struct {
    int minus; //к левому краю
    int plus; //знак
    int space_plus; //+символ под знак
    int hash; // вывод 16 и 8 ричных чисел в формате 0х и 0 соответсвенно
    int full_zero; // заполнить нулями а не пробелами
    int width; // ширина после точки я так понимаю
    int accuracy; // точность
    char length; //тип переменной ld,lf, Lf и тд
    int number_system; // система начисления
    int flag_size; // если число отрицательное или есть + или space
    int dot; // наличие точки, говорит про  accuracy
    int upper_case; // если спецификатор - буква в верхнем
    int g; //спецификатор g
    int e; // если необходимо запиать число в научной
} Spec;

