/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:53:58 by srudman           #+#    #+#             */
/*   Updated: 2024/02/17 19:26:32 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*free_if_error(char *string, int fd, int index)
{
	while(index-- >= 0)
		free(string[index]);
	close(fd);
	return(NULL);
}

/* Inspiration https://github.com/augustobecker/so_long/blob/main/sources/ft_init_map.c*/
void	**ft_retrieve_matrix(t_map_data game, char *path)
{
	char	*matrix_tmp;
	int		fd;
	char 	*line;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		// put error
	game->rows = 0;
	matrix_tmp = st_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
	}
	close(fd);
}

/* 
Functions arguments_are_valid checks
- if we get exactly 2 arguments and
- if the 2nd argument (the path to the game map) is corret. Specifically if
the name of the file ends with .ber
*/
int	arguments_are_valid(int argc, char *map_path)
{
	int	i;
	
	if (argc != 2 || !map_path)
	{
		perror("Error, exactly two arguments needed. Try: ./so_long maps/valid_maps/<name of map>\n");
		return (-1);
	}
	i = 0;
	while (map_path[i++]);
	if (map_path[i - 2] == 'r' && map_path[i - 3] == 'e' && map_path[i - 4] == 'b' 
		&& map_path[i - 5] == '.' )
		return (1);
	else
	{
		perror("Error, File name invalid.\n");
		return (-1);
	}
}

/*
Function flood_fill contains the matrix
*/
void	flood_fill(char **matrix, int xP, int yP, char "0CE")
{
	
}

int	main(int argc, char **argv)
{
	t_map_data game;
	
	if (arguments_are_valid(argc, argv[1]))
	{
		ft_retrieve_matrix(game, argv[1]);
	}
	return (0);
}

/*

int	deal_key()
{
	ft_putchar_fd('X', 1);
	mlx_pixel_put(mlx_ptr, win_ptr,);
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 500, "Moonlight Sonata");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	
	if (argc != 2 || !*argv[1])
	{
		perror("Error, exactly two arguments needed. Try: ./so_long maps/valid_maps/<name of map>");
		return (-1);
	}
	
	return (0);
}
*/