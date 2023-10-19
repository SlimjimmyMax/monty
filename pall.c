#include "monty.h"
/**
 * ej_pall - Prints all elements of the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number being processed (unused).
 */
void ej_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void) counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
