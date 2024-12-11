#ifndef PARSER_H
#define PARSER_H
#include <argp.h>

enum flags { SPECIFYCONF, DEFAULTCONF };

enum mode { NONE, INTERACTIVE, ASSIST };

/**
 * A collection of all the data from flags specified by the user
 */
struct flag_data
{
    /**
     * Flags we got from parsing, may be null (Make sure to check)
     */
    enum flags * flags;

    /**
     * The specified config path
     */
    char * conf_path;

    /**
     * Execution mode
     */
    enum mode exec_mode;
};

error_t parse(int argc, char* argv[], struct flag_data * f_data);

#endif //PARSER_H
