#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: pointer to pointer to head node
 * @index: index of the node to delete
 * Return: 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    temp = *head;

    /* delete head */
    if (index == 0)
    {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return (1);
    }

    /* traverse to the node at index */
    for (i = 0; temp != NULL && i < index; i++)
        temp = temp->next;

    if (temp == NULL)
        return (-1);

    /* unlink node */
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return (1);
}
