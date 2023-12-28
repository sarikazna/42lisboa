/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:53:11 by srudman           #+#    #+#             */
/*   Updated: 2023/12/28 13:52:35 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Should I also check if the len of stack is higher than 1?
// TO DO: change position numbering as well.
t_stack_node	**rev_rotate_movement(t_stack_node **head)
{
    // (*head)->prev = (ft_nodelast(*head));
    // (*head)->next->prev = NULL;
    // (ft_nodelast(*head))->next = *head;
    // (*head)->next = NULL;
    // while ((*head)->prev)
    //     (*head) = (*head)->prev;
    return (head);
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

int rra(t_stack_node **a)
{
	a = rev_rotate_movement(a);
	if (a)
	{
 		write(1, "ra\n", 3);
		return (1);
	}
	return (0);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.

int rrb(t_stack_node **b)
{
	b = rev_rotate_movement(b);
	if (b)
	{
 		write(1, "rb\n", 3);
		return (1);
	}
	return (0);
}

// rrr : rra and rrb at the same time

int rrr(t_stack_node **a, t_stack_node **b)
{
	a = rev_rotate_movement(a);
	b = rev_rotate_movement(b);
	if (a && b)
	{
 		write(1, "rr\n", 3);
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
    while (head != NULL)
    {
        printf("Value: %d, Pos.: %d\n", head->value, head->position);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // I add 4 nodes
    t_stack_node *stack = malloc(sizeof(t_stack_node));
    stack->value = 3;
    stack->position = 1;
    stack->prev = NULL;

    t_stack_node *node2 = malloc(sizeof(t_stack_node));
    node2->value = 6;
    node2->position = 2;
    node2->prev = stack;
    node2->next = NULL;
    stack->next = node2;

    t_stack_node *node3 = malloc(sizeof(t_stack_node));
    node3->value = 9;
    node3->position = 3;
    node3->prev = node2;
    node3->next = NULL;
    node2->next = node3;

    t_stack_node *node4 = malloc(sizeof(t_stack_node));
    node4->value = 12;
    node4->position = 4;
    node4->prev = node3;
    node4->next = NULL;
    node3->next = node4;

    // Print the original stack
    printf("Original Stack: \n");
    print_stack(stack);

    // Apply ra function
    rra(&stack);

    // Print the modified stack
    printf("Modified Stack: \n");
    print_stack(stack);

    // Free the allocated memory for the stack
    free_list(stack);
    return 0;
}
*/