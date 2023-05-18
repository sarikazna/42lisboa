/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:32:14 by srudman           #+#    #+#             */
/*   Updated: 2023/03/11 21:43:08 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			k = i;
			while (to_find[j] != '\0' && str[k] == to_find[j])
			{
				j++;
				k++;
			}
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
        char str[] = "Oh babeey babeey, how was I supposed to know";
        char to_find[] = "was I";
        char *result = ft_strstr(str, to_find);

	printf("%s\n", strstr(str, to_find));
        if (ft_strstr(str, to_find) == 0)
                printf("Substring not found\n");
        else
                printf("Substring found at position %ld\n", result - str);
        return (0);
}
*/
