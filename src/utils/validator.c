#include <string.h>

int is_empty_string(const char *text)
{
    if(text == NULL)
        return 1;

    return strlen(text) == 0;
}

int is_valid_length(int length, int min, int max)
{
    return length >= min && length <= max;
}
