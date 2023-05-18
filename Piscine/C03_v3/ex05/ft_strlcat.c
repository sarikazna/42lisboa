/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:32:16 by srudman           #+#    #+#             */
/*   Updated: 2023/03/11 18:11:30 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < size)
	{
		i++;
	}
	if (size > i++)
	{
		while (j + i < size - 1 && src[j] != '\0')
		{
			dest[i + j] = src[j];
			j++;
		}
	}
	if (i < size)
		dest[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	return (i + j);
}

/*
#include <stdio.h>
int	main(void)
{
	char src[] = "Source string.";
	char dest[] = "Destination string.";
	unsigned int size;

	size = 15;

	printf("BEFORE\n\tsrc: %s\n\tdes: %s\n", src, dest, size);

    size = ft_strlcat(dest, src, size);

	printf("AFTER\n\tsrc: %s\n\tdes: %s\n", src, dest, size);
	return (0);
}
*/
