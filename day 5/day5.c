#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int integer_between_0_and_100()
{
    return (double)rand() / RAND_MAX * 100;
}

int *generate_random_integers(int *size)
{
    int *arr = malloc(*size * sizeof(int));

    for (int i = 0; i < *size; i++)
    {
        arr[i] = integer_between_0_and_100();
    }

    return arr;
}

void random_integers_process()
{
    int number_of_integers = integer_between_0_and_100();
    int *integers = generate_random_integers(&number_of_integers);

    printf("A set of %d integers has been generated.\n", number_of_integers);

    for (int integer_index = 0; integer_index < number_of_integers; integer_index++)
    {
        printf("%d ", integers[integer_index]);
    }

    printf("\n");
}

int main()
{
    srand(time(NULL));
    random_integers_process();

    return 0;
}