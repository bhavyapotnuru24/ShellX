#include <stdio.h>
#include <stdlib.h>
#include "../../include/shellx.h"
#include "../../include/ui.h"

/* ================================
   File Manager
   ================================ */

void file_manager()
{
    int choice;
    char filename[100];
    char new_filename[100];

    printf("\n");

    printf(CYAN
           "╔══════════════════════════════════════════════════════════╗\n"
           "║                    FILE MANAGER                         ║\n"
           "╠══════════════════════════════════════════════════════════╣\n"
           RESET);

    printf(CYAN "║" RESET "  " YELLOW "1." RESET "  Create File                               " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "2." RESET "  Delete File                               " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "3." RESET "  List Files                                " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "4." RESET "  Rename File                               " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " RED "0." RESET "  Back                                      " CYAN "║\n" RESET);

    printf(CYAN
           "╚══════════════════════════════════════════════════════════╝\n"
           RESET);

    printf("\n");
    printf(GREEN "  ➜ Enter your choice: " RESET);
    scanf("%d", &choice);

    switch(choice)
    {
        /* ================================
           Create File
           ================================ */

        case 1:
        {
            printf("\n");
            printf(CYAN "  Enter file name: " RESET);
            scanf("%99s", filename);

            FILE *file = fopen(filename, "w");

            if(file == NULL)
            {
                print_error("Could not create the file.");
            }
            else
            {
                fclose(file);
                print_success("File created successfully!");
            }

            break;
        }

        /* ================================
           Delete File
           ================================ */

        case 2:
        {
            printf("\n");
            printf(CYAN "  Enter file name: " RESET);
            scanf("%99s", filename);

            if(remove(filename) == 0)
            {
                print_success("File deleted successfully!");
            }
            else
            {
                print_error("Could not delete the file.");
            }

            break;
        }

        /* ================================
           List Files
           ================================ */

        case 3:
        {
            print_header("FILES IN CURRENT DIRECTORY");

            system("ls");

            printf("\n");
            print_info("File listing completed.");

            break;
        }

        /* ================================
           Rename File
           ================================ */

        case 4:
        {
            printf("\n");
            printf(CYAN "  Enter current file name: " RESET);
            scanf("%99s", filename);

            printf(CYAN "  Enter new file name: " RESET);
            scanf("%99s", new_filename);

            if(rename(filename, new_filename) == 0)
            {
                print_success("File renamed successfully!");
            }
            else
            {
                print_error("Could not rename the file.");
            }

            break;
        }

        /* ================================
           Back
           ================================ */

        case 0:
            print_info("Returning to main menu...");
            break;

        default:
            print_error("Invalid choice!");
            break;
    }
}
