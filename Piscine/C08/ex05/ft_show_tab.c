/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:01:13 by srudman           #+#    #+#             */
/*   Updated: 2023/03/21 19:45:44 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"
#include <stdlib.h>

void	ft_putnbr(int nb);

/*
int     ft_strlen(char *str)
{
        int     n;

        n = 0;
        while (str[n] != '\0')
        {
                n++;
        }
        return (n);
}

char    *ft_strdup(char *src)
{
        char    *copy;
        int             i;

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

struct  s_stock_str     *ft_strs_to_tab(int ac, char **av)
{
        int                     counter;
        t_stock_str     *tab;
        char            *tmp;

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
*/

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		write(1, par[i].str, par[i].size);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, par[i].size);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}	
}

/*
#include <stdio.h>
#include <unistd.h>
int     main(int ac, char **av)
{
        t_stock_str     *a;

        if (ac > 1)
        {
                a = ft_strs_to_tab(ac, av);
		ft_show_tab(a);
        }
        return (0);
}
*/
