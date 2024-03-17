/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:39:27 by srudman           #+#    #+#             */
/*   Updated: 2024/03/17 16:44:18 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_on_exit(t_map_data *map, int new_x, int new_y)
{
	if (map->curr_score == map->score)
	{
		write(1, "Congrats! You won!\n", 19);
		exit_game(&map);
	}
	else
	{
		map->matrix[map->player_y][map->player_x] = '0';
		map->matrix[new_y][new_x] = 'W';
		if (map->matrix[map->player_y][map->player_x] == 'W')
			put_image(map, map->img[4], map->player_x * 64, map->player_y * 64);
		else 
			put_image(map, map->img[0], map->player_x * 64, map->player_y * 64);
		put_image(map, map->img[5], new_x * 64, 
			(new_y) * 64);
	}
}


/* move_up, move_down, move_left, move_right handle player movements in the
game maze. In case the next field contains a C (collectable) or 0 (path)
we update the image for the current and next field. We also update the image.
We don't update the image of the entire window, only of two slots. 
If player reaches exit and has collected all collectables, he wins the game.*/

void	move_up(t_map_data *map)
{
	if (map->matrix[map->player_y - 1][map->player_x] == 'W')
	{
		map->matrix[map->player_y][map->player_x] = 'E';
		map->matrix[map->player_y - 1][map->player_x] = 'P';
		put_image(map, map->img[4], map->player_x * 64, map->player_y * 64);
	}
	else if (map->matrix[map->player_y - 1][map->player_x] == '0' ||
		map->matrix[map->player_y - 1][map->player_x] == 'C')
	{
		if (map->matrix[map->player_y - 1][map->player_x] == 'C')
			map->curr_score++;
		map->matrix[map->player_y][map->player_x] = '0';
		map->matrix[map->player_y - 1][map->player_x] = 'P';
		put_image(map, map->img[0], map->player_x * 64, map->player_y * 64);
		put_image(map, map->img[2], map->player_x * 64, 
			(map->player_y - 1) * 64);
	}
	else if (map->matrix[map->player_y - 1][map->player_x] == 'E')
		move_on_exit(map, map->player_x, map->player_y - 1);
	map->player_y -= 1;
}

void	move_down(t_map_data *map)
{
	if (map->matrix[map->player_y + 1][map->player_x] == '0' ||
		map->matrix[map->player_y + 1][map->player_x] == 'C')
	{
		if (map->matrix[map->player_y + 1][map->player_x] == 'C')
			map->curr_score++;
		map->matrix[map->player_y][map->player_x] = '0';
		map->matrix[map->player_y + 1][map->player_x] = 'P';
		put_image(map, map->img[0], map->player_x * 64, map->player_y * 64);
		put_image(map, map->img[2], map->player_x * 64, 
			(map->player_y + 1) * 64);
	}
	else if (map->matrix[map->player_y + 1][map->player_x] == 'E')
		move_on_exit(map, map->player_x, map->player_y + 1);
	map->player_y += 1;
}

void	move_left(t_map_data *map)
{
	if (map->matrix[map->player_y][map->player_x - 1] == '0' ||
		map->matrix[map->player_y][map->player_x - 1] == 'C')
	{
		if (map->matrix[map->player_y][map->player_x - 1] == 'C')
			map->curr_score++;
		map->matrix[map->player_y][map->player_x] = '0';
		map->matrix[map->player_y][map->player_x - 1] = 'P';
		put_image(map, map->img[0], map->player_x * 64, map->player_y * 64);
		put_image(map, map->img[2], (map->player_x - 1) * 64,
			map->player_y * 64);
	}
	else if (map->matrix[map->player_y][map->player_x - 1] == 'E')
		move_on_exit(map, map->player_x - 1, map->player_y);
	map->player_x -= 1;
}

void	move_right(t_map_data *map)
{
	if (map->matrix[map->player_y][map->player_x + 1] == '0' ||
		map->matrix[map->player_y][map->player_x + 1] == 'C')
	{
		if (map->matrix[map->player_y][map->player_x + 1] == 'C')
			map->curr_score++;
		map->matrix[map->player_y][map->player_x] = '0';
		map->matrix[map->player_y][map->player_x + 1] = 'P';
		put_image(map, map->img[0], map->player_x * 64, map->player_y * 64);
		put_image(map, map->img[2], (map->player_x + 1) * 64,
			map->player_y * 64);
	}
	else if (map->matrix[map->player_y][map->player_x + 1])
		move_on_exit(map, map->player_x + 1, map->player_y);
	map->player_x += 1;
}
