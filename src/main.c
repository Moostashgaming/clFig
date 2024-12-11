#include "../include/flparser.h"
#include "../include/utils.h"

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    static struct flag_data data;

    parse(argc, argv, &data);

    puts("Welcome to clFig!");

    switch (data.exec_mode)
    {
        case INTERACTIVE:
            puts("Running in Interactive Mode!");
            break;

        case ASSIST:
            puts("Running in Assist Mode!");
            break;

        default:
            puts("No mode specified! We're fucked!");
            die(0);

            return 1;
    }

    return 0;
}
