/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:39:17 by srudman           #+#    #+#             */
/*   Updated: 2023/03/13 15:58:21 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_fibonacci(int index)
{
	if (index >= 2)
		return ((ft_fibonacci(index - 1)) + (ft_fibonacci(index - 2)));
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return (-1);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_fibonacci(7));
	return (0);
}
*/
