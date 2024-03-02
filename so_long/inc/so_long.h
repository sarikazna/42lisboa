/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:10:52 by srudman           #+#    #+#             */
/*   Updated: 2024/03/02 16:55:30 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
// Note to self. Check if you even used some of the functions from math.h library
# include <math.h>

/* DATA TYPES */

/* Keycodes on a keyboard */
// Double check the key values
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
// Mislim da je krizec 17

/* STRUCTS */

/* t_map_data is a struct containing info on the the game layout. 
> int 	player_posX and Y = position on the matrix with X and Y axis;
> int score = number of collectable in the game;
> int curr_score = number of collected collectables, the game starts with 0; 
> void *wall, *exit, *items, *player, *enemy = points to the image of each;
*/
typedef struct s_map_data
{
	char	**matrix;
	int		rows;
	int		columns;
	int		height;
	int		width;
	int		no_exits;
	int		no_players_check;
	int 	player_posX;
	int 	player_posY;
	int		score; // number collectables on the map
	int		curr_score;
	void	**img; // MLX image pointers (on the stack)
	void	*mlx_ptr; 
	void	*win_ptr;
	int		enemy_pos; // bonus
	int		gameover;
	int		steps;  //bonus
	
}	t_map_data;



/*  FUNCTIONS */
void	free_map_struct(t_map_data *map);
int		ft_map_init(t_map_data **map);
int		ft_validate_map(t_map_data *map, char *path_to_file);
int		ft_allowed_character(t_map_data *map);
void	ft_assign_position(t_map_data *map);
void	ft_flood_fill(int x, int y, t_map_data *map);
void	ft_rewrite_matrix(t_map_data *map, int fd);
int		game_init(t_map_data *map);


#endif