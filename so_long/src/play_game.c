/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:00:25 by srudman           #+#    #+#             */
/*   Updated: 2024/03/15 19:02:19 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// NEWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
void	exit_game(t_map_data *map)
{
	free_map_struct(map);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	if (map->mlx_ptr != NULL)
		free(map->mlx_ptr);
	exit(0);
}

/* This function makes sure the player does not move into a wall. It also
cannot move into an exit if the player hasn't collected all collectables.
The subject requires us to display number of moves/steps of the player in
the Shell. So if we validate that the move is valid we will count +1
towards the total number of steps/moves and write this information into
the shell using the write function. */

int	move_is_valid(t_map_data *map, int x, int y)
{
	if (map->matrix[y][x] == '0' || map->matrix[y][x] == 'C')
	{
		map->steps++;
		ft_putstr_fd("Number of moves: ", 1);
		ft_putnbr_fd(map->steps, 1);
		ft_putstr_fd("\n", 1);
		return (1);
	}
	else if (map->matrix[y][x] == 'E' && map->curr_score == map->score)
	{
		map->steps++;
		ft_putstr_fd("Number of moves: ", 1);
		ft_putnbr_fd(map->steps, 1);
		ft_putstr_fd("\n", 1);
		return (1);
	}
	else
		return (0);
}

/* This function is called by 
mlx_hook(map->win_ptr, 17, 1L<<19, &on_destroy, &map)
It ends the game once the X on the window is being pressed. */

int	on_destroy(t_map_data **map)
{
	write(1, "You have exited the game.\n", 27);
	exit_game(*map);
	return (0);
}

/* This function is called by mlx_key_hook(map->win_ptr, handle_input, &map)
It ends the game once you press ESC on the keyboard. */

int	handle_input(int keysym, t_map_data **map)
{
	if (keysym == KEY_ESC)
	{
		write(1, "You have exited the game.\n", 27);
		exit(0);
	}
	if (keysym == KEY_W && move_is_valid
		(*map, (*map)->player_x, ((*map)->player_y - 1)))
		move_up(*map);
	if (keysym == KEY_S && move_is_valid
		(*map, (*map)->player_x, ((*map)->player_y + 1)))
		move_down(*map);
	if (keysym == KEY_A && move_is_valid
		(*map, ((*map)->player_x - 1), (*map)->player_y))
		move_left(*map);
	if (keysym == KEY_D && move_is_valid
		(*map, ((*map)->player_x + 1), (*map)->player_y))
		move_right(*map);
	return (0);
}

/* Function play_game handles key board inputs of W S A D (up, down, left, 
right) and Ecs by calling mlx_key_hook. mlx_hook handles a mouse press on 
the X sign in the window. mlx_loop keeps the game running.
*/
// mlx_key_hook will be used for the bonus for animations
int	play_game(t_map_data *map)
{
	mlx_key_hook(map->win_ptr, handle_input, &map);
	mlx_hook(map->win_ptr, 17, 1L << 19, &on_destroy, &map);
	mlx_loop(map->mlx_ptr);
	return (1);
}
