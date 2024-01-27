/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:38:58 by srudman           #+#    #+#             */
/*   Updated: 2024/01/27 14:19:54 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
void run_algorithm(t_stack_node **a, t_stack_node **b)
{
    if (ft_stacksize(*a) >= 4 && !stack_is_sorted(*a))
        pb(a, b);        
    if (ft_stacksize(*a) >= 4 && !stack_is_sorted(*a))
        pb(a, b);
    while (ft_stacksize(*a) > 3)
    {
        set_target_a(a, b);
        no_of_moves_needed(a, b);
        move_a_to_b(a, b);
    }
    sort_three(a);
    while (*b)
    {
        set_target_b(a, b); // looking for the closest bigger number
        move_b_to_a(a, b); // move everything from B to A
    }
    put_min_on_top(a);// some rotating
}

// need to test
void    put_min_on_top(t_stack_node **a)
{
    int min_value_a;
    
    min_value_a = (get_min(*a))->value;
    while ((*a)->value != min_value_a)
    {
        if ((*a)->position <= ft_stacksize(*a)/2)
            ra(a);
        else
            rra(a);
    }
}

// need to test
void    move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *best;
    
    best = set_cheapest(b);
    if (best->target->position <= ft_stacksize(*a)/2 
    && best->target->position != 1)
    {
        while (best->target->position != 1)
        {
            if (best->position == 1 || best->target->position == 1)
                break ;
            ra(a);
        }
    }
    else
    {
        while (best->target->position != 1)
        {
            if (best->position == 1 || best->target->position == 1)
                break ;
            rra(a);
        }
    }
    pa(a, b);
    best->cheapest = false; // see if that needs changing
}

// I think I will then need to rest the cheapest to false
void    move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *best;

    best = set_cheapest(a); // handle case if best = NULL
    if (best->position <= ft_stacksize(*a)/2)
    {
        if (best->target->position <= ft_stacksize(*b))
        {
            while (best->position != 1 || best->target->position != 1)
            {
                if (best->position == 1 || best->target->position == 1)
                    break ;
                rr(a, b); 
            }
        }
        else
        {
            while (best->position != 1 && best->position != 1)
            {
                if (best->position == 1 || best->target->position == 1)
                    break ;
                ra(a);
            }
            while (best->target->position != 1)
            {
                if (best->position == 1 || best->target->position == 1)
                    break ;
                rrb(b);
            }
        }
    }
    if (best->position > ft_stacksize(*a)/2)
    {
        if (best->target->position > ft_stacksize(*b))
        {
            while (best->position != 1 || best->target->position != 1)
            {
                if (best->position == 1 || best->target->position == 1)
                    break ;
                rrr(a, b);
            }
        }
        else
        {
            while (best->position != 1)
            {
                if (best->position == 1 || best->target->position == 1)
                    break ;
                rra(a);
            }
            while (best->target->position != 1)
            {
                if (best->position == 1 || best->target->position == 1)
                    break ;
                rb(b);
            }
        }
    }
    pb(a, b);
    best->cheapest = false; // see if that needs changing
}


// cc push_swap.c push_swap.h movements_reverse_rotate.c movements_swap.c movements_rotate.c math_operations.c linked_stacks_utils.c movements_push.c

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
  1  printf("Initial Stack:\n");
    print_stack(sorted_stack);
3&sorted_stack);
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
void print_list(t_stack_node *stack) {
    while (stack != NULL) {
        printf("Value: %d, Position: %d, Push Cost: %d, Cheapest: %d\n",
               stack->value, stack->position, stack->push_cost, stack->cheapest);
        stack = stack->next;
    }1
    printf("\n");
}

int main() {
    // Create a sample stack for testing
    t_stack_node node1 = {4, 1, 3, false, NULL, NULL, NULL};
    t_stack_node node2 = {2, 2, 2, false, NULL, &node1, NULL};
    t_stack_node node3 = {7, 3, 4, false, NULL, &node2, NULL};
    t_stack_node node4 = {5, 4, 3, false, NULL, &node3, NULL};
    t_stack_node node5 = {10, 5, 2, false, NULL, &node4, NULL};
    t_stack_node node6 = {8, 6, 2, false, NULL, &node5, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;

    t_stack_node *a = &node1;

    printf("Original List A:\n");
    print_list(a);

    // Applying set_cheapest function
    set_cheapest(&a);

    printf("Modified List A (after set_cheapest):\n");
    print_list(a);

    return 0;
}
*/

// main to test move_a_to_b

