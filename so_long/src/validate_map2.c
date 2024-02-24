/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:50:12 by srudman           #+#    #+#             */
/*   Updated: 2024/02/24 19:24:32 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* 
Still needs work
*/
int	ft_flood_map_to_exit(int x, int y, char **matrix)
{
	if (matrix[y][x] == 'E')
		return (1); // exit was successfully found
	matrix[y][x] = 'V'; // 'V' represents visited
	if (matrix[y][x] == '0' || matrix[y][x] == 'C')
	{
		if (matrix[y + 1][x] == '0' || matrix[y + 1][x] == 'C' || matrix[y + 1][x] == 'E')
			ft_flood_map_to_exit(y + 1, x, matrix);
		if (matrix[y - 1][x] == '0' || matrix[y - 1][x] == 'C' || matrix[y - 1][x] == 'E')
			ft_flood_map_to_exit(y - 1, x, matrix);
		if (matrix[y][x + 1] == '0' || matrix[y][x + 1] == 'C' || matrix[y][x + 1] == 'E')
			ft_flood_map_to_exit(y, x + 1, matrix);
		if (matrix[y][x - 1] == '0' || matrix[y][x - 1] == 'C' || matrix[y][x - 1] == 'E')
			ft_flood_map_to_exit(y, x - 1, matrix);
	}
	return (0);
}

void	ft_assign_position(t_map_data *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->rows)
	{
		i = 0;
		while (i < map->columns)
		{
			if (map->matrix[j][i] == 'P')
			{
				map->player_posY = j;
				map->player_posX = i;
			}
			i++;
		}
		j++;
	}
}

/*
ft_validate_part contains a flood fill algorithm. The traditional flood-fill 
algorithm takes three parameters: a start node, a target color, and a replacement 
color. The algorithm looks for all nodes in the array that are connected to the 
start node by a path of the target color and changes them to the replacement color.
*/

int ft_validate_path(t_map_data *map)
{
	ft_assign_position(map);
	if (!ft_flood_map_to_exit(map->player_posX, map->player_posY, map->matrix))
	{
		perror("Error\nExit cannot be reached.\n");
		return (0);	
	}
	return (1);
}

/*
We need to make sure no invalid characters are present int our maps. 
The only allowed characters are 01CEP and \n.
*/
int ft_allowed_character(t_map_data *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->rows)
	{
		i = 0;
		while (i < map->columns)
		{
			if (map->matrix[j][i] != 'C' && map->matrix[j][i] != 'E' 
				&& map->matrix[j][i] != 'P' && map->matrix[j][i] != '1' 
				&& map->matrix[j][i] != '0' && map->matrix[j][i] != '\n')
			{
				perror("Error\nMap contains invalid characters.\n");
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}