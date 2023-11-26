/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:50:26 by srudman           #+#    #+#             */
/*   Updated: 2023/11/26 18:43:46 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

void	sa_movement(t_stack_node *a)
{
	write(1, "sa\n", 3);
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

void	sb_movement(t_stack_node *a)
{
	write(1, "sb\n", 3);
}

// ss : sa and sb at the same time.

void	ss_movement(t_stack_node *a)
{
	write(1, "ss\n", 3);
}