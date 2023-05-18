/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:07:11 by srudman           #+#    #+#             */
/*   Updated: 2023/03/18 13:22:50 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(long i, int nb)
{
	if (i * i > nb)
		return (1);
	else if (nb % i == 0)
		return (0);
	return (ft_is_prime(1 + i, nb));
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	else if (nb == 2147483647)
		return (nb);
	else if (ft_is_prime(2, nb))
		return (nb);
	else if (nb % 2 == 0)
		nb++;
	while (!ft_is_prime(2, nb))
		nb = nb + 2;
	return (nb);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_find_next_prime(7));
	printf("%d\n", ft_find_next_prime(0));
	printf("%d\n", ft_find_next_prime(15));
	printf("%d\n", ft_find_next_prime(8));
	printf("%d\n", ft_find_next_prime(11));
}
*/
