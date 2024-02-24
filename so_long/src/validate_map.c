/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:10:43 by srudman           #+#    #+#             */
/*   Updated: 2024/02/24 17:50:37 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_map_is_rectangular(t_map_data *map)
{
	int	i;

	map->columns = ft_strlen(map->matrix[0]) - 1;
	i = 0;
	while (i < (map->rows - 1))
	{
		if (ft_strlen(map->matrix[i++]) != ft_strlen(map->matrix[0]))
		{
			perror("Error\nEach line in the map should be the same length.\n");
			return (0);
		}
	}
	if ((ft_strlen(map->matrix[i]) + 1) != ft_strlen(map->matrix[0]))
	{
		perror("Error\nEach line in the map should be the same length.\n");
		return (0);
	}
	return (1);
}

/*
Fucntion ft_validate_walls validates whether or not the game matrix is surrounded
by walls (as required by the project instruction). Walls are marked with the number
'1'.
*/
int	ft_validate_walls(t_map_data *map)
{
	int	i;

	i = 0;
	while (i < map->columns)
	{
		if (map->matrix[0][i] != '1' || map->matrix[map->rows - 1][i] != '1')
		{
			perror("Error\nWalls are missing on the edges.\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->matrix[i][0] != '1' || map->matrix[i][map->columns - 1] != '1')
		{
			perror("Error\nWalls are missing on the edges.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_validate_count(t_map_data *map)
{
	if (map->score == 0)
	{
		perror("Error\nThe game map should contain collectables.\n");
		return (0);
	}
	if (map->no_exits == 0)
	{
		perror("Error\nThe game map should contain an exit.\n");
		return (0);
	}
	if (map->no_players_check != 1)
	{
		perror("Error\nThe game map should contain exactly one player.\n");
		return (0);
	}
	return (1);
}

/*
Function ft_count_elements counts the number of elements in the game map.
It counts the number of columns (rows were counter in another function),
the number of C (collectables), E (exits), P (players) and saves the data
in the struct called 'map'.
*/
int	ft_count_elements(t_map_data *map)
{
	int	i;
	int	j;
	
	j = 0;
	while (j < map->rows)
	{
		i = 0;
		while (i < map->columns)
		{
			if (map->matrix[j][i] == 'C')
				map->score++;
			if (map->matrix[j][i] == 'E')
				map->no_exits++;
			if (map->matrix[j][i] == 'P')
				map->no_players_check++;
			i++;
		}
		j++;
	}
	return (ft_validate_count(map));
}

int	ft_validate_map(t_map_data *map)
{
	if (!ft_map_is_rectangular(map) || !ft_validate_walls(map) 
		|| !ft_count_elements(map) || !ft_allowed_character(map))
		return (0);
	if (!ft_validate_path (map))
		return (0);
	return (1);
}
