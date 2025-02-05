#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

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
    free(integers);
}

typedef struct
{
    char letter;
    int times;
} Occurrence;

Occurrence *count_occurrence(char *text, Occurrence occurrences[])
{
    int length = strlen(text);

    for (int char_index = 0; char_index < length; char_index++)
    {
        for (int occurrence_index = 0; occurrence_index < 26; occurrence_index++)
        {
            Occurrence *occurrence = &occurrences[occurrence_index];

            if (occurrence->letter == text[char_index])
            {
                occurrence->times++;
                break;
            }
            else if (occurrence->times == 0)
            {
                occurrence->letter = text[char_index];
                occurrence->times = 1;

                break;
            }
        }
    }
}

void count_occurrences_process(char *text)
{
    Occurrence occurrences[26] = {0};
    count_occurrence(text, occurrences);

    for (int occurrence_index = 0; occurrence_index < 26; occurrence_index++)
    {
        Occurrence *occurrence = &occurrences[occurrence_index];

        if (occurrence->times > 0)
        {
            printf("Letter '%c' occurs %d times.\n", occurrence->letter, occurrence->times);
        }
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    random_integers_process();
    count_occurrences_process(argv[1]);

    return 0;
}