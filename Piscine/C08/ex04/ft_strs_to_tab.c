/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:02:28 by srudman           #+#    #+#             */
/*   Updated: 2023/03/21 19:26:04 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	copy = (char *)malloc(ft_strlen(src) + 1);
	if (copy == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < ft_strlen(src))
		{
			copy[i] = src[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			counter;
	t_stock_str	*tab;
	char		*tmp;

	tab = (t_stock_str *)malloc(sizeof (t_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	counter = 0;
	while (counter < ac)
	{
		tmp = av[counter];
		tab[counter].size = ft_strlen(tmp);
		tab[counter].str = ft_strdup(tmp);
		tab[counter].copy = ft_strdup(tmp);
		if (ft_strdup(tmp) == NULL || ft_strdup(tmp) == NULL)
			return (NULL);
		counter++;
	}
	tab[counter].str = 0;
	return (tab);
}

/*
#include <stdio.h>
#include <unistd.h>
int	main(int ac, char **av)
{
	t_stock_str	*a;

	if (ac > 1)
	{
		a = ft_strs_to_tab(ac, av);
		while (a->str)
		{
			printf("String: %s\n", a->str);
			printf("Copy: %s\n", a->copy);
			printf("Size: %d\n", a->size);
			write(1, "\n", 1);
			a++;
		}
	}
	return (0);
}
*/
