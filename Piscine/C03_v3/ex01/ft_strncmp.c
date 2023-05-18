/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:45:28 by srudman           #+#    #+#             */
/*   Updated: 2023/03/11 20:14:56 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] > s2[i])
			return (1);
		else
			return (-1);
	}
	if (i == n)
		return (0);
	else if (s1[i] > s2[i])
		return (1);
	else if (s1[i] < s2[i])
		return (-1);
	else
		return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "SSSara";
	char	s2[] = "SSSRudman";
	unsigned int	n = 3;
	ft_strncmp(s1, s2, n);
	printf("%d", ft_strncmp(s1, s2, n));
}
*/
