#include <stdio.h>

#include "../../include/ui.h"

/* ================================
   Clear Terminal Screen
   ================================ */

void clear_screen(void)
{
    printf("\033[2J\033[H");
}

/* ================================
   ShellX Logo
   ================================ */

void print_logo(void)
{
    printf("\n");

    printf(CYAN
           "╔══════════════════════════════════════════════════════════╗\n"
           "║                                                          ║\n"
           "║   ███████╗██╗  ██╗███████╗██╗     ██╗     ██╗  ██╗     ║\n"
           "║   ██╔════╝██║  ██║██╔════╝██║     ██║     ╚██╗██╔╝     ║\n"
           "║   ███████╗███████║█████╗  ██║     ██║      ╚███╔╝      ║\n"
           "║   ╚════██║██╔══██║██╔══╝  ██║     ██║      ██╔██╗      ║\n"
           "║   ███████║██║  ██║███████╗███████╗███████╗██╔╝ ██╗     ║\n"
           "║   ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝     ║\n"
           "║                                                          ║\n"
           RESET);

    printf(GREEN
           "║                  STUDENT LINUX TOOLKIT                  ║\n"
           RESET);

    printf(CYAN
           "║                     Version 1.0                         ║\n"
           "║                                                          ║\n"
           "╚══════════════════════════════════════════════════════════╝\n"
           RESET);

    printf("\n");
}

/* ================================
   Section Header
   ================================ */

void print_header(const char *title)
{
    printf("\n");

    printf(CYAN
           "╔══════════════════════════════════════════════════════════╗\n"
           RESET);

    printf(CYAN "║" RESET
           " %-54s "
           CYAN "║\n" RESET,
           title);

    printf(CYAN
           "╚══════════════════════════════════════════════════════════╝\n"
           RESET);

    printf("\n");
}

/* ================================
   Success Message
   ================================ */

void print_success(const char *message)
{
    printf("\n");

    printf(GREEN
           "╭─ SUCCESS ───────────────────────────────────────────────╮\n"
           RESET);

    printf(GREEN "│" RESET " ✓ %-53s" GREEN "│\n" RESET,
           message);

    printf(GREEN
           "╰─────────────────────────────────────────────────────────╯\n"
           RESET);
}

/* ================================
   Error Message
   ================================ */

void print_error(const char *message)
{
    printf("\n");

    printf(RED
           "╭─ ERROR ─────────────────────────────────────────────────╮\n"
           RESET);

    printf(RED "│" RESET " ✗ %-53s" RED "│\n" RESET,
           message);

    printf(RED
           "╰─────────────────────────────────────────────────────────╯\n"
           RESET);
}

/* ================================
   Information Message
   ================================ */

void print_info(const char *message)
{
    printf("\n");

    printf(BLUE
           "╭─ INFO ──────────────────────────────────────────────────╮\n"
           RESET);

    printf(BLUE "│" RESET "   %-53s" BLUE "│\n" RESET,
           message);

    printf(BLUE
           "╰─────────────────────────────────────────────────────────╯\n"
           RESET);
}

/* ================================
   Warning Message
   ================================ */

void print_warning(const char *message)
{
    printf("\n");

    printf(YELLOW
           "╭─ WARNING ───────────────────────────────────────────────╮\n"
           RESET);

    printf(YELLOW "│" RESET " ! %-53s" YELLOW "│\n" RESET,
           message);

    printf(YELLOW
           "╰─────────────────────────────────────────────────────────╯\n"
           RESET);
}

/* ================================
   Separator
   ================================ */

void print_separator(void)
{
    printf(CYAN
           "────────────────────────────────────────────────────────────\n"
           RESET);
}

/* ================================
   Footer
   ================================ */

void print_footer(void)
{
    printf("\n");

    printf(GRAY
           "────────────────────────────────────────────────────────────\n"
           RESET);

    printf(GRAY
           " ShellX v1.0  •  Student Linux Toolkit  •  C / Linux\n"
           RESET);

    printf(GRAY
           "────────────────────────────────────────────────────────────\n"
           RESET);
}
