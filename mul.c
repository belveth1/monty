#include "monty.h"
/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *tmp;
	int d, nodes = 0;

        tmp = *head;
        while (tmp)
        {
                nodes++;
                tmp = tmp->next;
        }
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short", counter);
		fclose(store.file);
                free(store.data);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
	tmp = *head;
	d = tmp->next->n * tmp->n;
	tmp->next->n = d;
	*head = tmp->next;
	free(tmp);
}
