#include <argp.h>

#define INTERACTIVE_FLAG 'i'
#define ASSIST_FLAG 'a'
#define SPECIFYCONF_FLAG 'c'

/**
 * Flags we got from parsing, may be null (Make sure to check)
 */
enum flags{INTERACTIVE, ASSIST, SPECIFYCONF, DEFAULTCONF} flag[];

/**
 * Config path we got from parsing, may be null (Make sure to check)
 */
char* conf_path;

static error_t parse_opt(int key, char* arg, struct argp_state* state)
{
    switch (key)
    {

    // TODO: Remove debugging puts
    case INTERACTIVE_FLAG:
        puts("Running Interactive Mode!");
        flag[state->arg_num] = INTERACTIVE;
            break;

    case ASSIST_FLAG:
        puts("Running Assist Mode!");
        flag[state->arg_num] = ASSIST;
            break;

    case SPECIFYCONF_FLAG:
        flag[state->arg_num] = SPECIFYCONF;
        conf_path = arg;
            break;

    case 0:
        flag[state->arg_num] = DEFAULTCONF;
            break;

    default:
        return ARGP_ERR_UNKNOWN;
    }



    return 0;
}

// Parse arguments
// FIXME: Add in documentation
static const struct argp_option argp_opts[] =
{
    {"interactive", INTERACTIVE_FLAG, 0, 0, "Run clFig in interactive mode.", 0},
    {"assist", ASSIST_FLAG, 0, 0, "Run clFig in assist mode. See INSERT DOCS.", 0},
    {"specify-config", SPECIFYCONF_FLAG, "config", 0, "Specify a path to the config file."},
    {"create-default-config", 0, 0, 0, "Creates a default configuration.", 0},
    { 0 }
};

static const struct argp argp_parser = {
    argp_opts,
    parse_opt,
    0,
    "Creates a config using data inputted by the user, either through interactive mode or assist mode.\v",
    0,
    0,
    0
};

/**
 * Parse through the flags and return the index
 */
error_t parse(int argc, char* argv[])
{
    return argp_parse
    (
        &argp_parser,
        argc,
        argv,
        0,
        NULL,
        NULL
    );
}
