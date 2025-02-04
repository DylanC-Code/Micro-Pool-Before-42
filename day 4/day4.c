#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copy_string(char *source, char *destination)
{
    int left_index = 0;
    int write_index = strlen(source);

    while (left_index < write_index)
    {
        destination[left_index] = source[left_index];
        destination[write_index] = source[write_index];

        left_index++;
        write_index--;
    }

    return destination;
}

void copy_string_process(char *str_to_copy)
{
    size_t source_length = strlen(str_to_copy) + 1;
    char *destination = malloc(source_length);
    char *result = copy_string(str_to_copy, destination);

    printf("The string '%s' has been copied on '%s'.\n", str_to_copy, result);
}

char *reverse(char *str)
{

    int length = strlen(str);
    int left_index = 0, write_index = length - 1;

    while (left_index < write_index)
    {
        char save = str[write_index];

        str[write_index] = str[left_index];
        str[left_index] = save;

        left_index++;
        write_index--;
    }

    return str;
}

void reverse_process(char *str_to_reverse)
{
    printf("String to reverse: %s\n", str_to_reverse);

    char *new_str = malloc(strlen(str_to_reverse) + 1);
    new_str = copy_string(str_to_reverse, new_str);
    char *reversed_str = reverse(new_str);

    printf("Reversed string: %s\n", reversed_str);
}

int main(int argc, char *argv[])
{
    char *str = argv[1];

    copy_string_process(str);
    reverse_process(str);

    return 0;
}
