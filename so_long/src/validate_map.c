/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:10:43 by srudman           #+#    #+#             */
/*   Updated: 2024/02/22 14:43:02 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*
Fucntion ft_validate_walls validates whether or not the game matrix is surrounded
by walls (as required by the project instruction). Walls are marked with the number
'1'.
*/
int	ft_validate_walls(t_map_data *map)
{
	int	i;

	i = 0;
	printf("Columns: %i \n", map->columns);
	while (i < map->columns)
	{
		if (map->matrix[0][i] != '1' || map->matrix[map->rows - 1][i] != '1')
		{
			perror("Error, walls are missing on the edges.\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->matrix[i][0] != '1' || map->matrix[i][map->columns - 1] != '1')
		{
			perror("Error, walls are missing on the edges.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/*
Function ft_count_elements counts the number of elements in the game map.
It counts the number of columns (rows were counter in another function),
the number of C (collectables), E (exits), P (players) and saves the data
in the struct called 'map'.
*/
void	ft_count_elements(t_map_data *map)
{
	int	i;
	int	j;
	
	while (map->matrix[0][map->columns++] != '\n' 
		&& map->matrix[0][map->columns] != '\0');
	j = 0;
	map->columns--;
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
}

/*
TO DO: report error if P, E, C are not great
TO DO: validate that there's no other letter than PEC10;
TO DO: empty lines cause seg fault
*/
// input position of the player

int	ft_validate_map(t_map_data *map)
{
	ft_count_elements(map);
	if (!ft_validate_walls(map))
		return (0);
	//ft_map_is_rectangular(map); // probably if statement and error
	// validate path
	return (1);
}