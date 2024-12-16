#include "../include/argparser.h"
#include "../include/utils.h"

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    parse(argc, argv, &data);

    puts("Welcome to clFig!");

    char* cwd = getcwd(NULL, 0);

    int fd;

    switch (data.exec_mode)
    {
    case INTERACTIVE:
        puts("Running in Interactive Mode!");

        // Allocate space for end of path and add it to the cwd
        const unsigned char len = strlen(cwd);
        cwd = alloc_mem(cwd, (len * sizeof(char))  + (6 * sizeof(char)));
        memcpy(cwd + len, "/.fig", 6);

        puts("Opening program conf...");
        if (((fd = open(cwd, O_RDWR)) == -1) && (errno == ENOENT))
        {
            l_retry_prompt:

            puts("File does not exist!");
            puts("Would you like to create it? [Y/n]:");

            char* res;
            size_t res_len;
            getline(&res, &res_len, stdin);

            switch (tolower(res[0]))
            {
                case 'y':
                case '\n':
                    fd = open(cwd, O_RDWR | O_CREAT);
                    printf("\nConf created at %s", cwd);

                    // TODO: Make program conf

                    break;

                case 'n':
                    puts("Exiting...");
                    free(res);
                    free(cwd);
                    die(0);
                    break;

                default:
                    puts("Input invalid! Try Again!");
                    goto l_retry_prompt;
            }

            free(res);
        } else
        {
            printf("\nConf found at %s", cwd);
            // TODO: Read program conf

            puts("Opening user conf...");
        }

        break;

    case ASSIST:
        puts("Running in Assist Mode!");
        break;

    default:
        puts("No mode specified! We're fucked!");
        puts("Exiting...");
        die(0);
    }

    return 0;
}
