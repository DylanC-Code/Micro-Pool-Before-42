#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUMBERS_OF_INTEGERS 10

int integer_between_0_and_1000();
void generate_number_of_random_int(int number_of_numbers, int numbers[]);
void insertion_sort(int integers_to_sort[], int capacity);
void quick_sort(int integers_to_sort[], int capacity);
void display_integers(int integers[], int length);

int main()
{
    srand(time(NULL));

    int integers[NUMBERS_OF_INTEGERS];

    generate_number_of_random_int(NUMBERS_OF_INTEGERS, integers);
    display_integers(integers, NUMBERS_OF_INTEGERS);
    // insertion_sort(integers, NUMBERS_OF_INTEGERS);
    printf("====================\n");
    printf("First pivot %d \n", integers[NUMBERS_OF_INTEGERS - 1]);
    printf("====================\n");

    quick_sort(integers, NUMBERS_OF_INTEGERS);
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

void quick_sort(int integers_to_sort[], int capacity)
{
    if (capacity <= 1)
        return;

    int last_integer_index = capacity - 1;
    int pivot = integers_to_sort[last_integer_index];
    int last_greater_integer_index = -1;

    for (int integer_index = last_integer_index - 1; integer_index >= 0; integer_index--)
    {
        int integer_value = integers_to_sort[integer_index];

        if (integer_value < pivot)
            continue;

        if (last_greater_integer_index < 0)
            last_greater_integer_index = last_integer_index;
        last_greater_integer_index--;

        int tmp = integers_to_sort[last_greater_integer_index];
        integers_to_sort[last_greater_integer_index] = integer_value;
        integers_to_sort[integer_index] = tmp;
    }

    int pivot_position = last_greater_integer_index == -1 ? last_integer_index : last_greater_integer_index;
    integers_to_sort[last_integer_index] = integers_to_sort[pivot_position];
    integers_to_sort[pivot_position] = pivot;

    quick_sort(integers_to_sort, pivot_position);
    quick_sort(integers_to_sort + 1 + pivot_position, capacity - pivot_position - 1);
}

void display_integers(int integers[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("I %d: %d\n", i, integers[i]);
    }
}