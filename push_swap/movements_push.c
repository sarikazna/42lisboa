/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:50:59 by srudman           #+#    #+#             */
/*   Updated: 2024/01/22 20:51:23 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_movement(t_stack_node **a_head, t_stack_node **b_head)
{
    t_stack_node	*pushed_b;
    if (!*b_head)
        return (0);
    pushed_b = *b_head;
    *b_head = (*b_head)->next;
    if (*b_head)
        (*b_head)->prev = NULL;
    if (!*a_head)
    {
        *a_head = pushed_b;
        (*a_head)->next = NULL;
    }
    else
    {
        (*a_head)->prev = pushed_b;
        pushed_b->next = (*a_head);
        *a_head = pushed_b;
    }
    ft_position_nbr(*b_head, 1);
    ft_position_nbr(*a_head, 1);
    return (1);
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

int pa(t_stack_node **a, t_stack_node **b)
{
    if (b == NULL || (*b) == NULL)
        return (0);
    if (push_movement(a, b))
	{
 		write(1, "pa\n", 3);
		return (1);
	}
	return (0);
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty

int pb(t_stack_node **a, t_stack_node **b)
{
    if (a == NULL || (*a) == NULL)
        return (0);
    if (push_movement(b, a))
	{
 		write(1, "pb\n", 3);
		return (1);
	}
	return (0);
}

/*
// Question does freeing stack automatically delete its values?
void free_list(t_stack_node *head) {
    t_stack_node *current = head;
    t_stack_node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void print_stack(t_stack_node *head)
{
    t_stack_node *current = head;

    while (current != NULL)
    {
        printf("Value: %d, Pos.: %d\n", current->value, current->position);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // I add 4 nodes
    t_stack_node *stack_a = malloc(sizeof(t_stack_node));
    stack_a->value = 3;
    stack_a->position = 1;
    stack_a->prev = NULL;

    t_stack_node *node2a = malloc(sizeof(t_stack_node));
    node2a->value = 6;
    node2a->position = 2;
    node2a->prev = stack_a;
    node2a->next = NULL;
    stack_a->next = node2a;

    t_stack_node *node3a = malloc(sizeof(t_stack_node));
    node3a->value = 9;
    node3a->position = 3;
    node3a->prev = node2a;
    node3a->next = NULL;
    node2a->next = node3a;

    // t_stack_node *stack_b = NULL;
    t_stack_node *stack_b = malloc(sizeof(t_stack_node));
    stack_b->value = 2;
    stack_b->position = 1;
    stack_b->prev = NULL;

    t_stack_node *node2b = malloc(sizeof(t_stack_node));
    node2b->value = 4;
    node2b->position = 2;
    node2b->prev = stack_b;
    node2b->next = NULL;
    stack_b->next = node2b;

    t_stack_node *node3b = malloc(sizeof(t_stack_node));
    node3b->value = 6;
    node3b->position = 3;
    node3b->prev = node2b;
    node3b->next = NULL;
    node2b->next = node3b;

    // Print the original stack
    printf("Original Stack 1: \n");
    print_stack(stack_a);
    printf("Original Stack 2: \n");
    print_stack(stack_b);

    // Apply ra function
    pa(&stack_a, &stack_b);

    // Print the modified stack
    printf("Modified Stack 1: \n");
    print_stack(stack_a);
    printf("Modified Stack 2: \n");
    print_stack(stack_b);

    // Free the allocated memory for the stack
    free_list(stack_a);
    free_list(stack_b);
    return 0;
}
*/