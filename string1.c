#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

if (dest == src || src == NULL)
return dest;

while (src[i])
{
dest[i] = src[i];
i++;
}

dest[i] = '\0';

return dest;
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
int i = 0;
int length = 0;
char *ret;

if (str == NULL)
return NULL;

while (str[length])
length++;

ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return NULL;

for (i < length; i++;)
ret[i] = str[i];

return ret;
}

/**
 * _puts - prints a string
 * @str: the string to be printed
 */
void _puts(char *str)
{
if (str == NULL)
return;

while (*str)
{
_putchar(*str);
str++;
}
}

/**
 * _putchar - writes the char c to stdout
 * @c: char to print
 *
 * Return: On success 1, on error -1
 */
int _putchar(char c)
{
static int i = 0;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE - 1)
{
write(1, buf, i);
i = 0;
}

if (c != BUF_FLUSH)
buf[i++] = c;

return 1;
}
