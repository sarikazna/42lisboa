/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:09:48 by srudman           #+#    #+#             */
/*   Updated: 2023/03/13 12:48:07 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power != 0)
	{
		i = i * nb;
		power--;
	}
	return (i);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_iterative_power(4, 4));
	return (0);
}
*/
