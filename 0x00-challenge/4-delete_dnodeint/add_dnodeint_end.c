#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Add a node at the end of a list
 *
 * @head: The address of the pointer to the first element of the list
 * @n: The number to store in the new element
 *
 * Return: A pointer to the new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new;
    dlistint_t *l;

    // Allocate memory for the new node
    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
    {
        return (NULL);
    }

    // Initialize the new node
    new->n = n;
    new->next = NULL;

    // If the list is empty, the new node becomes the head
    if (*head == NULL)
    {
        *head = new;
        new->prev = NULL;
        return (new);
    }

    // Traverse to the last node of the list
    l = *head;
    while (l->next != NULL)
    {
        l = l->next;
    }

    // Link the new node at the end
    l->next = new;
    new->prev = l;

    return (new);
}
