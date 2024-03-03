/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:10 by srudman           #+#    #+#             */
/*   Updated: 2024/03/03 18:35:21 by srudman          ###   ########.fr       */
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

void	img_render(t_map_data *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			if (map->matrix[y][x] == '0')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img[0], x * 128, y * 128);
			if (map->matrix[y][x] == '1')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img[1], x * 128, y * 128);
			if (map->matrix[y][x] == 'P')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img[2], x * 128, y * 128);
			if (map->matrix[y][x] == 'C')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img[3], x * 128, y * 128);
			if (map->matrix[y][x] == 'E')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img[4], x * 128, y * 128);
			x++;
		}
		y++;
	}
}

static void	img_init(t_map_data *map)
{
	int	size;

	size = 128;
	map->img = malloc(6 * sizeof(void *));
	if (map->img == NULL)
		return ;
	map->img[0] = mlx_xpm_file_to_image(map->mlx_ptr, "img/path/path.xpm", &size, &size);
	map->img[1] = mlx_xpm_file_to_image(map->mlx_ptr, "img/wall/wall.xpm", &size, &size);
	map->img[2] = mlx_xpm_file_to_image(map->mlx_ptr, "img/player/player01.xpm", &size, &size);
	map->img[3] = mlx_xpm_file_to_image(map->mlx_ptr, "img/collectable/collectable01.xpm", &size, &size);
	map->img[4] = mlx_xpm_file_to_image(map->mlx_ptr, "img/exit/exit.xpm", &size, &size);
	map->img[5] = NULL;
}


int	game_init(t_map_data *map)
{
	int	i;

	i = 0;
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		return (-1);
	map->win_ptr = mlx_new_window(map->mlx_ptr, (map->columns * 128), (map->rows * 128), "so_long");
	if (!map->win_ptr)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_display(map->mlx_ptr);
		return (-1);
	}
	img_init(map);
	img_render(map);
	mlx_loop(map->mlx_ptr);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	// draw_game(map); LEFT HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEeee
	// mlx_put_image_to_window(map->win_ptr, map->win_ptr, "", int x, int y);
	// mlx_pixel_put(map->mlx_ptr, map->win_ptr, 250, 250, 0xFFFFFF);
	// mlx_key_hook(win_ptr, deal_key, (void *)0);
	// Register key release hook
	// The KeyRelease and DestroyNotify constants are native X11 events, and can be imported through the X11 headers.
	// mlx_hook(map->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &map);
	// Register destroy hook
	// mlx_hook(map->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &map);
	// mlx_loop(map->mlx_ptr);
	return (1);
}
