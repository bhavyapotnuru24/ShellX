#include <stdio.h>
#include <string.h>
#include "../../include/shellx.h"
#include "../../include/ui.h"

/* ================================
   Notes Manager
   ================================ */

void notes_manager()
{
    int choice;
    char note[500];

    printf("\n");

    printf(CYAN
           "╔══════════════════════════════════════════════════════════╗\n"
           "║                    NOTES MANAGER                        ║\n"
           "╠══════════════════════════════════════════════════════════╣\n"
           RESET);

    printf(CYAN "║" RESET "  " YELLOW "1." RESET "  Add Note                                  " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "2." RESET "  View Notes                                " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "3." RESET "  Delete Note                              " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " RED "0." RESET "  Back                                      " CYAN "║\n" RESET);

    printf(CYAN
           "╚══════════════════════════════════════════════════════════╝\n"
           RESET);

    printf("\n");
    printf(GREEN "  ➜ Enter your choice: " RESET);
    scanf("%d", &choice);

    getchar();

    switch(choice)
    {
        /* ================================
           Add Note
           ================================ */

        case 1:
        {
            FILE *file = fopen("notes.txt", "a");

            if(file == NULL)
            {
                print_error("Error opening notes file.");
                break;
            }

            printf("\n");
            printf(CYAN "  Enter your note: " RESET);

            fgets(note, sizeof(note), stdin);

            fprintf(file, "%s", note);

            fclose(file);

            print_success("Note saved successfully!");

            break;
        }

        /* ================================
           View Notes
           ================================ */

        case 2:
        {
            FILE *file = fopen("notes.txt", "r");

            if(file == NULL)
            {
                print_info("No notes found.");
                break;
            }

            print_header("YOUR NOTES");

            while(fgets(note, sizeof(note), file) != NULL)
            {
                printf("  " WHITE "• " RESET "%s", note);
            }

            fclose(file);

            printf("\n");
            print_info("Notes displayed successfully.");

            break;
        }

        /* ================================
           Delete Note
           ================================ */

        case 3:
        {
            FILE *file = fopen("notes.txt", "r");
            FILE *temp = fopen("temp_notes.txt", "w");

            int note_number;
            int current_number = 1;
            int found = 0;

            if(file == NULL)
            {
                print_info("No notes found.");
                break;
            }

            if(temp == NULL)
            {
                fclose(file);
                print_error("Could not create temporary file.");
                break;
            }

            printf("\n");
            print_header("DELETE NOTE");

            printf(CYAN "  Your Notes:\n\n" RESET);

            while(fgets(note, sizeof(note), file) != NULL)
            {
                printf(YELLOW "  %d." RESET " %s",
                       current_number,
                       note);

                current_number++;
            }

            if(current_number == 1)
            {
                fclose(file);
                fclose(temp);
                remove("temp_notes.txt");

                print_info("No notes available to delete.");
                break;
            }

            printf("\n");
            printf(GREEN "  ➜ Enter note number to delete: " RESET);
            scanf("%d", &note_number);

            rewind(file);

            current_number = 1;

            while(fgets(note, sizeof(note), file) != NULL)
            {
                if(current_number == note_number)
                {
                    found = 1;
                }
                else
                {
                    fprintf(temp, "%s", note);
                }

                current_number++;
            }

            fclose(file);
            fclose(temp);

            if(found)
            {
                remove("notes.txt");
                rename("temp_notes.txt", "notes.txt");

                print_success("Note deleted successfully!");
            }
            else
            {
                remove("temp_notes.txt");

                print_error("Invalid note number.");
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
