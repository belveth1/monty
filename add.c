#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *tmp;
	int len = 0, i;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(store.file);
		free(store.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	i = tmp->n + tmp->next->n;
	tmp->next->n = i;
	*head = tmp->next;
	free(tmp);
}
