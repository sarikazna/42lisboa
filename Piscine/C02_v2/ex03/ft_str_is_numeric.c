/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:44:51 by srudman           #+#    #+#             */
/*   Updated: 2023/03/07 17:11:05 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0' && n != 10)
	{
		if (!(str[i] > 47 && str[i] < 58))
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
    char numeric[] = {'1', '2', '3', '4', '5', '\0'};
	char *p_num;
	p_num = numeric;
	ft_str_is_numeric(p_num);
	return ft_str_is_numeric(p_num);
}
*/
