/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:20:26 by srudman           #+#    #+#             */
/*   Updated: 2023/11/25 19:39:14 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int long	ft_atol(const char *nptr)
{
	int	minus;
	int long	result;

	minus = 1;
	result = 0;
	while (*nptr != '\0')
	{
		while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
			nptr++;
		if (*nptr == '+' || *nptr == '-')
		{
			if (*nptr == '-')
				minus = -1;
			nptr++;
		}
		while (*nptr >= '0' && *nptr <= '9')
		{
			result = result * 10 + (*nptr - '0');
			nptr++;
		}
		break ;
	}
	return (result * minus);
}


#include <stdio.h>
int main(void)
{
    printf("%ld\n", ft_atol(" -346k446"));
    return (0);
}
