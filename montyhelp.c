#include "monty.h"

/**
 * getnumtokens - gets number of tokens passed
 * @buf: string
 * Return: number of tokens
 */

int getnumtokens(char *buf)
{
	int ntokens = 0;
	char *token, *dlim = " \t\r\n";

	for (token = strtok(buf, dlim); token != NULL; token = strtok(NULL, dlim))
	{
		ntokens++;
	}

	return (ntokens + 1);
}

/**
 * stringsplit - splits a string into substrings
 * @buf: string
 * Return: pointer to address of substrings
 */

char **stringsplit(char *buf)
{
	char **avcode, *bufcpy, *token, *dlim = " \n";
	int i = 0, ntokens;

	bufcpy = strdup(buf);
	ntokens = getnumtokens(buf);

	avcode = malloc(sizeof(char *) * (ntokens + 1));

	if (avcode == NULL)
	{
		free(bufcpy);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(bufcpy, dlim);

	if (token == NULL || *token == '#')
	{
		free(bufcpy);
		free(avcode); // Free the avcode array before returning
		return (NULL);
	}

	while (token != NULL)
	{
		avcode[i] = strdup(token);
		if (avcode[i] == NULL)
	{
	perror("strdup");
	free_av(avcode); // Free any allocated tokens before returning
	free(bufcpy);
	exit(EXIT_FAILURE);
	}
	i++;
	token = strtok(NULL, dlim);
	}

	avcode[i] = NULL;

	free(bufcpy);
	return avcode;
}

/**
 * free_av - frees memory used by array of strings
 * @av: array of strings
 */

void free_av(char **av)
{
	int i;

	if (av != NULL)
 	{
		for (i = 0; av[i] != NULL; i++)
	{
		free(av[i]);
	}
		free(av);
	}
}

/**
 * free_stack - frees a linked list stack_t
 * @stack: pointer to head of linked list
 */

void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

/**
 * checkstack - checks if the stack is empty
 * @stack: pointer to head of linked list
 * @count: line number of execution
 */

void checkstack(stack_t **stack, int count)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		exit(EXIT_FAILURE);
	}
}
