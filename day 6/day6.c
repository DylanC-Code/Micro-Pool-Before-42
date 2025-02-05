#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <math.h>

struct Person
{
    char name[64];
    int age;
    float size;
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

void set_size(struct Person *person)
{
    float user_input;

    printf("Enter your size:");
    scanf("%f", &user_input);

    if (user_input > 150)
    {
        printf("If its true, go to the gym!\n");
        return set_size(person);
    }
    else if (user_input < 1)
    {
        printf("Stop kidding.\n");
        return set_size(person);
    }

    person->size = truncf(user_input * 100) / 100;
}

int main()
{
    struct Person person;

    // set_name(&person);
    // set_age(&person);
    set_size(&person);
    save_person(&person);

    return 0;
}
