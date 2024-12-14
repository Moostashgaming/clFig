#include "../include/argparser.h"
#include "../include/utils.h"

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    parse(argc, argv, &data);

    puts("Welcome to clFig!");

    char* tmp = ".fig";
    char* cwd = getcwd(NULL, 0);

    unsigned int res;
    int fd;

    switch (data.exec_mode)
    {
    case INTERACTIVE:
        puts("Running in Interactive Mode!");

        // Allocate space for end of path and add it to the cwd
        alloc_mem(cwd, (strlen(tmp) + 1) * sizeof(char));
        mempcpy(cwd, tmp, strlen(tmp));

        puts("Opening program conf...");
        if ((fd = open(cwd, O_RDWR)) == -1 && errno == EACCES)
        {
            l_retry_prompt:

            puts("File does not exist!");
            puts("Would you like to create it? [Y/n]:\n");

            res = fgetc(stdin);

            switch (res)
            {
                case 'y':
                case 'Y':
                case '\n':
                    fd = open(cwd, O_RDWR | O_CREAT);

                    // TODO: Add functionality

                    break;

                case 'n':
                case 'N':
                    puts("Exiting...");
                    die(0);
                    break;

                default:
                    puts("Input invalid! Try Again!");
                    goto l_retry_prompt;
            }


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
