/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:38:58 by srudman           #+#    #+#             */
/*   Updated: 2023/11/23 14:39:08 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack_node *head);

// needs work
t_stack_node *sort_three(t_stack_node **a)
{
    t_stack_node    *max_node;

    max_node = get_max(*a);
    print_stack(*a);
    if (max_node == *a)
        ra(a);
    // this is causing segmenetation fault
//    else if (max_node->position == 2)
    else if ((*a)->next == max_node)
    {
        rra(a);
        printf("Stack after rra(&a):\n");
        print_stack(*a);
    }
    // this is causing segmenetation fault
    if ((*a)->value > (*a)->next->value)
    {
        sa(a);
        printf("Stack after sa(&a):\n");
        print_stack(*a);
    }
    if (stack_is_sorted(*a))
        return (*a);
    return (NULL);
}


void print_stack(t_stack_node *head) {
    t_stack_node *current = head;

    while (current != NULL) {
        printf("Value: %d Position: %d;", current->value, current->position);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    // Create a sample sorted stack
    t_stack_node *sorted_stack = malloc(sizeof(t_stack_node));
    sorted_stack->value = 17;
    sorted_stack->position = 1;
    sorted_stack->next = malloc(sizeof(t_stack_node));
    sorted_stack->next->value = 18;
    sorted_stack->next->position = 2;
    sorted_stack->next->next = malloc(sizeof(t_stack_node));
    sorted_stack->next->next->value = 15;
    sorted_stack->next->next->position = 3;
    sorted_stack->next->next->next = NULL;

    // Print the sorted stack
    printf("Initial Stack:\n");
    print_stack(sorted_stack);

    // Check if the stack is sorted
    sorted_stack = sort_three(&sorted_stack);
    if (sorted_stack)
    {
        printf("Sorted Stack:\n");
        print_stack(sorted_stack);
    }
    else
    {
        printf("Error.\n");
    }

    // Free the allocated memory
    free_list(sorted_stack);

    return 0;
}
