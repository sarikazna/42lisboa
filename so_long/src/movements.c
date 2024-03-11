/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:39:27 by srudman           #+#    #+#             */
/*   Updated: 2024/03/11 15:58:50 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// int	move_is_valid(t_map_data *map, int x, int y)

void	move_up(t_map_data *map)
{
	// if (move_is_valid(map, map->player_posX, (map->player_posY - 1)))
		write(1, "OK\n", 3);
	printf("Position of player X: %i and Y: %i", map->player_posX, (map->player_posY - 1));
}

void	move_down(t_map_data *map)
{
	//if (move_is_valid(map, map->player_posX, (map->player_posY + 1)))
		write(1, "OK\n", 3);
	printf("Position of player X: %i and Y: %i", map->player_posX, map->player_posY + 1);
}

void	move_left(t_map_data *map)
{
	//if (move_is_valid(map, (map->player_posX - 1), map->player_posY))
		write(1, "OK\n", 3);
	printf("Position of player X: %i and Y: %i", (map->player_posX - 1), map->player_posY);
}

void	move_right(t_map_data *map)
{
	//if (move_is_valid(map, (map->player_posX + 1), map->player_posY))
		write(1, "OK\n", 3);
	printf("Position of player X: %i and Y: %i", (map->player_posX + 1), map->player_posY);
}
