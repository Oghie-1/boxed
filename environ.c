#include "shell.h"

/**
 * print_env_list - prints the current environment
 * @info: structure containing potential arguments
 *
 * Return: Always void
 */
void print_env_list(const info_t *info)
{
    print_list_str(info->env);
}

/**
 * get_env_var - gets the value of an environment variable
 * @info: structure containing potential arguments
 * @name: environment variable name
 *
 * Return: the value of the environment variable
 */
char *get_env_var(const info_t *info, const char *name)
{
    list_t *node = info->env;
    char *p;

    while (node)
    {
        p = starts_with(node->str, name);
        if (p && *p)
            return (p);
        node = node->next;
    }

    return (NULL);
}

/**
 * set_env_var - initializes a new environment variable,
 *	or modifies an existing one
 * @info: structure containing potential arguments
 *
 * Return: Always void
 */
void set_env_var(info_t *info)
{
    if (info->argc != 3)
    {
        _eputs("Incorrect number of arguments\n");
        return;
    }

    if (_setenv(info, info->argv[1], info->argv[2]) != 0)
    {
        _eputs("Error setting environment variable\n");
        return;
    }
}

/**
 * unset_env_var - removes an environment variable
 * @info: structure containing potential arguments
 *
 * Return: Always void
 */
void unset_env_var(info_t *info)
{
    int i;

    if (info->argc == 1)
    {
        _eputs("Too few arguments.\n");
        return;
    }

    for (i = 1; i < info->argc; i++)
        _unsetenv(info, info->argv[i]);
}

/**
 * populate_env_list - populates env linked list
 * @info: structure containing potential arguments
 *
 * Return: 0 on success, 1 on failure
 */
int populate_env_list(info_t *info)
{
    list_t *node = NULL;
    size_t i;

    for (i = 0; environ[i]; i++)
    {
        if (add_node_end(&node, environ[i], 0) == NULL)
        {
            free_list(node);
            return (1);
        }
    }

    info->env = node;
    return (0);
}

