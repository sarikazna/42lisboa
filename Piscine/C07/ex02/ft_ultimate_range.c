/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:03:20 by srudman           #+#    #+#             */
/*   Updated: 2023/03/18 18:21:25 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc(sizeof (int) * (max - min));
	if (*range == NULL)
	{
		return (-1);
	}
	i = min;
	j = 0;
	while (i < max)
	{
		(*range)[j] = i;
		i++;
		j++;
	}
	return (max - min);
}

/*
#include <stdio.h>
int     main(void)
{
	int	min = 5;
	int	max = 10;
	int	*tab;

	printf("%d", ft_ultimate_range(&tab, min, max));
}
*/
