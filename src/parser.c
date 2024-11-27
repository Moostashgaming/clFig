#include <argp.h>

#define INTERACTIVE_FLAG 'i'
#define ASSIST_FLAG 'a'
#define SPECIFYCONFIG_FLAG 'c'

error_t parse_opt(int key, char* arg, struct argp_state* state)
{
    switch (key)
    {
    case INTERACTIVE_FLAG:
        // Run in interactive mode
            break;

    case ASSIST_FLAG:
        // Run in assist mode
            break;

    case SPECIFYCONFIG_FLAG:

        break;

    default:
        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

// Parse arguments
// FIXME: Add in documentation
const struct argp_option argp_opts[] =
{
    {"interactive", INTERACTIVE_FLAG, 0, 0, "Run clFig in interactive mode.", 0},
    {"assist", ASSIST_FLAG, 0, 0, "Run clFig in assist mode. See INSERT DOCS.", 0},
    {"specify-config", SPECIFYCONFIG_FLAG, "config", 0, "Specify a path to the config file."},
    {"create-default-config", 0, 0, 0, "Creates a default configuration.", 0}
};

const struct argp argp_parser = {
    argp_opts,
    parse_opt,
    NULL,
    "Creates a config using data inputted by the user, either through interactive mode or assist mode.\v",
    NULL,
    NULL,
    NULL
};

/**
 * Parse through the flags and return
 */
char* parse(int argc, char* argv[])
{
    argp_parse
    (
        &argp_parser,
        argc,
        argv,
        NULL,
        NULL,
        NULL

    );
}
