#include "monty.h"
/**
 * f_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_mod(stack_t **head, unsigned int counter)
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
                fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
                fclose(store.file);
                free(store.data);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        tmp = *head;
        if (tmp->n == 0)
        {
                fprintf(stderr, "L%d: division by zero\n", counter);
                fclose(store.file);
                free(store.data);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
	d = tmp->next->n % tmp->n;
        tmp->next->n = d;
        *head = tmp->next;
        free(tmp);
}
