#include "monty.h"
/**
 * ej_pstr - Prints the string starting from the top of the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number being processed (unused).
 */
void ej_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
