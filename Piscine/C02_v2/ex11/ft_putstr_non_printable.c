/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:33:02 by srudman           #+#    #+#             */
/*   Updated: 2023/03/09 16:49:03 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_printable(str[i]))
		{
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[((unsigned char)str[i]) / 16], 1);
			write(1, &"0123456789abcdef"[((unsigned char)str[i]) % 16], 1);
		}
		else
			write (1, &str[i], 1);
		i++;
	}
}

/*
int	main(void)
{

	char str[] = "Coucou\ntu vas bien ?";
	str[10] = -56;
	ft_putstr_non_printable(str);
	return (0);
}
*/
