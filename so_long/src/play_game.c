/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:00:25 by srudman           #+#    #+#             */
/*   Updated: 2024/03/11 15:52:09 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
int	handle_input(int keysym, t_map_data *map)
{
	if (keysym == KEY_ESC)
	{
		write(1, "You have exited the game.\n", 27);
		exit(0);	
	}
	if (keysym == KEY_W)
		move_up(map);
	if (keysym == KEY_S /*&& (map->matrix[map->player_posY + 1][map->player_posX] == '0' || map->matrix[map->player_posY + 1][map->player_posX] == 'C')*/)
		move_down(map);
	if (keysym == KEY_A /*&& (map->matrix[map->player_posY][map->player_posX - 1] == '0' || map->matrix[map->player_posY][map->player_posX - 1] == 'C')*/)
		move_left(map);
	if (keysym == KEY_D /*&& (map->matrix[map->player_posY - 1][map->player_posX + 1] == '0' || map->matrix[map->player_posY][map->player_posX + 1] == 'C')*/)
		move_right(map);
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