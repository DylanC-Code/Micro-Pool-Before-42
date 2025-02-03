#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("The list of prime numbers from 1 to 100 are listed below:\n");

    for (int number = 2; number <= 100; number++)
    {
        bool is_prime = true;

        for (int between_number = 2; between_number < number; between_number++)
        {
            int remainder = number % between_number;

            if (remainder == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
            printf("%d  ", number);
    }

    printf("\n");

    return 0;
}