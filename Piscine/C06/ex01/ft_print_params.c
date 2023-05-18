/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:07:37 by srudman           #+#    #+#             */
/*   Updated: 2023/03/15 18:39:41 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_params(int argc, char **argv)
{
	int	counter;

	counter = 1;
	while (counter < argc)
	{
		while (*argv[counter] != '\0')
		{
			write(1, argv[counter], 1);
			argv[counter]++;
		}
		write (1, "\n", 1);
		counter++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_print_params(argc, argv);
	else
		return (0);
}
