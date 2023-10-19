#include "monty.h"
/**
 * ej_stack - Sets the format of adding elements to stack (bus.lifi = 0).
 * @head: Pointer to the head of the stack (unused).
 * @counter: Line number being processed (unused).
 */
void ej_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
