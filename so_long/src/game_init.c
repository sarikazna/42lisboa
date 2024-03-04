/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:59:10 by srudman           #+#    #+#             */
/*   Updated: 2024/03/04 20:32:27 by srudman          ###   ########.fr       */
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
				put_image(map, map->img[0], x * 128, y * 128);
			if (map->matrix[y][x] == '1')
				put_image(map, map->img[1], x * 128, y * 128);
			if (map->matrix[y][x] == 'P')
				put_image(map, map->img[2], x * 128, y * 128);
			if (map->matrix[y][x] == 'C')
				put_image(map, map->img[3], x * 128, y * 128);
			if (map->matrix[y][x] == 'E')
				put_image(map, map->img[4], x * 128, y * 128);
			x++;
		}
		y++;
	}
}

// Maybe add an error code
static void	img_init(t_map_data *map)
{
	int	size;

	size = 128;
	map->img = malloc(6 * sizeof(void *));
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
	map->img[5] = NULL;
}

int	game_init(t_map_data *map)
{
	int	i;

	i = 0;
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
	{
		mlx_destroy_display(map->mlx_ptr);
		return (-1);
	}
	map->win_ptr = mlx_new_window(map->mlx_ptr, (map->columns * 128), 
			(map->rows * 128), "so_long");
	if (!map->win_ptr)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		mlx_destroy_display(map->mlx_ptr);
		return (-1);
	}
	img_init(map);
	img_render(map);
	return (1);
}
