/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:50:26 by srudman           #+#    #+#             */
/*   Updated: 2023/12/11 13:27:34 by srudman          ###   ########.fr       */
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

// Should I also check if the len of stack is higher than 1?
t_stack_node	**swap_movement(t_stack_node **head)
{
	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
		return(NULL);
	(*head)->position += 1;
	(*head)->next->position -= 1;
    *head = (*head)->next;
    if ((*head)->next)
        (*head)->next->prev = (*head)->prev;
    (*head)->prev->next = (*head)->next;
    (*head)->next = (*head)->prev;
    (*head)->prev->prev = *head;
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
	if (swap_movement(b))
	{
 		write(1, "sb\n", 3);
		return (1);
	}
	return (0);
}

// ss : sa and sb at the same time.

int ss(t_stack_node **a, t_stack_node **b)
{
	if (swap_movement(a) && swap_movement(b))
	{
 		write(1, "ss\n", 3);
		return (1);
	}
	return (0);
}

/*
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
        printf("Value: %d, Pos.: %d\n", void    		no_of_moves_needed(t_stack_node **a, t_stack_node **b);head->value, head->position);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create a stack with a few elements
    t_stack_node *stack = malloc(sizeof(t_stack_node));
    stack->value = 3;
    stack->position = 1;
    stack->prev = NULL;
    stack->next = malloc(sizeof(t_stack_node));
    stack->next->value = 7;
    stack->next->position = 2;
    stack->next->prev = stack;
    stack->next->next = NULL;

    // Print the original stack
    printf("Original Stack: \n");
    print_stack(stack);

    // Apply sa function
    sa(&stack);

    // Print the modified stack
    printf("Modified Stack: \n");
    print_stack(stack);

    // Free the allocated memory for the stack
    free_list(stack);
    return 0;
}
*/