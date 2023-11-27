/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:12:43 by srudman           #+#    #+#             */
/*   Updated: 2023/11/27 15:55:02 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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


// #include <stdio.h>
// int main(void)
// {
// 	// Test for syntax_error function.
// 	char *nptr = "3";
// 	printf("%d", syntax_error(nptr));
// 	return (0);	
// }
