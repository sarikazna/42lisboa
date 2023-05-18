/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:47:55 by srudman           #+#    #+#             */
/*   Updated: 2023/03/07 12:54:49 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[size - 1 - i];
		tab[size - 1 - i] = tab[i];
		tab[i] = tmp;
		i++;
	}
}

/*
#include <stdio.h>
int main(void)
{
    int tab[6] = {1, 2, 3, 4, 5, 6};
    int i;

    ft_rev_int_tab(tab, 6);

    while (i < 6)
    {
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");

    return (0);
}
*/
