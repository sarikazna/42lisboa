/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:12:43 by srudman           #+#    #+#             */
/*   Updated: 2024/01/22 18:29:36 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// make sure it handles input of a singe +
int	syntax_error(char *nptr)
{
	int	i;
	int	operator;

	i = 0;
	operator = 0;
	if (*nptr == '\0')
		return(0);
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]) && !(nptr[i] == '+' || nptr[i] == '-'))
			return (0);
		if (nptr[i] == '+' || nptr[i] == '-')
			operator++;
		i++;
	}
	if (operator <= 1)
		return (1);
	return (0);
}

int	contains_duplicate(t_stack_node *a, int tmp)
{
	t_stack_node	*current;
	
	current = a;
	while (current)
	{
		if (tmp == current->value)
			return (1);
		current = current->next;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	// Test for syntax_error function.
// 	char *nptr = "3";
// 	printf("%d", syntax_error(nptr));
// 	return (0);	
// }
