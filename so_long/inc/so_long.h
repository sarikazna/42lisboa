/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:10:52 by srudman           #+#    #+#             */
/*   Updated: 2024/02/18 21:52:56 by srudman          ###   ########.fr       */
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
	void	*wall;
	void	*exit;
	void	*items;
	void	*player;
	void	*enemy; // bonus
	int		enemy_pos; // bonus
	int		gameover;
	int		steps;  //bonus
	
}	t_map_data;

/*  FUNCTIONS */
void	free_map_struct(t_map_data *map);
int		ft_map_init(t_map_data **map);
int		ft_validate_map(t_map_data *map);


#endif