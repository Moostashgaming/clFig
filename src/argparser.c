#include "../include/argparser.h"
#include "../include/utils.h"

#include <argp.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define INTERACTIVE_MODE_SWITCH 'i'
#define ASSIST_MODE_SWITCH 'a'
#define SPECIFYCONF_FLAG 'c'
#define DEFAULTCONF_FLAG '1'

struct flag_data data;

static error_t parse_opt(int key, char* arg, struct argp_state* state)
{
    struct flag_data* f_data = state->input;

    // Realloc buffer
    void* tmp;

    switch (key)
    {

    case SPECIFYCONF_FLAG:
        // If it's the first argument, allocate initial memory, otherwise allocate one more enum worth of space
        if ((state->arg_num - 1) == -1)
        {
            f_data->flags = alloc_mem(f_data->flags, sizeof(enum flags));
        }
        else
        {
            f_data->flags = alloc_mem(0, (state->arg_num + 1) * sizeof(enum flags));
        }

        f_data->flags[state->arg_num] = SPECIFYCONF;
        f_data->conf_path = arg;
        break;

    case DEFAULTCONF_FLAG:
        // If it's the first argument, allocate initial memory, otherwise allocate one more enum worth of space
        if ((state->arg_num - 1) == -1)
        {
            f_data->flags = alloc_mem(f_data->flags, sizeof(enum flags));
        }
        else
        {
            f_data->flags = alloc_mem(0, (state->arg_num + 1) * sizeof(enum flags));
        }

        f_data->flags[state->arg_num] = DEFAULTCONF;
        break;

    case ARGP_KEY_ARG:
        switch (tolower(arg[0]))
        {
            case INTERACTIVE_MODE_SWITCH:
                f_data->exec_mode = INTERACTIVE;
                break;

            case ASSIST_MODE_SWITCH:
                f_data->exec_mode = ASSIST;
                break;

            default:
                f_data->exec_mode = NONE;
                return ARGP_ERR_UNKNOWN;
        }
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
    {0, ARGP_HELP_PRE_DOC, 0, 0, "\n\rList of available commands:", 1},
    {0, ARGP_KEY_ARG, "i", 0, "  i - Run clFig in interactive mode.", 1},
    {0, ARGP_KEY_ARG, "a", 0, "  a - Run clFig in assist mode. See INSERT DOCS.",1},
    {0, ARGP_HELP_PRE_DOC, 0, 0, "\rMultiple Command entries will result in only the last command taking action.", 1},

    {0, ARGP_HELP_PRE_DOC, 0, 0, "\n\rList of available flags:\n", 2},
    {"specify-config", SPECIFYCONF_FLAG, "path", 0, "Specify a path to the config file. Default is whatever directory the user is in on runtime under the name .fig for program config, and .ufig for user config.", 2},
    {"create-default-config", DEFAULTCONF_FLAG, "path", OPTION_ARG_OPTIONAL, "Creates a default configuration at PATH if specified. Otherwise create a default config wherever the user is.", 2},
    { 0 }
};

static const struct argp argp_parser = {
    argp_opts,
    parse_opt,
    "<cmd> [OPTION...]",
    // TODO: Finish this doc
    "\nCreates a config using data inputted by the user, either through interactive mode or assist mode.\v",
    0,
    0,
    0
};

// TODO: Finish arg documentation

/**
 * Parse through the flags and return the index
 * @param f_data A struct holding all data that could be retrieved from flags, all values must be freed by the user
 */
error_t parse(int argc, char* argv[], struct flag_data* f_data)
{
    return argp_parse
    (
        &argp_parser,
        argc,
        argv,
        0,
        NULL,
        f_data
    );
}
