/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:33:46 by srudman           #+#    #+#             */
/*   Updated: 2023/03/09 15:17:55 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0' && n != 10)
	{
		if (str[i] < 32 || str[i] > 126)
		{
			n = 10;
		}
		i++;
	}
	if (n == 10)
		return (0);
	else
		return (1);
}

/*
int	main(void)
{
	return ft_str_is_printable("Sara");
}
*/
