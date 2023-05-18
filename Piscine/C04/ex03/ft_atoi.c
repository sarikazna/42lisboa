/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:56:07 by srudman           #+#    #+#             */
/*   Updated: 2023/03/12 17:45:03 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	final;
	int	minus;

	final = 0;
	minus = 0;
	while (*str && ((*str >= '\t' && *str <= '\r') || *str == ' '))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			minus++;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		final = final * 10 + (*str - '0');
		str++;
	}
	if (minus % 2 != 0)
		final = -final;
	return (final);
}

/*
#include <stdio.h>
int	main(void)
{
	ft_atoi(" ---+--+1234ab567");
	printf("%d", ft_atoi(" ---+--+1234ab567"));
	return (0);
}
*/
