#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (store.arg)
	{
		if (store.arg[0] == '-')
			j++;
		for (; store.arg[j] != '\0'; j++)
		{
			if (store.arg[j] > 57 || store.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(store.file);
			free(store.data);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(store.file);
		free(store.data);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(store.arg);
	if (store.lifi == 0)
		addnode(head, n);
}
