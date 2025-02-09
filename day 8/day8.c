#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUMBERS_OF_INTEGERS 100

int integer_between_0_and_1000();
void generate_number_of_random_int(int number_of_numbers, int numbers[]);
void insertion_sort(int integers_to_sort[], int capacity);

int main()
{
    srand(time(NULL));

    int integers[NUMBERS_OF_INTEGERS];

    generate_number_of_random_int(NUMBERS_OF_INTEGERS, integers);
    display_integers(integers, NUMBERS_OF_INTEGERS);
    insertion_sort(integers, NUMBERS_OF_INTEGERS);
    display_integers(integers, NUMBERS_OF_INTEGERS);
}

int integer_between_0_and_1000()
{
    return (double)rand() / RAND_MAX * 1000;
}

void generate_number_of_random_int(int number_of_integers, int integers[])
{
    for (int integer_index = 0; integer_index <= number_of_integers; integer_index++)
    {
        integers[integer_index] = integer_between_0_and_1000();
    }
}

void insertion_sort(int integers_to_sort[], int capacity)
{
    for (int i = 0; i < capacity; i++)

    {
        int integer_to_sort = integers_to_sort[i];

        for (int b = i; b >= 0; b--)
        {
            if (b == 0)
            {
                integers_to_sort[0] = integer_to_sort;
                break;
            }

            int integer_sorted = integers_to_sort[b - 1];

            if (integer_to_sort > integer_sorted)
            {
                integers_to_sort[b] = integer_to_sort;
                break;
            }

            integers_to_sort[b] = integer_sorted;
        }
    }
}



void display_integers(int integers[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("I %d: %d\n", i, integers[i]);
    }
}