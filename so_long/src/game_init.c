/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:10 by srudman           #+#    #+#             */
/*   Updated: 2024/03/01 12:46:48 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	deal_key()
{
	ft_putchar_fd('X', 1);
	//mlx_pixel_put(mlx_ptr, win_ptr,);
	return (0);
}

int	game_init(t_map_data *map)
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (free(mlx_ptr), -1);
	win_ptr = mlx_new_window(mlx_ptr, (map->columns * 16), (map->rows * 16), "Moonlight Sonata");
	if (!win_ptr)
		return (free(win_ptr), -1);
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	// mlx_key_hook(win_ptr, deal_key, (void *)0);
	// mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (1);
}
