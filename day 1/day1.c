#include <stdio.h>

int main()
{
    int user_age;

    printf("How old are you?\n");
    scanf("%d", &user_age);

    clear_console();

    if (user_age > 18)
    {
        printf("%d is greater than 18, so you're authorized!\n", user_age);
    }
    else if (user_age < 0)
    {
        printf("Age lower than 0 isn't authorized!\n");
    }
    else
    {
        printf("Age %d is lower than the majority, rejected!\n", user_age);
    }

    return 0;
}

void clear_console()
{
    for (int i = 0; i != 50; i++)
    {
        printf("\n");
    }
}