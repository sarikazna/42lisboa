/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:13:54 by srudman           #+#    #+#             */
/*   Updated: 2023/03/23 14:59:08 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_in_charset(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (charset[j] == str[i])
			{
				counter--;
				break ;
			}
			j++;
		}
		i++;
		counter++;
	}
	return (counter);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	char	*tmp;
	int	i;
	int	j;

	split = (char **)malloc(sizeof (char *) * (ft_strlen(str, charset) + 1));
	if (split == NULL)
		return (NULL);
	j = 0;
	while (*str)
	{
		while (ft_in_charset(*str, charset))
			str++;
		i = 0;
		while (!ft_in_charset(str[i], charset) && str[i])
			i++;
		if ((tmp = (char *)malloc(sizeof (char) * (i + 1))) == NULL)
			return (NULL);
		i = 0;
		while (!ft_in_charset(*str, charset) && *str)
		{
			tmp[i] = *str;
			i++;
			str++;
		}
		tmp[i] = '\0';
		if (i != 0)
		{
			split[j] = tmp;
			j++;
		}
	}
	split[j] = 0;
	return (split);
}

#include <stdio.h>
int	main(void)
{
	char	*str = "I_have a goat, cows. No";
	char	*charset = " ,.  _";
	int	i = 0;
	char	**result = (ft_split(str, charset));

	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
}
