/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:39:01 by srudman           #+#    #+#             */
/*   Updated: 2023/03/15 12:41:59 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_prime_recursive(long i, int nb)
{
	if (i * i > nb)
		return (1);
	else if (nb % i == 0)
		return (0);
	return (ft_prime_recursive(1 + i, nb));
}

int	ft_is_prime(int nb)
{
	if (nb <= 0 || nb == 1)
		return (0);
	else if (nb <= 3)
		return (1);
	else if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	else
		return (ft_prime_recursive(2, nb));
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_is_prime(7));
	printf("%d\n", ft_is_prime(0));
	printf("%d\n", ft_is_prime(15));
	printf("%d\n", ft_is_prime(8));
	printf("%d\n", ft_is_prime(11));
}
*/
