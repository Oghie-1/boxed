#include "shell.h"

/**
 * _myhistory - displays the history list, one command per line,
 * preceded with line numbers, starting at 0
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias - removes an alias from the alias list
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @name: the name of the alias to be removed
 * Return: 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *name)
{
char *p;
int ret;
p = _strchr(name, '=');
if (!p)
return (1);
*p = '\0';
ret = delete_node_at_index(&(info->alias), get_node_index(info->alias, info->alias));
*p = '=';
return (ret);
return (0);
}

/**
 * set_alias - adds or modifies an alias in the alias list
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @name: the name of the alias to be added or modified
 * @value: the value of the alias
 * Return: 0 on success, 1 on error
 */
int set_alias(info_t *info, char *name)
{
char *p;

p = _strchr(name, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(info, name));
unset_alias(info, name);
return (add_node_end(&(info->alias), name, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node to be printed
 * Return: 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
char *p = NULL;

if (node)
{
p = _strchr(node->str, '=');
for (; node->str != p; node->str++)
_putchar(*(node->str));
_puts(p);
_putchar('\n');
return (0);
}
return (1);
}

/**
 * _myalias - displays, sets, or unsets aliases
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myalias(info_t *info)
{
int i;
char *p;
list_t *node;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}

for (i = 1; info->argv[i]; i++)
{
p = _strchr(info->argv[i], '=');
if (p)
{
*p = '\0';
set_alias(info, info->argv[i]);
}
else
{
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}
}
return (0);
}

