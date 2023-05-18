/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:52:32 by srudman           #+#    #+#             */
/*   Updated: 2023/03/04 14:51:56 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	rush(int x, int y)
{
	int changablex = x;
	int changabley = y;

	if (x == 1)
	{
		ft_putchar("o");
		ft_putchar("\n");
	}
	if (x > 1)
	{
		ft_putchar("o");
		while(changablex > 2)
		{
			ft_putchar("-");
			changablex--;
		}
		write(1, "o\n", 2);
		if (y > 1)
		{
			while(changabley > 2)
			{
				ft_putchar("|");
				changablex = x;
				while(changabley >= 2 && changablex > 2)
				{
					ft_putchar(" ");
					changablex--;
				}
				ft_putchar("|");
				ft_putchar("\n");
				changabley--;
			}
			ft_putchar("o");
			changablex = x;
			while(changablex > 2)
               		 {
                        	ft_putchar("-");
                        	changablex--;
               		 }
               		 ft_putchar("o");
			 ft_putchar("\n");
		}
	}
}


int 	main()
{
	int x;
	int y;

	rush(5,5);
	return (0);
}
