#include <stdio.h>
#include <time.h>

void log_event(const char *message)
{
    FILE *file = fopen("data/history.txt", "a");

    if(file == NULL)
        return;

    time_t now = time(NULL);

    fprintf(file, "[%s] %s\n", ctime(&now), message);

    fclose(file);
}
