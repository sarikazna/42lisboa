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

t_stack_node    *set_target(t_stack_node **a, t_stack_node **b);

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
Push the nodes from A to B until there are only three nodes left in A.
Each time a node is pushed to B, B is sorted in a descending order.
The first two nodes are pushed without checking anything. We now have
the two numbers in B - a current min and a current max.
Everytime you make the push, you check if there are 3 nodes in stack A
*/
t_stack_node *run_algorithm(t_stack_node **a, t_stack_node **b)
{
    if (ft_stacksize(*a) >= 4 && !stack_is_sorted(*a))
        pb(a, b);        
    if (ft_stacksize(*a) >= 4 && !stack_is_sorted(*a))
        pb(a, b);
    while (ft_stacksize(*a) > 3)
    {
        set_target(a, b);
        // add more values to A (set target node, calculate push, above or under median)
        // move everything from A to B, one by one
    }
    sort_three(a);
    while (*b)
    {
        // add more values to B
        // move everything from B to A
    }
}

/*
Every A needs a ´closest smaller nbr to A' from stack B. 
A has to have a larger number to B when we push it.
If A is smaller to B, then the 'closes smaller number to A' is the max_value in B.
Every A node is assigned a ´closest smallest number to A´
*/
t_stack_node    *set_target(t_stack_node **a, t_stack_node **b)
{
    long            tmp_best_match;
    t_stack_node    *current_a;
    t_stack_node    *current_b;
    t_stack_node    *target_node;

    current_a = *a;
    while (current_a)
    {
        tmp_best_match = LONG_MIN;
        current_b = *b;
        target_node = NULL;
        while (current_b)
        {
            if (current_b->value < current_a->value 
                && current_b->value > tmp_best_match)
            {
                tmp_best_match = current_b->value;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        if (tmp_best_match == LONG_MIN)
            current_a->target = get_max(*b);
        else 
            current_a->target = target_node;
        current_a = current_a->next;
    }
    return (*a);
}

/*
THIS NEEDS TO OPTIMISED!
cc push_swap.c push_swap.h movements_reverse_rotate.c movements_swap.c movements_rotate.c math_operations.c linked_stacks_utils.c movements_push.c
*/
t_stack_node    *cost_analysis(t_stack_node **a, t_stack_node **b)
{
    int             a_len;
    int             b_len;
    t_stack_node    *current_a;

    current_a = *a;
    a_len = ft_stacksize(*a);
    b_len = ft_stacksize(*b);
    while (current_a)
    {
        if (current_a->position <= a_len/2)        
            current_a->push_cost = current_a->position;
        else if (current_a->position > a_len/2)   
            current_a->push_cost = a_len - (current_a->position) + 1;
        if (current_a->target->position <= b_len/2)
            current_a->push_cost += current_a->target->position - 1;
        else
            current_a->push_cost += b_len - (current_a->target->position);
        current_a = current_a->next;
    }
    return (*a);
}

/*
Main to test sort_three
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
*/

/*
Main to test out set_target
void print_list(t_stack_node *head)
{
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void print_stack(t_stack_node *head)
{
    while (head)
    {
        printf("%d and target %d; ", head->value, head->target->value);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    // Create a sample stack for testing
    t_stack_node node1 = {4, 1, 0, false, NULL, NULL, NULL};
    t_stack_node node2 = {2, 2, 0, false, NULL, &node1, NULL};
    t_stack_node node3 = {7, 3, 0, false, NULL, &node2, NULL};
    t_stack_node node4 = {5, 4, 0, false, NULL, &node3, NULL};
    t_stack_node nodeb1 = {1, 1, 0, false, NULL, NULL, NULL};
    t_stack_node nodeb2 = {6, 2, 0, false, NULL, &nodeb1, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    nodeb1.next = &nodeb2;

    t_stack_node *a = &node1;
    t_stack_node *b = &nodeb1;

    printf("Original List A: ");
    print_list(a);

    printf("List B: ");
    print_list(b);

    t_stack_node *modifiedListA = set_target(&a, &b);

    printf("Modified List A: ");
    print_stack(modifiedListA);

    return 0;
}
*/

void print_list(t_stack_node *head)
{
    while (head)
    {
        printf("Value: %d, Position: %d, Push Cost: %d\n", head->value, head->position, head->push_cost);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    // Create a sample stack for testing
    t_stack_node node1 = {4, 1, 0, false, NULL, NULL, NULL};
    t_stack_node node2 = {2, 2, 0, false, NULL, &node1, NULL};
    t_stack_node node3 = {7, 3, 0, false, NULL, &node2, NULL};
    t_stack_node node4 = {5, 4, 0, false, NULL, &node3, NULL};
    t_stack_node nodeb1 = {1, 1, 0, false, NULL, NULL, NULL};
    t_stack_node nodeb2 = {6, 2, 0, false, NULL, &nodeb1, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    nodeb1.next = &nodeb2;

    node1.target = &nodeb1;
    node2.target = &nodeb1;
    node3.target = &nodeb2;
    node4.target = &nodeb1;

    t_stack_node *a = &node1;
    t_stack_node *b = &nodeb1;

    printf("Original List A:\n");
    print_list(a);

    printf("List B:\n");
    print_list(b);

    // Applying cost_analysis function
    cost_analysis(&a, &b);

    printf("Modified List A (after cost analysis):\n");
    print_list(a);

    return 0;
}