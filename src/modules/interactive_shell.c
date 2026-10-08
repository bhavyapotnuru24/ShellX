#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/interactive_shell.h"
#include "../../include/ui.h"

/* ================================
   Interactive Command Mode
   ================================ */

void interactive_shell(void)
{
    char command[500];

    clear_screen();

    print_header("INTERACTIVE COMMAND MODE");

    print_info("Type Linux commands directly. Type 'help' for help.");
    print_info("Type 'exit' to return to the ShellX main menu.");

    while (1)
    {
        printf("\n");
        printf(GREEN "ShellX > " RESET);

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            break;
        }

        /* Remove newline */
        command[strcspn(command, "\n")] = '\0';

        /* Ignore empty input */
        if (strlen(command) == 0)
        {
            continue;
        }

        /* Exit interactive mode */
        if (strcmp(command, "exit") == 0)
        {
            print_info("Returning to main menu...");
            break;
        }

        /* Help command */
        if (strcmp(command, "help") == 0)
        {
            printf("\n");

            printf(CYAN
                   "╔══════════════════════════════════════════════════════════╗\n"
                   "║                 SHELLX COMMAND HELP                    ║\n"
                   "╠══════════════════════════════════════════════════════════╣\n"
                   RESET);

            printf(CYAN "║" RESET "  help       - Show this help menu                    " CYAN "║\n" RESET);
            printf(CYAN "║" RESET "  clear      - Clear the terminal                    " CYAN "║\n" RESET);
            printf(CYAN "║" RESET "  exit       - Return to ShellX main menu            " CYAN "║\n" RESET);
            printf(CYAN "║" RESET "  Any Linux command can also be entered directly     " CYAN "║\n" RESET);

            printf(CYAN
                   "╚══════════════════════════════════════════════════════════╝\n"
                   RESET);

            continue;
        }

        /* Clear command */
        if (strcmp(command, "clear") == 0)
        {
            clear_screen();
            print_header("INTERACTIVE COMMAND MODE");
            continue;
        }

        /* Execute Linux command */
        system(command);
    }
}
