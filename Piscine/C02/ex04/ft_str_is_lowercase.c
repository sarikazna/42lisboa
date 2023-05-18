/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:14:19 by srudman           #+#    #+#             */
/*   Updated: 2023/03/07 17:22:02 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	stop;

	i = 0;
	stop = 0;
	while (str[i] != '\0' && stop != 10)
	{
		if (!(str[i] > 96 && str[i] < 123))
		{
			stop = 10;
		}
		i++;
	}
	if (stop == 10)
		return (0);
	else
		return (1);
}

/*
int	main(void)
{
	return ft_str_is_lowercase("sara");
}
*/
