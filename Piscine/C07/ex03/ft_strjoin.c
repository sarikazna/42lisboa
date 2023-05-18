/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:38:14 by srudman           #+#    #+#             */
/*   Updated: 2023/03/19 13:45:30 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*s;

	i = 0;
	while (sep[i])
		i++;
	i = i * (size - 1);
	j = 0;
	while (j < size)
	{
		s = strs[j];
		k = 0;
		while (s[k])
		{
			k++;
			i++;
		}
		j++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		*dest = src[i];
		dest++;
		i++;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*concat;
	int		i;
	char	*tmp;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	concat = (char *)malloc((ft_strlen(size, strs, sep) + 1) * sizeof (char));
	if (concat == NULL)
		return (0);
	tmp = concat;
	tmp = ft_strcpy(tmp, strs[0]);
	i = 1;
	while (i < size)
	{
		tmp = ft_strcpy(tmp, sep);
		tmp = ft_strcpy(tmp, strs[i]);
		i++;
	}
	*tmp = '\0';
	return (concat);
}

/*
#include <stdio.h>
int main(void)
{
    char *strs1[] = {"hello", "world", "!"};
    char *res1 = ft_strjoin(3, strs1, " ");
    printf("%s\n", res1);
    free(res1);

    return 0;
}
*/
