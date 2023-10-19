#include "monty.h"
/**
  *f_sub- sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *tmp;
	int d;
	int nodes = 0;

	tmp = *head;
	while(tmp)
	{
		nodes++;
		tmp = tmp->next;
	}
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		free(tmp);
		fclose(store.file);
		free(store.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	d = tmp->next->n - tmp->n;
	tmp->next->n = d;
	*head = tmp->next;
	free(tmp);
}
