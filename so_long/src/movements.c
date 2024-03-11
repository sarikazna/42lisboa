/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:39:27 by srudman           #+#    #+#             */
/*   Updated: 2024/03/11 19:13:00 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_map_data *map)
{
	if (map->matrix[map->player_posY - 1][map->player_posX] == '0' ||
		map->matrix[map->player_posY - 1][map->player_posX] == 'C')
	{
		if (map->matrix[map->player_posY - 1][map->player_posX] == 'C')
			map->curr_score++;
		map->matrix[map->player_posY][map->player_posX] = '0';
		map->matrix[map->player_posY - 1][map->player_posX] = 'P';
		put_image(map, map->img[0], map->player_posX * 64, map->player_posY * 64);
		put_image(map, map->img[2], map->player_posX * 64, (map->player_posY - 1) * 64);
		map->player_posY -= 1;
	}
	if (map->matrix[map->player_posY - 1][map->player_posX] == 'E'
		&& map->curr_score == map->score)
	{
		write(1, "Congrats! You won!\n", 19);
		exit(0);
	}
}

void	move_down(t_map_data *map)
{
	if (map->matrix[map->player_posY + 1][map->player_posX] == '0' ||
		map->matrix[map->player_posY + 1][map->player_posX] == 'C')
	{
		if (map->matrix[map->player_posY + 1][map->player_posX] == 'C')
			map->curr_score++;
		map->matrix[map->player_posY][map->player_posX] = '0';
		map->matrix[map->player_posY + 1][map->player_posX] = 'P';
		put_image(map, map->img[0], map->player_posX * 64, map->player_posY * 64);
		put_image(map, map->img[2], map->player_posX * 64, (map->player_posY + 1) * 64);
		map->player_posY += 1;
	}
	if (map->matrix[map->player_posY + 1][map->player_posX] == 'E'
		&& map->curr_score == map->score)
	{
		write(1, "Congrats! You won!\n", 19);
		exit(0);
	}
}

void	move_left(t_map_data *map)
{
	if (map->matrix[map->player_posY][map->player_posX - 1] == '0' ||
		map->matrix[map->player_posY][map->player_posX - 1] == 'C')
	{
		if (map->matrix[map->player_posY][map->player_posX - 1] == 'C')
			map->curr_score++;
		map->matrix[map->player_posY][map->player_posX] = '0';
		map->matrix[map->player_posY][map->player_posX - 1] = 'P';
		put_image(map, map->img[0], map->player_posX * 64, map->player_posY * 64);
		put_image(map, map->img[2], (map->player_posX - 1) * 64, map->player_posY * 64);
		map->player_posX -= 1;
	}
	if (map->matrix[map->player_posY][map->player_posX - 1] == 'E'
		&& map->curr_score == map->score)
	{
		write(1, "Congrats! You won!\n", 19);
		exit(0);
	}
}

void	move_right(t_map_data *map)
{
	if (map->matrix[map->player_posY][map->player_posX + 1] == '0' ||
		map->matrix[map->player_posY][map->player_posX + 1] == 'C')
		if (map->matrix[map->player_posY][map->player_posX + 1] == 'C')
			map->curr_score++;
	{
		map->matrix[map->player_posY][map->player_posX] = '0';
		map->matrix[map->player_posY][map->player_posX + 1] = 'P';
		put_image(map, map->img[0], map->player_posX * 64, map->player_posY * 64);
		put_image(map, map->img[2], (map->player_posX + 1) * 64, map->player_posY * 64);
		map->player_posX += 1;
	}
	if (map->matrix[map->player_posY][map->player_posX + 1] == 'E'
		&& map->curr_score == map->score)
	{
		write(1, "Congrats! You won!\n", 19);
		exit(0);
	}
}
