/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_stacks_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:28:59 by srudman           #+#    #+#             */
/*   Updated: 2023/11/25 20:03:09 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Incorportate the PREVIOUS node address as well. */
/*
This is in the header file already.
typedef struct	s_stack_node
{
	int		value;
	int		position;
	struct s_stack_node *prev;
	struct s_stack_node *next;
	// more meta data missing
}				t_stack_node;
*/

/* *ft_nodenew allocates with malloc and returns a new node. The 
member variable  ’value’ is initialized with  the value of the 
parameter ’value’. The variable ’next’ is initialized to NULL. */

t_stack_node	*ft_nodenew(int *nbr)
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

/* Adds the node ’new’ at the end of the list. 
**first is the address to the first link of a list */

t_stack_node	ft_nodeadd_back(t_stack_node **first, t_stack_node *new)
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
	return (new);
}

/* Counts the number of nodes in a list. 
*first: The begining of the stack. */

int	ft_stacksize(t_stack_node *first)
{
	int		size;
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

/*Iterates the stack and applies the function
’f’ on the content of each node. I'll use this to 
change the index value of the node once I execute
the movements. */

void	ft_lstiter(t_stack_node *first, void (*f)(void *))
{
	t_stack_node	*current;

	current = first;
	while (current != NULL)
	{
		f(current->index);
		current = current->next;
	}
}

/* Returns the last node of the stack. */

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

// STILL NEED TO FIGURE OUT BOTTOM TWO

/*Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed.*/

void	ft_nodedelone(t_stack_node *first, void (*del)(void *))
{
	del(first->content);
	free(first);
}

/* Deletes and frees the given node and every
successor of that node, using the function ’del’
and free(3).
Finally, the pointer to the list must be set to
NULL. */

void	ft_nodesclear(t_stack_node **first, void (*del)(void *))
{
	t_stack_node	*current;
	t_stack_node	*buffer;

	if (!first || !del)
		return ;
	current = *first;
	while (current != NULL)
	{
		buffer = current->next;
		del(current->content);
		free(current);
		current = buffer;
	}
	*first = NULL;
}