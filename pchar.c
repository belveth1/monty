#include "monty.h"
/**
 * f_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *tmp;

	tmp = *head;
	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		 fclose(store.file);
                free(store.data);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
	if (tmp->n > 127 || tmp->n <  0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		 fclose(store.file);
                free(store.data);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
	printf("%c\n",tmp->n);
	*head = tmp->next;
	free(tmp);
}
