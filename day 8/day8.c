#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUMBERS_OF_INTEGERS 100

int integer_between_0_and_1000();
void generate_number_of_random_int(int number_of_numbers, int *numbers[]);

int main()
{
    srand(time(NULL));

    int *integers[NUMBERS_OF_INTEGERS];

    generate_number_of_random_int(NUMBERS_OF_INTEGERS, integers);

    for (int i = 1; i <= NUMBERS_OF_INTEGERS; i++)
    {
        printf("I %d equal %d\n", i, integers[i]);
    }
}

int integer_between_0_and_1000()
{
    return (double)rand() / RAND_MAX * 1000;
}

void generate_number_of_random_int(int number_of_integers, int *integers[])
{
    for (int integer_index = 0; integer_index <= number_of_integers; integer_index++)
    {
        integers[integer_index] = integer_between_0_and_1000();
    }
}