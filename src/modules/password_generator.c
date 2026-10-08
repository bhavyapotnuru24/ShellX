#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/shellx.h"
#include "../../include/ui.h"

void password_generator()
{
    int length;
    int i;

    char characters[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789";

    int size = sizeof(characters) - 1;

    printf("\n");

    printf(CYAN
           "╔══════════════════════════════════════════════════════════╗\n"
           "║                  PASSWORD GENERATOR                     ║\n"
           "╠══════════════════════════════════════════════════════════╣\n"
           RESET);

    printf(CYAN "║" RESET "  Generate a random password using letters and numbers. " CYAN "║\n" RESET);

    printf(CYAN
           "╚══════════════════════════════════════════════════════════╝\n"
           RESET);

    printf("\n");
    printf(GREEN "  ➜ Enter password length: " RESET);
    scanf("%d", &length);

    if(length <= 0)
    {
        print_error("Invalid password length!");
        return;
    }

    srand(time(NULL));

    printf("\n");
    printf(MAGENTA "  Generated Password: " RESET);

    for(i = 0; i < length; i++)
    {
        printf("%c", characters[rand() % size]);
    }

    printf("\n");

    print_success("Password generated successfully.");
}
