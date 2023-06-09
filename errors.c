#include "shell.h"

/**
 * _eputs - prints an input string to stderr
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
    if (!str)
        return;

    while (*str)
    {
        _eputchar(*str++);
    }
}

/**
 * _eputchar - writes the character c to stderr
 * @c: the character to print
 *
 * Return: On success 1, on error -1 is returned and errno is set appropriately
 */
int _eputchar(char c)
{
    return write(STDERR_FILENO, &c, 1);
}

/**
 * _putfd - writes the character c to the given file descriptor
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1, on error -1 is returned and errno is set appropriately
 */
int _putfd(char c, int fd)
{
    return write(fd, &c, 1);
}

/**
 * _putsfd - prints an input string to the given file descriptor
 * @str: the string to be printed
 * @fd: The file descriptor to write to
 *
 * Return: the number of characters written
 */
int _putsfd(char *str, int fd)
{
    int count = 0;

    if (!str)
        return 0;

    while (*str)
    {
        count += _putfd(*str++, fd);
    }

    return count;
}
