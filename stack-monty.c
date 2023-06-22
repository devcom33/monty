#include "monty.h"
stack_t *top = NULL;
/**
 * push - push new element
 * @data: data argument
 */
void push(int data)
{
	stack_t *tmp = (stack_t *)malloc(sizeof(stack_t));

	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tmp->n = data;
	tmp->prev = NULL;
	tmp->next = top;
	if (tmp->next != NULL)
		top->prev = tmp;
	top = tmp;
}
/**
 * pop - delete element
 */
void pop(void)
{
	stack_t *p = top;

	if (!top)
		exit(EXIT_FAILURE);
	if (top->next)
	{
		top = top->next;
		top->prev = NULL;
	}
	else
	{
		top = NULL;
	}
	free(p);
}
/**
 * display - function that display elements
 */
void display(void)
{
	stack_t *current = top;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
