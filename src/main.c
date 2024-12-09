#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

int main(int argc, char* argv[])
{
    struct flag_data data;

    parse(argc, argv, &data);
    puts("Welcome to clFig!");
    return 0;
}
