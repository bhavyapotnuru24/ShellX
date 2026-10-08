#include <stdio.h>
#include "../../include/shellx.h"
#include "../../include/ui.h"

void calculator()
{
    double num1, num2;
    int choice;

    printf("\n");

    printf(CYAN
           "╔══════════════════════════════════════════════════════════╗\n"
           "║                      CALCULATOR                         ║\n"
           "╠══════════════════════════════════════════════════════════╣\n"
           RESET);

    printf(CYAN "║" RESET "  " YELLOW "1." RESET "  Addition                                  " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "2." RESET "  Subtraction                               " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "3." RESET "  Multiplication                            " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " YELLOW "4." RESET "  Division                                  " CYAN "║\n" RESET);
    printf(CYAN "║" RESET "  " RED "0." RESET "  Back                                      " CYAN "║\n" RESET);

    printf(CYAN
           "╚══════════════════════════════════════════════════════════╝\n"
           RESET);

    printf("\n");
    printf(GREEN "  ➜ Enter your choice: " RESET);
    scanf("%d", &choice);

    if(choice == 0)
    {
        print_info("Returning to main menu...");
        return;
    }

    if(choice < 1 || choice > 4)
    {
        print_error("Invalid choice!");
        return;
    }

    printf("\n");
    printf(CYAN "  Enter first number: " RESET);
    scanf("%lf", &num1);

    printf(CYAN "  Enter second number: " RESET);
    scanf("%lf", &num2);

    switch(choice)
    {
        case 1:
            printf("\n");
            printf(BLUE "  Calculation: " RESET
                   "%.2lf + %.2lf = %.2lf\n",
                   num1, num2, num1 + num2);

            print_success("Addition completed.");
            break;

        case 2:
            printf("\n");
            printf(BLUE "  Calculation: " RESET
                   "%.2lf - %.2lf = %.2lf\n",
                   num1, num2, num1 - num2);

            print_success("Subtraction completed.");
            break;

        case 3:
            printf("\n");
            printf(BLUE "  Calculation: " RESET
                   "%.2lf × %.2lf = %.2lf\n",
                   num1, num2, num1 * num2);

            print_success("Multiplication completed.");
            break;

        case 4:

            if(num2 == 0)
            {
                print_error("Division by zero is not allowed.");
            }
            else
            {
                printf("\n");
                printf(BLUE "  Calculation: " RESET
                       "%.2lf ÷ %.2lf = %.2lf\n",
                       num1, num2, num1 / num2);

                print_success("Division completed.");
            }

            break;
    }
}
