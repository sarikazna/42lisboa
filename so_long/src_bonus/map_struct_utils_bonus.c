/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:59:27 by srudman           #+#    #+#             */
/*   Updated: 2024/03/17 16:01:02 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map_struct(t_map_data *map)
{
	int	i;

	if (map == NULL)
		return ;
	if (map->matrix != NULL)
	{
		i = 0;
		while (i < map->rows)
			free(map->matrix[i++]);
		free(map->matrix);
	}
	if (map->img != NULL)
	{
		i = 0;
		while (i < 8 && map->img[i] != NULL)
			mlx_destroy_image(map->mlx_ptr, map->img[i++]);
		free(map->img);
	}
}

int	ft_map_init(t_map_data **map)
{
	*map = malloc(sizeof(t_map_data));
	if (*map == NULL)
	{
		perror("Error\nMemory allocation of map failed.\n");
		return (-1);
	}
	(*map)->matrix = NULL;
	(*map)->img = NULL;
	(*map)->mlx_ptr = NULL;
	(*map)->rows = 0;
	(*map)->no_exits = 0;
	(*map)->no_players_check = 0;
	(*map)->columns = 0;
	(*map)->height = 0;
	(*map)->width = 0;
	(*map)->score = 0;
	(*map)->curr_score = 0;
	(*map)->steps = 0;
	(*map)->no_enemies = 0;
	(*map)->game_running = 1;
	return (1);
}
