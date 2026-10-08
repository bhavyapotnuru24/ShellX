#ifndef UI_H
#define UI_H

/* ================================
   ShellX Color Definitions
   ================================ */

#define RESET       "\033[0m"

#define BOLD        "\033[1m"
#define CYAN        "\033[1;36m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define RED         "\033[1;31m"
#define BLUE        "\033[1;34m"
#define MAGENTA     "\033[1;35m"
#define WHITE       "\033[1;37m"
#define GRAY        "\033[0;37m"

/* ================================
   UI Functions
   ================================ */

void clear_screen(void);

void print_logo(void);

void print_header(const char *title);

void print_success(const char *message);

void print_error(const char *message);

void print_info(const char *message);

void print_warning(const char *message);

void print_separator(void);

void print_footer(void);

#endif
