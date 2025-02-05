#include <stdio.h>
#include <regex.h>
#include <string.h>

struct Person
{
    char name[64];
    int age;
    double taille;
};

int check_name(char *name)
{
    regex_t regex;
    const char *pattern = "^[A-Za-z ]{1,64}$";

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0)
    {
        perror("Checking name regex compilation error.");
    };

    int result = regexec(&regex, name, 0, NULL, 0);

    regfree(&regex);
    return (result == 0);
}

void set_name(struct Person *person)
{
    char name[64];

    printf("Enter your name: ");
    fgets(name, 64, stdin);
    name[strcspn(name, "\n")] = '\0';

    if (check_name(name) == 1)
    {
        strncpy(person->name, name, sizeof(person->name) - 1);
        person->name[sizeof(person->name) - 1] = '\0';
    }
    else
    {
        printf("Invalid name, please retry only with letters and without more 63 characters.\n", name);
        set_name(person);
    }
}

void set_age(struct Person *person)
{
    int user_input;

    printf("Enter your age: ");
    scanf("%d", &user_input);

    if (user_input <= 0)
    {
        printf("The age must be greater than 0.\n");
        return set_age(person);
    }
    else if (user_input > 110)
    {
        printf("There is no chance.\n");
        return set_age(person);
    }

    person->age = user_input;
}

int main()
{
    struct Person person;

    set_name(&person);
    set_age(&person);

    return 0;
}
