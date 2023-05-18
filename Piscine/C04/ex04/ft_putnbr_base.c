/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:37:46 by srudman           #+#    #+#             */
/*   Updated: 2023/03/12 18:28:51 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_length_of_regex(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_regex_is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || base[i] <= 32 || base[i] >= 127)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	r_length;

	r_length = ft_length_of_regex(base);
	if (!(ft_regex_is_valid(base)))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= r_length)
		ft_putnbr_base(nbr / r_length, base);
	write (1, &base[nbr % r_length], 1);
}

/*
int	main(void)
{
	ft_putnbr_base(140, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(140, "01");
	write (1, "\n", 1);
	ft_putnbr_base(140, "0123456789ABCDEF");
	write (1, "\n", 1);
	ft_putnbr_base(140, "poneyvif");
	return (0);
}
*/
