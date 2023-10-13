#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

struct User
{
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];
int userCount = 0;

void registerUser()
{
    if (userCount >= MAX_USERS)
    {
        printf("Maximum number of users reached.\n");
        return;
    }

    struct User newUser;
    printf("Enter name: ");
    fgets(newUser.name, MAX_NAME_LENGTH, stdin);
    printf("Enter email: ");
    fgets(newUser.email, MAX_EMAIL_LENGTH, stdin);
    printf("Enter password: ");
    fgets(newUser.password, MAX_PASSWORD_LENGTH, stdin);

    // Remove trailing newline characters from fgets
    newUser.name[strcspn(newUser.name, "\n")] = '\0';
    newUser.email[strcspn(newUser.email, "\n")] = '\0';
    newUser.password[strcspn(newUser.password, "\n")] = '\0';

    users[userCount++] = newUser;

    printf("Registration successful!\n");
}

void loginUser()
{
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter email: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    email[strcspn(email, "\n")] = '\0';
    password[strcspn(password, "\n")] = '\0';

    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].email, email) == 0 && strcmp(users[i].password, password) == 0)
        {
            printf("Login successful!\n");
            return;
        }
    }

    printf("Invalid email or password. Please try again.\n");
}

int main()
{
    int option;

    do
    {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        getchar(); // Consume the newline character left by scanf

        switch (option)
        {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }

        printf("\n");
    } while (option != 3);

    return 0;
}