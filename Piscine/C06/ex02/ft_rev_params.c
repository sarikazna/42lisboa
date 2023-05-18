/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:56:58 by srudman           #+#    #+#             */
/*   Updated: 2023/03/15 19:32:55 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_params(int argc, char **argv)
{
	int	counter;

	counter = argc - 1;
	while (1 <= counter)
	{
		while (*argv[counter] != '\0')
		{
			write(1, argv[counter], 1);
			argv[counter]++;
		}
		write (1, "\n", 1);
		counter--;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_rev_params(argc, argv);
	else
		return (0);
}
