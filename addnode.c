#include "monty.h"
/**
 * addnode - Adds a new node to the beginning of the stack.
 * @head: Pointer to the head of the stack.
 * @n: Value to be assigned to the new node.
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
