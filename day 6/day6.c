#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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
        fprintf(stderr, "Error: Failed to compile regex for name validation.\n");
        return 0;
    };

    int result = regexec(&regex, name, 0, NULL, 0);

    regfree(&regex);
    return (result == 0);
}

void set_name(struct Person *person)
{
    char name[64];

    printf("Enter a name: ");
    fgets(name, 64, stdin);
    name[strcspn(name, "\n")] = '\0';

    if (check_name(name) == 1)
    {
        strncpy(person->name, name, sizeof(person->name) - 1);
        person->name[sizeof(person->name) - 1] = '\0';
    }
    else
    {
        printf("Invalid name, please retry only with letters and less than 63 characters.\n", name);
        set_name(person);
    }
}

void set_age(struct Person *person)
{
    fflush(stdout);
    char user_input[5];
    int age;

    printf("Enter an age: ");
    fgets(user_input, 5, stdin);
    sscanf(user_input, "%d", &age);

    if (age <= 0)
    {
        printf("\nThe age must be greater than 0.\n");
        return set_age(person);
    }
    else if (age > 110)
    {
        printf("\nThere is no chance.\n");
        return set_age(person);
    }

    person->age = age;
}

void set_size(struct Person *person)
{
    float user_input;

    printf("Enter a size: ");
    scanf("%f", &user_input);
    while ((getchar()) != '\n')
        ;

    if (user_input > 220)
    {
        printf("Lier!\n");
        return set_size(person);
    }
    else if (user_input < 1)
    {
        printf("Stop kidding.\n");
        return set_size(person);
    }

    person->size = truncf(user_input * 100) / 100;
}

#define GREEN "\033[1;32m"
#define RESET "\033[0m"
#define LINE "----------------------------------------"

void print_saved_person(struct Person *person)
{
    printf("\n%s\n", LINE);
    printf(GREEN "✅ Successfully saved !\n" RESET);
    printf("📌 Name     : %s\n", person->name);
    printf("🎂 Age     : %d \n", person->age);
    printf("📏 Size  : %.2f cm\n", person->size);
    printf("%s\n\n", LINE);
}

void save_person(struct Person *person)
{
    FILE *fptr;

    fptr = fopen("people.csv", "a");
    fprintf(fptr, "%s,%d,%.2f;", person->name, person->age, person->size);
    fclose(fptr);

    print_saved_person(person);
}

int main()
{

    while (1)
    {
        struct Person person;

        set_name(&person);
        set_age(&person);
        set_size(&person);
        save_person(&person);
    }

    return 0;
}
