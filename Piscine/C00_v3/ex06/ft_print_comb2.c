/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:27:30 by srudman           #+#    #+#             */
/*   Updated: 2023/03/04 20:22:27 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_digit_display(int a, int b);

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 99)
	{
		while (b <= 99 && a < b)
		{
			ft_digit_display (a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
}

void	ft_digit_display(int a, int b)
{
	char	i;
	char	j;
	char	k;
	char	l;

	i = a / 10 + '0';
	j = a % 10 + '0';
	k = b / 10 + '0';
	l = b % 10 + '0';
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, " ", 1);
	write(1, &k, 1);
	write(1, &l, 1);
	if (!(i == '9' && j == '8' && k == '9' && l == '9'))
	{
		write(1, ", ", 2);
	}
}
