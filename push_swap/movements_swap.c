/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:50:26 by srudman           #+#    #+#             */
/*   Updated: 2023/11/27 21:03:29 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// typedef struct	s_stack_node
// {
// 	int		value;
// 	int		position;
// 	struct s_stack_node *prev;
// 	struct s_stack_node *next;
// 	// more meta data missing
// }				t_stack_node;

Should I also check if the len of stack is higher than 1?
t_stack_node	**swap_movement(t_stack_node **head)
{
	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
		return(NULL);
	(*head)->position += 1;
	(*head)->next->position -= 1;

	
	(*head)->prev = (*head)->next;
	(*head)->next->prev = NULL;
	
	if ((*head)->next->next != NULL)
		(*head)->next->prev = (*head);
	
	(*head)->next->next = (*head);
	return (&(*head));
	// THIS CODE BELOW WORKS - try it!
	// *head = (*head)->next;
	// (*head)->prev->prev = *head;
	// (*head)->prev->next = (*head)->next;
	// if ((*head)->next)
	// 	(*head)->next->prev = (*head)->prev;
	// (*head)->next = (*head)->prev;
	// (*head)->prev = NULL;
	// return (head);
}

t_stack_node **swap_movement(t_stack_node **head)
{
    if (head == NULL || (*head) == NULL || (*head)->next == NULL)
        return NULL;

    (*head)->position += 1;
    (*head)->next->position -= 1;

	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
	return (head);
}


// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

int sa(t_stack_node **a)
{
	if (swap_movement(a))
	{
 		write(1, "sa\n", 3);
		return (1);
	}
	return (0);
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

int sb(t_stack_node **b)
{
	b = swap_movement(b);
	if (b)
	{
 		write(1, "sb\n", 3);
		return (1);
	}
	return (0);
}

// ss : sa and sb at the same time.

int ss(t_stack_node **a, t_stack_node **b)
{
	a = swap_movement(a);
	b = swap_movement(b);
	if (a && b)
	{
 		write(1, "ss\n", 3);
		return (1);
	}
	return (0);
}


void free_list(t_stack_node *head) {
    t_stack_node *current = head;
    t_stack_node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void print_list(t_stack_node *head)
{
    while (head != NULL)
    {
        printf("Value: %d, Position: %d\n", head->value, head->position);
        head = head->next;
    }
}

int main()
{
    // Create two nodes
    t_stack_node *node1 = malloc(sizeof(t_stack_node));
    t_stack_node *node2 = malloc(sizeof(t_stack_node));

    // Initialize node values and positions
    node1->value = 1;
    node1->position = 1;
    node1->prev = NULL;
    node1->next = node2;

    node2->value = 2;
    node2->position = 2;
    node2->prev = node1;
    node2->next = NULL;

    // Print the initial list
    printf("Before swap:\n");
    print_list(node1);

    // Perform swap operation
    t_stack_node **result = swap_movement(&node1);

    // Update the head of the list after swap
    if (result != NULL && *result != NULL) {
        node1 = *result;
    }

    // Print the list after swap
    printf("\nAfter swap:\n");
    print_list(node1);

    // Free allocated memory
    free(node1);
    free(node2);

    return 0;
}
