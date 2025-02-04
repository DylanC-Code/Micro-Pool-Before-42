#include <time.h>
#include <stdlib.h>
#include <stdio.h>

double double_between_0_and_1()
{
    srand(time(NULL));
    return (double)rand() / RAND_MAX;
}

// --------- //
// FACTORIAL //
// --------- //

int factorial_iterative(int num)
{
    int result = num;

    for (int factor = num - 1; factor > 0; factor--)
    {
        result *= factor;
    }

    return result;
}

int factorial_recursive(int num)
{
    if (num == 1 | num == 0)
    {
        return 1;
    }
    return num * factorial_recursive(num - 1);
}

void factorial_calculation(int num)
{
    int result;

    if (double_between_0_and_1() > 0.5)
    {
        result = factorial_recursive(num);
    }
    else
    {
        result = factorial_iterative(num);
    }

    printf("The factorial of %d is %d.\n", num, result);
}

// ---------- //
// DIGITS SUM //
// ---------- //

int digits_sum_recursive(int num)
{
    if (num <= 0)
        return num;

    int last_digit = num % 10;
    return last_digit + digits_sum_recursive(num / 10);
}

int digits_sum_iterative(int num)
{
    int result = 0;

    while (num > 0)
    {
        result += num % 10;
        num /= 10;
    }

    return result;
}

void digits_sum_calculation(int num)
{
    int result = 0;

    if (double_between_0_and_1() > 0.5)
    {
        result = digits_sum_recursive(num);
    }
    else
    {
        result = digits_sum_iterative(num);
    }

    printf("The sum of every digit of the number %d is %d.\n", num, result);
}