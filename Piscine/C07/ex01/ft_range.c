/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:49:05 by srudman           #+#    #+#             */
/*   Updated: 2023/03/18 15:47:48 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	int	j;

	if (min >= max)
	{
		range = NULL;
		return (range);
	}
	range = (int *)malloc(sizeof (int) * (max - min));
	if (range == NULL)
		return (NULL);
	i = min;
	j = 0;
	while (i < max)
	{
		range[j] = i;
		i++;
		j++;
	}
	return (range);
}

/*
#include <stdio.h>
int     main(void)
{
        int     *range;
        int     min;
        int     max;
        int     i;

        min = 0;
        max = 10;
        range = ft_range(min, max);
	i = 0;
        while (i < max - min)
        {
                printf("%d ", range[i]);
		i++;
        }
        return (0);
}
*/
