#include "../include/parser.h"
#include "../include/utils.h"

#include <argp.h>
#include <stdlib.h>
#include <unistd.h>

#define INTERACTIVE_FLAG 'i'
#define ASSIST_FLAG 'a'
#define SPECIFYCONF_FLAG 'c'
#define DEFAULTCONF_FLAG '1'

static error_t parse_opt(int key, char* arg, struct argp_state* state)
{
    struct flag_data* f_data = state->input;

    // Realloc buffer
    void* tmp;

    switch (key)
    {
    // TODO: Remove debugging puts
    // TODO: Allocate space for enums
    case INTERACTIVE_FLAG:
        puts("Running Interactive Mode!");

    // If it's the first argument, allocate initial memory, otherwise allocate one more enum worth of space
        if ((state->arg_num - 1) == -1)
        {
            f_data->flags = alloc_mem(f_data->flags, sizeof(enum flags));
        }
        else
        {
            f_data->flags = alloc_mem(0, (state->arg_num + 1) * sizeof(enum flags));
        }

        f_data->flags[state->arg_num] = INTERACTIVE;
        break;

    case ASSIST_FLAG:
        puts("Running Assist Mode!");

    // If it's the first argument, allocate initial memory, otherwise allocate one more enum worth of space
        if ((state->arg_num - 1) == -1)
        {
            f_data->flags = alloc_mem(f_data->flags, sizeof(enum flags));
        }
        else
        {
            f_data->flags = alloc_mem(0, (state->arg_num + 1) * sizeof(enum flags));
        }

        f_data->flags[state->arg_num] = ASSIST;
        break;

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

    default:
        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

// Parse arguments
// FIXME: Add in documentation
static const struct argp_option argp_opts[] =
{
    {"interactive", INTERACTIVE_FLAG, 0, 0, "Run clFig in interactive mode."},
    {"assist", ASSIST_FLAG, 0, 0, "Run clFig in assist mode. See INSERT DOCS."},
    {"specify-config", SPECIFYCONF_FLAG, "config", 0, "Specify a path to the config file."},
    {"create-default-config", DEFAULTCONF_FLAG, 0, 0, "Creates a default configuration."},
    {0}
};

static const struct argp argp_parser = {
    argp_opts,
    parse_opt,
    0,
    // TODO: Finish this doc
    "Creates a config using data inputted by the user, either through interactive mode or assist mode.\v",
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