/*
void print_list(t_stack_node *stack) {
    while (stack != NULL) {
        printf("Value: %d, Position: %d, Push Cost: %d, Cheapest: %d\n",
               stack->value, stack->position, stack->push_cost, stack->cheapest);
        stack = stack->next;
    }
    printf("\n");
}

int main()
{
    // Create a sample stack for testing
    t_stack_node node1 = {4, 1, 0, true, NULL, NULL, NULL};
    t_stack_node node2 = {2, 2, 0, false, NULL, &node1, NULL};
    t_stack_node node3 = {7, 3, 0, false, NULL, &node2, NULL};
    t_stack_node node4 = {5, 4, 0, true, NULL, &node3, NULL};
    t_stack_node node5 = {10, 5, 0, false, NULL, &node4, NULL};  // Additional nodes
    t_stack_node node6 = {8, 6, 0, false, NULL, &node5, NULL};   // Additional nodes
    t_stack_node nodeb1 = {1, 1, 0, false, NULL, NULL, NULL};
    t_stack_node nodeb2 = {6, 2, 0, false, NULL, &nodeb1, NULL};
    t_stack_node nodeb3 = {12, 3, 0, false, NULL, &nodeb2, NULL};  // Additional nodes
    t_stack_node nodeb4 = {3, 4, 0, false, NULL, &nodeb3, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;  // Additional nodes
    node5.next = &node6;  // Additional nodes

    nodeb1.next = &nodeb2;
    nodeb2.next = &nodeb3;
    nodeb3.next = &nodeb4;  // Additional nodes

    node1.target = &nodeb4;
    node2.target = &nodeb1;
    node3.target = &nodeb2;
    node4.target = &nodeb4;
    node5.target = &nodeb2;  // Additional nodes
    node6.target = &nodeb2;  // Additional nodes

    t_stack_node *a = &node1;
    t_stack_node *b = &nodeb1;

    printf("Original List A:\n");
    print_list(a);

    printf("List B:\n");
    print_list(b);

    // Applying move_a_to_b function
    move_a_to_b(&a, &b);

    printf("Modified List A (after move_a_to_b):\n");
    print_list(a);

    printf("Modified List B (after move_a_to_b):\n");
    print_list(b);

    return 0;
}
*/

/*
// main to test move_b_to_a
void print_list(t_stack_node *stack) {
    while (stack != NULL) {
        printf("Value: %d, Position: %d, Push Cost: %d, Cheapest: %d\n",
               stack->value, stack->position, stack->push_cost, stack->cheapest);
        stack = stack->next;
    }
    printf("\n");
}

int main()
{
    // Create a sample stack for testing
    t_stack_node node1 = {4, 1, 10, false, NULL, NULL, NULL};
    t_stack_node node2 = {2, 2, 3, false, NULL, &node1, NULL};
    t_stack_node node3 = {7, 3, 1, false, NULL, &node2, NULL};
    t_stack_node node4 = {5, 4, 2, false, NULL, &node3, NULL};
    t_stack_node node5 = {10, 5, 2, false, NULL, &node4, NULL};  // Additional nodes
    t_stack_node node6 = {8, 6, 7, false, NULL, &node5, NULL};   // Additional nodes
    t_stack_node nodeb1 = {1, 1, 0, false, NULL, NULL, NULL};
    t_stack_node nodeb2 = {6, 2, 0, false, NULL, &nodeb1, NULL};
    t_stack_node nodeb3 = {12, 3, 0, false, NULL, &nodeb2, NULL};  // Additional nodes
    t_stack_node nodeb4 = {3, 4, 0, false, NULL, &nodeb3, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;  // Additional nodes
    node5.next = &node6;  // Additional nodes

    nodeb1.next = &nodeb2;
    nodeb2.next = &nodeb3;
    nodeb3.next = &nodeb4;  // Additional nodes

    node1.target = &nodeb4;
    node2.target = &nodeb1;
    node3.target = &nodeb2;
    node4.target = &nodeb4;
    node5.target = &nodeb2;  // Additional nodes
    node6.target = &nodeb2;  // Additional nodes

    t_stack_node *a = &node1;
    t_stack_node *b = &nodeb1;

    printf("Original List A:\n");
    print_list(b);

    printf("List B:\n");
    print_list(a);

    // Applying move_b_to_a function
    move_b_to_a(&b, &a);

    printf("Modified List A (after move_b_to_a):\n");
    print_list(b);

    printf("Modified List B (after move_b_to_a):\n");
    print_list(a);

    return 0;
}
*/