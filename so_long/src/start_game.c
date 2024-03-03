/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:00:25 by srudman           #+#    #+#             */
/*   Updated: 2024/03/03 19:01:23 by srudman          ###   ########.fr       */
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
// int on_destroy(t_map_data *map)
// {
// 	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
// 	mlx_destroy_display(map->mlx_ptr);
// 	free(map->mlx_ptr);
// 	exit(0);
// 	return (0);
// }

// int on_keypress(int keysym, t_map_data *map)
// {
// 	(void)map;
// 	printf("Pressed key: %d\\n", keysym);
// 	return (0);
// }

/*
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	Register key release hook
	The KeyRelease and DestroyNotify constants are native X11 events, and can be imported through the X11 headers.
	mlx_hook(map->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &map);
	Register destroy hook
	mlx_hook(map->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &map);
	mlx_loop(map->mlx_ptr);
*/