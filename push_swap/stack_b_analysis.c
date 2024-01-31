/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:01:54 by srudman           #+#    #+#             */
/*   Updated: 2024/01/31 21:31:02 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Every B needs a ´closest larger nbr to B' from stack A. 
A has to have a larger number to B when we push it.
If A is smaller to B, then the 'closes smaller number to A' is 
the max_value in B.
Every A node is assigned a ´closest smallest number to A´
*/

void	assign_target_b(t_stack_node **a, t_stack_node *current_a,
						t_stack_node *current_b, long tmp_best_match)
{
	t_stack_node	*target_node;

	target_node = NULL;
	while (current_a)
	{
		if (current_a->value > current_b->value 
			&& current_a->value < tmp_best_match)
		{
			tmp_best_match = current_a->value;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	if (tmp_best_match == LONG_MAX)
		current_b->target = get_min(*a);
	else 
		current_b->target = target_node;
}

t_stack_node	*set_target_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current_a;
	t_stack_node	*current_b;

	current_b = *b;
	while (current_b)
	{
		current_a = *a;
		assign_target_b(a, current_a, current_b, LONG_MAX);
		current_b = current_b->next;
	}
	return (*b);
}
