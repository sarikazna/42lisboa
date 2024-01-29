/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:38:58 by srudman           #+#    #+#             */
/*   Updated: 2024/01/29 18:13:39 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*sort_three(t_stack_node **a)
{
	t_stack_node	*max_node;

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
Everytime you make the push, you check if there are 3 nodes in stack A.
Once we have 3 nodes in stack A, we sort those three. Then we start
the process of pushing each node form node B to A. But first we find
a target node for each node in B from stack A. The target node is its
closest bigger number.
Then we rotate the stack A so we make sure that the first node is on top.
*/

void	run_algorithm(t_stack_node **a, t_stack_node **b)
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
		set_target_b(a, b);
		move_b_to_a(a, b);
	}
	put_min_on_top(a);
}

void	put_min_on_top(t_stack_node **a)
{
	int	min_value_a;

	min_value_a = (get_min(*a))->value;
	while ((*a)->value != min_value_a)
	{
		if ((*a)->position <= (ft_stacksize(*a) / 2))
			ra(a);
		else if ((*a)->position > (ft_stacksize(*a) / 2))
			rra(a);
	}
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
