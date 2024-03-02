/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:10 by srudman           #+#    #+#             */
/*   Updated: 2024/03/02 17:16:29 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// int	deal_key()
// {
// 	ft_putchar_fd('X', 1);
// 	//mlx_pixel_put(mlx_ptr, win_ptr,);
// 	return (0);
// }


// MEMORY LEAK
int on_destroy(t_map_data *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_map_data *map)
{
	(void)map;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int	game_init(t_map_data *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		return (free(map->mlx_ptr), -1);
	map->win_ptr = mlx_new_window(map->mlx_ptr, (map->columns * 128), (map->rows * 128), "Moonlight Sonata");
	if (!map->win_ptr)
		return (free(map->win_ptr), -1);
	// mlx_put_image_to_window(map->win_ptr, map->win_ptr, "", int x, int y);
	// mlx_pixel_put(map->mlx_ptr, map->win_ptr, 250, 250, 0xFFFFFF);
	// mlx_key_hook(win_ptr, deal_key, (void *)0);
	// Register key release hook
	// The KeyRelease and DestroyNotify constants are native X11 events, and can be imported through the X11 headers.
	mlx_hook(map->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &map);
	// Register destroy hook
	mlx_hook(map->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &map);
	mlx_loop(map->mlx_ptr);
	return (1);
}
