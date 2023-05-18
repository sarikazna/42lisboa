/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:55:05 by srudman           #+#    #+#             */
/*   Updated: 2023/03/23 15:13:14 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	in_charset(char str, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == str)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (in_charset(str[i], charset))
			counter--;
		i++;
		counter++;
	}
	return (counter);
}


char	**ft_split(char *str, char *charset)
{
	int	i;
	int	j;
	char	**split;
	char	*tmp;

	tmp = NULL;
	split = (char **)malloc(sizeof (char *) * (ft_strlen(str, charset) + 1));
	if (split == NULL)
		return (NULL);
	j = 0;
	while (*str)
	{
		if (in_charset(*str, charset))
			str++;
		else if (!in_charset(*str, charset))
		{
			i = 0;
			while (!in_charset(str[i], charset) && str[i])
				i++;
			tmp = (char *)malloc(sizeof (char) * (i + 1));
			if (tmp == NULL)
				return (NULL);
			i = 0;
			while (!in_charset(str[i], charset) && str[i])
			{
				tmp[i] = str[i];
				i++;
			}
			tmp[i] = '\0';
			split[j] = tmp;
			j++;
			str = str + i;
		}
	}
	split[j] = 0;
	return (split);
}

/*
int	main(void)
{
	char	*str = "Very,nice how# much. ";
	char	*charset = " ,#!. ";
	int	i = 0;
	char	**result = ft_split(str, charset);
	while (result[i] != 0)
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}
*/
