#include <stdio.h>
#include <stdlib.h>
#include "../../include/shellx.h"
#include "../../include/ui.h"

void system_info()
{
    int choice;

    printf("\n");

    printf(CYAN
           "╔══════════════════════════════════════════════════════════╗\n"
           "║                 SYSTEM INFORMATION                      ║\n"
           "╠══════════════════════════════════════════════════════════╣\n"
           RESET);

    printf(CYAN "║" RESET "  " YELLOW "1." RESET "  Current User                              " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "2." RESET "  Current Directory                         " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "3." RESET "  Date and Time                             " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "4." RESET "  Memory Information                        " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "5." RESET "  Disk Usage                                " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " RED "0." RESET "  Back                                      " CYAN "║\n" RESET);

    printf(CYAN
           "╚══════════════════════════════════════════════════════════╝\n"
           RESET);

    printf("\n");
    printf(GREEN "  ➜ Enter your choice: " RESET);
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            print_header("CURRENT USER");
            system("whoami");
            print_info("Current user displayed.");
            break;

        case 2:
            print_header("CURRENT DIRECTORY");
            system("pwd");
            print_info("Current directory displayed.");
            break;

        case 3:
            print_header("DATE AND TIME");
            system("date");
            print_info("Date and time displayed.");
            break;

        case 4:
            print_header("MEMORY INFORMATION");
            system("free -h");
            print_info("Memory information displayed.");
            break;

        case 5:
            print_header("DISK USAGE");
            system("df -h");
            print_info("Disk usage displayed.");
            break;

        case 0:
            print_info("Returning to main menu...");
            break;

        default:
            print_error("Invalid choice!");
            break;
    }
}
