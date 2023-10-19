#include "monty.h"

/**
 * custom_getline - Custom implementation of the getline function.
 * @lineptr: Pointer to the line buffer.
 * @n: Pointer to the buffer size.
 * @stream: Pointer to the input stream.
 * Return: Number of characters read.
 */
bus_t bus = {NULL, NULL, NULL, 0};

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bufsize = 1024;
	size_t pos = 0;
	int c;

	if (*lineptr == NULL)
{
		*lineptr = (char *)malloc(bufsize);
		if (*lineptr == NULL)
{
			return (-1);
		}
		*n = bufsize;
	}

	while (1)
{
		c = fgetc(stream);

		if (c == EOF || c == '\n')
{
			(*lineptr)[pos] = '\0';
			break;
		}
{
			(*lineptr)[pos] = c;
		}

		pos++;

		if (pos >= *n)
{
			bufsize += 1024;
			*lineptr = (char *)realloc(*lineptr, bufsize);
			if (*lineptr == NULL)
{
				return (-1);
			}
			*n = bufsize;
		}
	}

	if (pos == 0 && c == EOF)
{
		return (-1);
	}

	return (pos);
}
/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = custom_getline(&content, &size, file);
		bus.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
