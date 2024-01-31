/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:05:33 by srudman           #+#    #+#             */
/*   Updated: 2024/01/31 21:25:41 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Every A needs a ´closest smaller nbr to A' from stack B. 
A has to have a larger number to B when we push it.
If A is smaller to B, then the 'closes smaller number to A' 
is the max_value in B.
Every A node is assigned a ´closest smallest number to A´
*/

void	assign_target_a(t_stack_node **b, t_stack_node *current_b,
						t_stack_node *current_a, long tmp_best_match)
{
	t_stack_node	*target_node;

	target_node = NULL;
	while (current_b)
	{
		if (current_b->value < current_a->value 
			&& (current_b->value) > tmp_best_match)
		{
			tmp_best_match = (current_b->value);
			target_node = current_b;
		}
		current_b = current_b->next;
	}
	if (tmp_best_match == LONG_MIN)
		(current_a)->target = get_max(*b);
	else 
		(current_a)->target = target_node;
}

t_stack_node	*set_target_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current_a;
	t_stack_node	*current_b;

	(current_a) = *a;
	while (current_a)
	{
		current_b = *b;
		assign_target_a(b, current_b, current_a, LONG_MIN);
		(current_a) = (current_a)->next;
	}
	return (*a);
}

int	ft_push_cost_below_median(t_stack_node *a, int len_b)
{
	if (a->target->position <= (len_b / 2))
	{
		if (a->position >= a->target->position)
			return (a->position - 1);
		else
			return (a->target->position - 1);
	}
	else
		return (a->position + len_b - (a->target->position));
}

int	ft_push_cost_above_median(t_stack_node *a, int len_a, int len_b)
{
	if (a->target->position > (len_b / 2))
	{
		if (len_a - (a->position) >= (len_b - (a->target->position)))
			return (len_a - (a->position) + 1);
		else
			return (len_b - (a->target->position) + 1);
	}
	else
		return (len_a - (a->position) + (a->target->position));
}

t_stack_node	*no_of_moves_needed(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*curr_a;
	int				len_a;
	int				len_b;

	curr_a = *a;
	len_a = ft_stacksize(*a);
	len_b = ft_stacksize(*b);
	while (curr_a)
	{
		(curr_a)->push_cost = 0;
		if (curr_a->position <= (len_a / 2))
			curr_a->push_cost = ft_push_cost_below_median(curr_a, len_b);
		else
			curr_a->push_cost = ft_push_cost_above_median(curr_a, len_a, len_b);
		curr_a = curr_a->next;
	}
	return (*a);
}

/*
// Main to test push_cost
void print_list(t_stack_node *head)
{
    while (head)
    {
        printf("Value: %d, Position: %d, Push Cost: %d\n", 
			head->value, head->position, head->push_cost);
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

    // Applying cost_analysis function
    no_of_moves_needed(&a, &b);

    printf("Modified List A (after cost analysis):\n");
    print_list(a);

    return 0;
}
*/

/*
// Main to test out set_target
void print_stack(t_stack_node *head) {
    while (head) {
        printf("%d and target %d; ", head->value, 
			head->target->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
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
    print_stack(a);

    printf("List B: ");
    print_stack(b);

    t_stack_node *modifiedListA = set_target_a(&a, &b);

    printf("Modified List A: ");
    print_stack(modifiedListA);

    return 0;
}
*/