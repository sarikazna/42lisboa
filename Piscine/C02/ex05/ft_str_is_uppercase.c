/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:22:56 by srudman           #+#    #+#             */
/*   Updated: 2023/03/07 17:32:22 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	stop;

	i = 0;
	stop = 0;
	while (str[i] != '\0' && stop != 10)
	{
		if (!(str[i] > 64 && str[i] < 91))
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
	return ft_str_is_uppercase("SARA");
}
*/
