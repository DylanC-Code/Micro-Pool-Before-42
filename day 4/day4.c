#include <stdio.h>
#include <string.h>

const char *reverse(char *str)
{
    printf("String to reverse: %s\n", str);

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

    printf("Reversed string: %s\n", str);

    return str;
}

int main(int argc, char *argv[])
{
    char *str = argv[1];
    reverse(str);

    return 0;
}
