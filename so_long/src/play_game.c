/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:00:25 by srudman           #+#    #+#             */
/*   Updated: 2024/03/11 17:43:05 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* This function makes sure the player does not move into a wall. It also
cannot move into an exit if the player hasn't collected all collectables. */

int	move_is_valid(t_map_data *map, int x, int y)
{
	if (map->matrix[y][x] == '0' || map->matrix[y][x] == 'C')
		return (1);
	else if (map->matrix[y][x] == 'E' && map->curr_score == map->score)
		return (1);
	else
	{
		printf("invalid move\n");
		return (0);
	}
}

/* This function is called by 
mlx_hook(map->win_ptr, 17, 1L<<19, &on_destroy, &map)
It ends the game once the X on the window is being pressed. */

int on_destroy()
{
	write(1, "You have exited the game.\n", 27);
	exit(0);
	return (0);
}

/* This function is called by mlx_key_hook(map->win_ptr, handle_input, &map)
It ends the game once you press ESC on the keyboard. */

// make sure to count the number of moves
int	handle_input(int keysym, t_map_data **map)
{
	if (keysym == KEY_ESC)
	{
		write(1, "You have exited the game.\n", 27);
		exit(0);	
	}
	if (keysym == KEY_W && move_is_valid(*map, (*map)->player_posX, ((*map)->player_posY - 1)))
	{
		move_up(*map);
		return (1);
	}
	if (keysym == KEY_S && move_is_valid(*map, (*map)->player_posX, ((*map)->player_posY + 1)))
	{
		move_down(*map);
		return (1);
	}
	if (keysym == KEY_A && move_is_valid(*map, ((*map)->player_posX - 1), (*map)->player_posY))
	{
		move_left(*map);
		return (1);
	}
	if (keysym == KEY_D && move_is_valid(*map, ((*map)->player_posX + 1), (*map)->player_posY))
	{
		move_right(*map);
		return (1);
	}
	return (0);
}

int	play_game(t_map_data *map)
{
	mlx_key_hook(map->win_ptr, handle_input, &map);
	mlx_hook(map->win_ptr, 17, 1L<<19, &on_destroy, &map);
	// mlx_key_hook will be used for the bonus for animations
	mlx_loop(map->mlx_ptr);
	return (1);
}


// int	deal_key()
// {
// 	ft_putchar_fd('X', 1);
// 	//mlx_pixel_put(mlx_ptr, win_ptr,);
// 	return (0);
// }

// MEMORY LEAK
// int on_destroy(t_map_data *map)
// {
// 	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
// 	mlx_destroy_display(map->mlx_ptr);
// 	free(map->mlx_ptr);
// 	exit(0);
// 	return (0);
// }

// int on_keypress(int keysym, t_map_data *map)
// {
// 	(void)map;
// 	printf("Pressed key: %d\\n", keysym);
// 	return (0);
// }

/*
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	Register key release hook
	The KeyRelease and DestroyNotify constants are native X11 events, and can be imported through the X11 headers.
	mlx_hook(map->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &map);
	Register destroy hook
	mlx_hook(map->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &map);
	mlx_loop(map->mlx_ptr);
*/