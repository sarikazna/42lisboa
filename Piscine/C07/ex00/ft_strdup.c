/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:13:26 by srudman           #+#    #+#             */
/*   Updated: 2023/03/19 15:18:41 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
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

/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_strdup("I love Zdravko Colic!"));
	free(ft_strdup("I love Zdravko Colic!"));
	return (0);
}
*/
