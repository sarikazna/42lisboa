/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:30:51 by srudman           #+#    #+#             */
/*   Updated: 2023/03/19 17:45:34 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_base_valid(char *base)
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

int	ft_convert_to_decimal(char *nbr, char *base_from)
{
	int	i;
	int	nb;
	int	digit_index;
	int	minus;

	nb = 0;
	i = 0;
	minus = 1;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			minus = -minus;
		i++;
	}
	while (nbr[i])
	{
		digit_index = ft_find_char_index(base_from, nbr[i]);
		if (digit_index == -1)
			return (0);
		nb = nb * ft_str_length(base_from);
		nb = nb + digit_index;
		i++;
	}
	return (nb * minus);
}

int	ft_find_char_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_str_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	if (nbr[0] == '-' || nbr[0] == '+')
		i--;
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nb;

	if (!(ft_is_base_valid(base_from)) || !(ft_is_base_valid(base_to)))
		return ;
	nb = ft_convert_to_decimal(nbr, base_from);
}
