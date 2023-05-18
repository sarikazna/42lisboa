/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:54:35 by srudman           #+#    #+#             */
/*   Updated: 2023/03/04 16:34:03 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	char	a;

	write(1, &a, 1);
}

void	rush00(int x, int y) {
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (i < x)
		{
			if (i == 0 || i == x - 1)
			{
				ft_putchar((j == 0 || j == y - 1) ? 'o' : '|');
			}
			else if (i > 0 && i < x - 1)
			{
				ft_putchar((j == 0 || j == y - 1) ? '-' : ' ');
			}
			if (i == x - 1)
			{
				ft_putchar('\n');
			}
			i++;
		}
		i = 0;
		j++;
	}
}

int	main(void)
{
	int	x;
	int	y;

	rush(5, 5);
	return (0);
}
