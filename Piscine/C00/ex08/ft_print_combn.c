/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 20:25:16 by srudman           #+#    #+#             */
/*   Updated: 2023/03/05 16:08:18 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_recursion(int n, int remaining);

void	ft_print_combn(int n)
{
	int	remaining;

	remaining = n;
	if (remaining > 0)
	{
		ft_recursion(n, remaining);
	}
}

void	ft_recursion(int n, int remaining)
{
	if (remaining == 0)
	{
	}
	else
	{
	}
}

void	write(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	ft_print_combn(int n);
	return (0);
}
