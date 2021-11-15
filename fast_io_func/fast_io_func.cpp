// fast_io_func.cpp: определяет точку входа для приложения.
//

#include "fast_io_func.h"

/*fast print int numbers*/
template <typename T>
void print(T num) 
{
    static_assert(std::is_integral_v<T>, "Supports only integer types");
    if (num == 0) {
        putchar('0');
        return;
    }

    //neg sign of number
    bool neg_sign = num < 0;
    num = num * ((neg_sign) ? -1 : 1);

    T reverse_num = 0;

    /*multply of 10*/
    int zero_cnt = 0;
    T num_copy = num;
    while (num_copy % 10 == 0) 
    {
        ++zero_cnt;
        num_copy /= 10;
    }

    //reverse number
    while (num) 
    {
        reverse_num = reverse_num*10 + num % 10;
        num /= 10;
    }

    //minus
    if (neg_sign) 
    {
        putchar('-');
    }

    while (reverse_num) 
    {
        putchar('0' + reverse_num % 10);
        reverse_num /= 10;
    }

    for (int i = 0; i < zero_cnt; ++i) 
    {
        putchar('0');
    }
}

/*fast scan int numbers*/
template <typename T>
int scan(T& number) 
{
    static_assert(std::is_integral_v<T>, "Supports only integer types");
    T value = 0;
    bool sign = true, is_exit = false, is_fail = false, is_first = true;
    do {
        char s = getchar();
        if ((s >= '0' && s <= '9'))
        {
            value = value * 10 + (s - '0');
        }
        else if (s == '-' && sign && is_first) 
        {
            sign = false;
        }
        else if (s == ' ' || s == '\n')
        {
            is_exit = true;
        }
        else
        {
            is_fail = true;
        }
        is_first = false;
    } while (!is_exit);

    if (!sign) 
    {
        value *= -1;
    }

    if (is_fail) {
        /*0 success entering numbers*/
        return 0;
    }
    number = value;

    /*success of entering one number*/
    return 1;
}

int main(int argc, char** args)
{
    //Test int
    printf("Test int numbers:\n");
    print(123456789);
    putchar('\n');
    print(0);
    putchar('\n');
    print(-123456);
    putchar('\n');
    putchar('\n');

    //Test uint
    printf("Test uint numbers:\n");
    print(42u);
    putchar('\n');
    print(0u);
    putchar('\n');
    size_t t = 64;
    print(t);
    putchar('\n');
    putchar('\n');

    /*Test scan*/
    printf("Test scan numbers:\n");
    int a;
    while (scan(a) == 0)
    {
        printf("Incorrect input! Try again\n");
    }
    printf("You input: ");
    print(a);
    putchar('\n');

    //print("Hello");
    return 0;
}
