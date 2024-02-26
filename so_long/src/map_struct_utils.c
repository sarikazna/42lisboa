/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:59:27 by srudman           #+#    #+#             */
/*   Updated: 2024/02/26 20:16:51 by srudman          ###   ########.fr       */
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
		{
			free(map->matrix[i]);
			i++;
		}
		free(map->matrix);
	}
	if (map->wall != NULL)
		free(map->wall);
	if (map->exit != NULL)
		free(map->exit);
	if (map->items != NULL)
		free(map->items);
	if (map->player != NULL)
		free(map->player);
	free(map);
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
	(*map)->wall = NULL;
	(*map)->exit = NULL;
	(*map)->items = NULL;
	(*map)->player = NULL;
	(*map)->rows = 0;
	(*map)->no_exits = 0;
	(*map)->no_players_check = 0;
	(*map)->columns = 0;
	(*map)->height = 0;
	(*map)->width = 0;
	(*map)->score = 0;
	(*map)->curr_score = 0;
	(*map)->gameover = 1;
	(*map)->steps = 0;
	return (1);
}
