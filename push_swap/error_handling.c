/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:12:43 by srudman           #+#    #+#             */
/*   Updated: 2024/01/31 21:40:35 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// It handles input of a singe + or - and reports it as error.
int	syntax_error(char *nptr)
{
	int	i;
	int	operator;

	i = 0;
	operator = 0;
	if (*nptr == '\0')
		return (0);
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]) && !(nptr[i] == '+' || nptr[i] == '-'))
			return (0);
		if (nptr[i] == '+' || nptr[i] == '-')
		{
			if (nptr[i + 1] == '\0')
				return (0);
			operator++;
		}
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

// Test for syntax_error function.
// #include <stdio.h>
// int main(void)
// {
// 	char *nptr = "3";
// 	printf("%d", syntax_error(nptr));
// 	return (0);	
// }
