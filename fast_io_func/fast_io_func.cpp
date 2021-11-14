// fast_io_func.cpp: определяет точку входа для приложения.
//

#include "fast_io_func.h"

/*fast print int numbers*/
template <typename T>
void print(T num) 
{
    if (num == 0) {
        putchar('0');
        return;
    }

    //neg sign of number
    bool neg_sign = num < 0;
    num = num * ((neg_sign) ? -1 : 1);

    T reverse_num = 0;
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
}

/*fast scan int numbers*/
template <typename T>
int scan(T& number) 
{
    T value = 0;
    bool sign = true, is_exit = false, is_fail = false;
    do {
        char s = getchar();
        if ((s >= '0' && s <= '9'))
        {
            value = value * 10 + (s - '0');
        }
        else if (s == '-' && sign) 
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

	return 0;
}
