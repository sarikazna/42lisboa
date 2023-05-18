/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:34:49 by srudman           #+#    #+#             */
/*   Updated: 2023/03/16 14:13:39 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putchar(int counter, int argc, char **argv)
{
	while (counter < argc)
	{
		while (*argv[counter] != '\0')
		{
			write(1, argv[counter], 1);
			argv[counter]++;
		}
		*argv[counter] = '\0';
		write (1, "\n", 1);
		counter++;
	}
}

void	ft_sort_params(int argc, char **argv)
{
	int		counter;
	int		i;
	char	*tmp;

	i = 0;
	counter = 1;
	while (counter < argc - 1)
	{
		if ((ft_strcmp(argv[counter], argv[counter + 1])) > 0)
		{
			tmp = argv[counter];
			argv[counter] = argv[counter + 1];
			argv[counter + 1] = tmp;
			counter = 1;
		}
		else
			counter++;
	}
	ft_putchar(1, argc, argv);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_sort_params(argc, argv);
	else
		return (0);
}
