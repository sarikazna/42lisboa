/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:10 by srudman           #+#    #+#             */
/*   Updated: 2024/03/18 17:14:23 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_image(t_map_data *map, void *img, int x, int y)
{
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, img, x, y);
}

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
				put_image(map, map->img[0], x * 64, y * 64);
			if (map->matrix[y][x] == '1')
				put_image(map, map->img[1], x * 64, y * 64);
			if (map->matrix[y][x] == 'P')
				put_image(map, map->img[2], x * 64, y * 64);
			if (map->matrix[y][x] == 'C')
				put_image(map, map->img[3], x * 64, y * 64);
			if (map->matrix[y][x] == 'E')
				put_image(map, map->img[4], x * 64, y * 64);
			if (map->matrix[y][x] == 'X')
				put_image(map, map->img[6], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

// Maybe add an error code
static void	img_init(t_map_data *map)
{
	int	size;

	size = 64;
	map->img = malloc(8 * sizeof(void *));
	if (map->img == NULL)
		return ;
	map->img[0] = mlx_xpm_file_to_image
		(map->mlx_ptr, "img/path/path.xpm", &size, &size);
	map->img[1] = mlx_xpm_file_to_image
		(map->mlx_ptr, "img/wall/wall.xpm", &size, &size);
	map->img[2] = mlx_xpm_file_to_image
		(map->mlx_ptr, "img/player/player01.xpm", &size, &size);
	map->img[3] = mlx_xpm_file_to_image
		(map->mlx_ptr, "img/collect/collectable01.xpm", &size, &size);
	map->img[4] = mlx_xpm_file_to_image
		(map->mlx_ptr, "img/exit/exit.xpm", &size, &size);
	map->img[5] = mlx_xpm_file_to_image
		(map->mlx_ptr, "img/exit/p_over_e.xpm", &size, &size);
	map->img[6] = mlx_xpm_file_to_image
		(map->mlx_ptr, "img/enemy/enemy.xpm", &size, &size);
	map->img[7] = NULL;
}

int	game_init(t_map_data *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
	{
		mlx_destroy_display(map->mlx_ptr);
		return (0);
	}
	map->win_ptr = mlx_new_window(map->mlx_ptr, (map->columns * 64), 
			(map->rows * 64), "so_long_bonus");
	if (!map->win_ptr)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_display(map->mlx_ptr);
		return (0);
	}
	img_init(map);
	img_render(map);
	return (1);
}
