#include <stdio.h>
#include <stdlib.h>
#include "../../include/shellx.h"
#include "../../include/ui.h"

void command_runner()
{
    int choice;

    printf("\n");

    printf(CYAN
           "╔══════════════════════════════════════════════════════════╗\n"
           "║                   COMMAND RUNNER                        ║\n"
           "╠══════════════════════════════════════════════════════════╣\n"
           RESET);

    printf(CYAN "║" RESET "  " YELLOW "1." RESET "  List Files (ls)                          " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "2." RESET "  Current Directory (pwd)                  " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "3." RESET "  Current User (whoami)                    " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "4." RESET "  Current Date and Time (date)             " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " RED "0." RESET "  Back                                     " CYAN "║\n" RESET);

    printf(CYAN
           "╚══════════════════════════════════════════════════════════╝\n"
           RESET);

    printf("\n");
    printf(GREEN "  ➜ Enter your choice: " RESET);
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            print_header("LIST OF FILES");
            system("ls");
            print_info("File listing completed.");
            break;

        case 2:
            print_header("CURRENT DIRECTORY");
            system("pwd");
            print_info("Current directory displayed.");
            break;

        case 3:
            print_header("CURRENT USER");
            system("whoami");
            print_info("Current user displayed.");
            break;

        case 4:
            print_header("CURRENT DATE AND TIME");
            system("date");
            print_info("Date and time displayed.");
            break;

        case 0:
            print_info("Returning to main menu...");
            break;

        default:
            print_error("Invalid choice!");
            break;
    }
}
