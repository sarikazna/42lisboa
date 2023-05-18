/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:48:49 by srudman           #+#    #+#             */
/*   Updated: 2023/03/14 17:17:35 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (nb == 1 || power < 1 || power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, (power - 1)));
}

/*
#include <stdio.h>
int	main(void)
{       
	printf("%d", ft_recursive_power(4, 4));
	return (0);
}
*/
