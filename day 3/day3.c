#include <stdio.h>
#include <stdlib.h>
#include "formulas.h"

int extract_number_from_str(char *arg)
{
    char *endptr;
    long num = strtol(arg, &endptr, 10);

    if (*endptr == '\0')
    {
        return num;
    }

    printf("Param '%s' provided isn't a valid integer!\n\n", arg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int requested_number = extract_number_from_str(argv[1]);

    factorial_calculation(requested_number);
    digits_sum_calculation(requested_number);

    return 0;
}
