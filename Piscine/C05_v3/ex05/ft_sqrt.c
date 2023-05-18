/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:58:59 by srudman           #+#    #+#             */
/*   Updated: 2023/03/15 12:43:29 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	max_iterations;

	max_iterations = 100;
	if (nb == 0 || nb == 1)
		return (nb);
	else if (nb < 0)
		return (0);
	else
	{
		i = 2;
		while (i < nb && max_iterations)
		{
			if (i * i == nb)
				return (i);
			i = (i + (nb / i)) / 2;
			max_iterations--;
		}
	}
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(-4));
	return (0);
}
*/
