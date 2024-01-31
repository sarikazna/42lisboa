/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_stacks_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:28:59 by srudman           #+#    #+#             */
/*   Updated: 2024/01/31 21:42:21 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* *ft_nodenew allocates with malloc and returns a new node. The 
member variable  ’value’ is initialized with  the value of the 
parameter ’value’. The variable ’next’ is initialized to NULL. */

t_stack_node	*ft_nodenew(int nbr)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (new == NULL)
		return (NULL);
	new->value = nbr;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/* ft_nodeadd_back adds the node ’new’ at the end of the list. 
**first is the address to the first link of a list */

t_stack_node	*ft_nodeadd_back(t_stack_node **first, t_stack_node *new)
{
	t_stack_node	*current;

	if (*first == NULL)
		*first = new;
	else
	{
		current = *first;
		while (current->next != NULL)
			current = current->next;
		new->prev = current;
		current->next = new;
	}
	new->position = ft_stacksize(*first);
	return (new);
}

/* ft_stacksize counts the number of nodes in a list. 
*first: The begining of the stack. */

int	ft_stacksize(t_stack_node *first)
{
	int				size;
	t_stack_node	*current;

	current = first;
	size = 0;
	while (current != NULL)
	{
		current = current->next;
		size++;
	}
	return (size);
}

/* ft_nodelast returns the last node of the stack. */

t_stack_node	*ft_nodelast(t_stack_node *first)
{
	t_stack_node	*current;
	t_stack_node	*previous;

	current = first;
	previous = NULL;
	while (current != NULL)
	{
		previous = current;
		current = current->next;
	}
	return (previous);
}

/* ft_nodefirst returns the first node of the stack. */

t_stack_node	*ft_nodefirst(t_stack_node *last)
{
	if (last == NULL)
		return (NULL);
	while (last->prev != NULL)
		last = last->prev;
	return (last);
}
