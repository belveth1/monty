#include "monty.h"

store_t store = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int ac, char **av)
{
	FILE *file;
	char *data;
	stack_t *stack = NULL;
	unsigned int counter = 0;
	ssize_t read_line = 1;
	size_t n = 0;



	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	store.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		data = NULL;
		read_line = getline(&data, &n, file);
		store.data = data;
		counter++;
		if (read_line > 0)
			execute(data, &stack, counter, file);
		free(data);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
