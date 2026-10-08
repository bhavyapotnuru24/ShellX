#include <stdio.h>
#include "../include/shellx.h"
#include "../include/ui.h"
#include "../include/interactive_shell.h"
/* ================================
   Display ShellX Main Menu
   ================================ */

void display_menu()
{
    printf("\n");

    printf(CYAN
           "╔══════════════════════════════════════════════════════════╗\n"
           "║                    " BOLD "SHELLX MAIN MENU" RESET CYAN "                     ║\n"
           "╠══════════════════════════════════════════════════════════╣\n"
           RESET);

    printf(CYAN "║" RESET "  " YELLOW "1." RESET "  File Manager                                       " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "2." RESET "  Command Runner                                     " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "3." RESET "  Notes Manager                                      " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "4." RESET "  Calculator                                         " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "5." RESET "  System Information                                 " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "6." RESET "  Password Generator                                " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "7." RESET "  Interactive Command Mode                         " CYAN "║\n" RESET);
    printf(CYAN
           "╠══════════════════════════════════════════════════════════╣\n"
           RESET);

    printf(CYAN "║" RESET "  " RED "0." RESET "  Exit ShellX                                        " CYAN "║\n" RESET);

    printf(CYAN
           "╚══════════════════════════════════════════════════════════╝\n"
           RESET);

    printf("\n");
    printf(GREEN "  ➜ Enter your choice: " RESET);
}

/* ================================
   Main Program
   ================================ */

int main()
{
    int choice;

    /* Startup screen */
    clear_screen();
    print_logo();

    printf(GREEN
           "              Welcome to ShellX!\n"
           RESET);

    printf("\n");
    print_separator();

    do
    {
        display_menu();

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');

            print_error("Invalid input. Please enter a number.");
            continue;
        }

        switch(choice)
        {
            case 1:
                clear_screen();
                file_manager();
                break;

            case 2:
                clear_screen();
                command_runner();
                break;

            case 3:
                clear_screen();
                notes_manager();
                break;

            case 4:
                clear_screen();
                calculator();
                break;

            case 5:
                clear_screen();
                system_info();
                break;

            case 6:
                clear_screen();
                password_generator();
                break;
	    case 7:
    		while (getchar() != '\n');
	        interactive_shell();
    		break;

            case 0:
                clear_screen();

                printf("\n");

                printf(CYAN
                       "╔══════════════════════════════════════════════════════════╗\n"
                       "║                                                          ║\n"
                       RESET);

                printf(GREEN
                       "║              Thank you for using ShellX!                ║\n"
                       RESET);

                printf(CYAN
                       "║                                                          ║\n"
                       "║              Exiting ShellX... Goodbye!                 ║\n"
                       "║                                                          ║\n"
                       "╚══════════════════════════════════════════════════════════╝\n"
                       RESET);

                printf("\n");
                break;

            default:
                print_error("Invalid choice! Please select a valid option.");
                break;
        }

    } while(choice != 0);

    return 0;
}
