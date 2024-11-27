#include <argp.h>

#define INTERACTIVE_FLAG 'i'
#define ASSIST_FLAG 'a'

error_t parse_opt(int key, char* arg, struct argp_state* state)
{
    switch (key)
    {
        case INTERACTIVE_FLAG:

            break;

        case ASSIST_FLAG:

            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

/**
 * Parse through the flag
 */
char* parse()
{
    // Parse arguments
    // FIXME: Add in documentation
    const struct argp_option argpopts[] =
    {
        {"interactive", INTERACTIVE_FLAG, 0, 0, "Run clFig in interactive mode.", 0},
        {"assist", ASSIST_FLAG, 0, 0, "Run clFig in assist mode. See INSERT DOCS.", 0},
        {"create-default-config", 0, 0, 0, "Creates a default configuration.", 0}
    };

    argp_parse
    (
        (struct arp){&argpopts,},
    );
}
