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

t_stack_node *sort_three(t_stack_node **a)
{
    t_stack_node    *max_node;

    max_node = get_max(*a);
    if (max_node == *a)
        ra(a);
    else if ((*a)->next == max_node)
        rra(a);
    if ((*a)->value > (*a)->next->value)
        sa(a);
    if (stack_is_sorted(*a))
        return (*a);
    return (NULL);
}

/*
STEP 9 - Turk Algorithm
1. Push the nodes from A to B until there are only three nodes left in A.
Each time a node is pushed to B, B is sorted in a descending order.
The first two nodes are pushed without checking anything. We now have
the two numbers in B - a current min and a current max.
2. Everytime you make the push, you check if there are 3 nodes in stack A
3. Every A needs a ´closest smaller nbr to A' from stack B. 
A has to have a larger number to B when we push it.
If A is smaller to B, then the 'closes smaller number to A' is the max_value in B.
Every A node is assigned a ´closest smallest number to A´
*/
t_stack_node *run_algorithm(t_stack_node **a, t_stack_node **b)
{
    if (t_stacksize(*a) >= 4 && !stack_is_sorted(*a))
        pb(a, b);        
    if (t_stacksize(*a) >= 4 && !stack_is_sorted(*a))
        pb(a, b);
    while (t_stacksize(*a) > 3)
    {
        set_target(a, b);
        // add more values to A (set target node, calculate push, above or under median)
        // move everything from A to B
    }
    sort_three(a);
    while (*b)
    {
        // add more values to B
        // move everything from B to A
    }
}

void    set_target(t_stack_node **a, t_stack_node **b)
{
    long            tmp_best_match;
    t_stack_node    *current_b;
    t_stack_node    *target_node;

    tmp_best_match = LONG_MIN;
    current_b = *b;
    //  Left off here 37min: https://www.youtube.com/watch?v=wRvipSG4Mmk
}

void print_stack(t_stack_node *head) {
    t_stack_node *current = head;

    while (current != NULL) {
        printf("Value: %d Position: %d; ", current->value, current->position);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    // Create a sample sorted stack
    t_stack_node *sorted_stack = malloc(sizeof(t_stack_node));
    sorted_stack->value = 5;
    sorted_stack->position = 1;
    sorted_stack->prev = NULL;  // Initialize prev pointer
    sorted_stack->next = malloc(sizeof(t_stack_node));
    sorted_stack->next->value = 6;
    sorted_stack->next->position = 2;
    sorted_stack->next->prev = sorted_stack;  // Set prev pointer
    sorted_stack->next->next = malloc(sizeof(t_stack_node));
    sorted_stack->next->next->value = 7;
    sorted_stack->next->next->position = 3;
    sorted_stack->next->next->prev = sorted_stack->next;  // Set prev pointer
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
