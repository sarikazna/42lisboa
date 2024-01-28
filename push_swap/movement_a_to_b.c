/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_a_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:51:06 by srudman           #+#    #+#             */
/*   Updated: 2024/01/28 19:58:04 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_stack(t_stack_node **a, t_stack_node **b, t_stack_node *best, char c)
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

void    rev_rotate_stack(t_stack_node **a, t_stack_node **b, t_stack_node *best, char c)
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

// '0' = rr movement
// 'r' = rrr movement
void    rotate_a_and_b(t_stack_node **a, t_stack_node **b, t_stack_node *best, char c)
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

void    move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *best;

    best = set_cheapest(a); // handle case if best = NULL
    if (best->position <= ft_stacksize(*a)/2)
    {
        if (best->target->position <= ft_stacksize(*b)/2)
        {
            rotate_a_and_b(a, b, best, '0');
            rotate_stack(a, b, best->target, 'b');
        }
        else
            rev_rotate_stack(a, b, best->target, 'b');
        rotate_stack(a, b, best, 'a');
    }
    else if (best->position > ft_stacksize(*a)/2)
    {
        if (best->target->position > ft_stacksize(*b)/2)
        {
            rotate_a_and_b(a, b, best, 'r');
            rev_rotate_stack(a, b, best->target, 'b');
        }
        else
            rotate_stack(a, b, best->target, 'b');
        rev_rotate_stack(a, b, best->target, 'a');
    }
    pb(a, b);
    best->cheapest = false;
}

void    move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *best;
    
    best = (*b);
    if (best->target->position <= ft_stacksize(*a)/2)
        rotate_stack(a, b, best->target, 'a');
    else
        rev_rotate_stack(a, b, best->target, 'a');
    pa(a, b);
}
