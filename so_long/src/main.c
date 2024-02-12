/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:53:58 by srudman           #+#    #+#             */
/*   Updated: 2024/02/12 18:49:50 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_map_check()
{
	
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !*argv[1])
	{
		perror("Error, exactly two arguments needed. Try: ./so_long maps/valid_maps/<name of map>\n");
		return (-1);
	}
	if (!ft_map_check)

	
	return (0);
}

/*

int	deal_key()
{
	ft_putchar_fd('X', 1);
	mlx_pixel_put(mlx_ptr, win_ptr,);
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 500, "Moonlight Sonata");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	
	if (argc != 2 || !*argv[1])
	{
		perror("Error, exactly two arguments needed. Try: ./so_long maps/valid_maps/<name of map>");
		return (-1);
	}
	
	return (0);
}
*/