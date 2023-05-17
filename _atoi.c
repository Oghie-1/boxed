#include "shell.h"
#include <ctype.h>  // Added for the isspace and isdigit functions
#include <string.h> // Added for the strchr function

/**
 * interactive - checks if the shell is in interactive mode
 * @shell_info: pointer to a struct containing information about the shell
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise
 */

int interactive(info_t *shell_info)
{
int stdin_is_terminal = isatty(STDIN_FILENO);
int stdout_is_terminal = isatty(STDOUT_FILENO);
int stderr_is_terminal = isatty(STDERR_FILENO);

return (stdin_is_terminal && stdout_is_terminal &&
stderr_is_terminal && shell_info->readfd <= STDERR_FILENO);
}

/**
 * is_delim - checks if a character is a delimiter
 * @character: the character to check
 * @delimiter_string: the string containing delimiters
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int is_delim(char character, const char *delimiter_string)
{
    return (strchr(delimiter_string, character) != NULL);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the converted integer, or 0 if the string contains no numbers
 */
int _atoi(const char *s)
{
    int sign = 1;
    unsigned int result = 0;

    while (isspace((unsigned char)*s))  // Cast to unsigned char for isspace
        s++;

    if (*s == '-')
    {
        sign = -1;
        s++;
    }
    else if (*s == '+')
    {
        s++;
    }

    while (isdigit((unsigned char)*s))  // Cast to unsigned char for isdigit
    {
        result = result * 10 + (*s - '0');
        s++;
    }

    return (sign * result);
}
