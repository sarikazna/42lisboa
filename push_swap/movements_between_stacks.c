/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_between_stacks.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:51:06 by srudman           #+#    #+#             */
/*   Updated: 2024/01/29 12:44:50 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack_node **a, t_stack_node **b,
		t_stack_node *best, char c)
{
	while (best->position != 1)
	{
		if (best->position == 1)
			break ;
		if (c == 'a')
			ra(a);
		if (c == 'b')
			rb(b);
	}
}

void	rev_rotate_stack(t_stack_node **a, t_stack_node **b,
		t_stack_node *best, char c)
{
	while (best->position != 1)
	{
		if (best->position == 1)
			break ;
		if (c == 'a')
			rra(a);
		if (c == 'b')
			rrb(b);
	}
}

/*  '0' = rr movement
	'r' = rrr movement */
void	rotate_a_and_b(t_stack_node **a, t_stack_node **b,
		t_stack_node *best, char c)
{
	while (best->position != 1 || best->target->position != 1)
	{
		if (best->position == 1 || best->target->position == 1)
			break ;
		if (c == '0')
			rr(a, b);
		if (c == 'r')
			rrr(a, b);
	}
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*best;

	best = set_cheapest(a);
	if (best->position <= (ft_stacksize(*a) / 2)
		&& best->target->position <= (ft_stacksize(*b) / 2))
		rotate_a_and_b(a, b, best, '0');
	else if (best->position > (ft_stacksize(*a) / 2)
		&& best->target->position > (ft_stacksize(*b) / 2))
		rotate_a_and_b(a, b, best, 'r');
	if (best->position <= (ft_stacksize(*a) / 2))
		rotate_stack(a, b, best, 'a');
	else if (best->position > (ft_stacksize(*a) / 2))
		rev_rotate_stack(a, b, best->target, 'a');
	if (best->target->position <= (ft_stacksize(*b) / 2))
		rotate_stack(a, b, best->target, 'b');
	else if (best->target->position > (ft_stacksize(*b) / 2))
		rev_rotate_stack(a, b, best->target, 'b');
	pb(a, b);
	best->cheapest = false;
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*best;

	best = (*b);
	if (best->target->position <= (ft_stacksize(*a) / 2))
		rotate_stack(a, b, best->target, 'a');
	else
		rev_rotate_stack(a, b, best->target, 'a');
	pa(a, b);
}

// main to test move_a_to_b
/*
void print_list(t_stack_node *stack) {
    while (stack != NULL) {
        printf("Value: %d, Position: %d, Push Cost: %d, 
            Cheapest: %d\n", stack->value, stack->position, \
            stack->push_cost, stack->cheapest);
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
    t_stack_node node5 = {10, 5, 0, false, NULL, &node4, NULL};
    t_stack_node node6 = {8, 6, 0, false, NULL, &node5, NULL};
    t_stack_node nodeb1 = {1, 1, 0, false, NULL, NULL, NULL};
    t_stack_node nodeb2 = {6, 2, 0, false, NULL, &nodeb1, NULL};
    t_stack_node nodeb3 = {12, 3, 0, false, NULL, &nodeb2, NULL};
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
        printf("Value: %d, Position: %d, Push Cost: %d, 
            Cheapest: %d\n", stack->value, stack->position,
            stack->push_cost, stack->cheapest);
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
    t_stack_node node5 = {10, 5, 2, false, NULL, &node4, NULL};
    t_stack_node node6 = {8, 6, 7, false, NULL, &node5, NULL};
    t_stack_node nodeb1 = {1, 1, 0, false, NULL, NULL, NULL};
    t_stack_node nodeb2 = {6, 2, 0, false, NULL, &nodeb1, NULL};
    t_stack_node nodeb3 = {12, 3, 0, false, NULL, &nodeb2, NULL};
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
