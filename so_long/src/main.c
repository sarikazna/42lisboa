/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:53:58 by srudman           #+#    #+#             */
/*   Updated: 2024/02/26 20:19:48 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_retrieve_matrix(t_map_data *map, char *path)
{
	char	*matrix_tmp;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nCould not open the file.");
		return ;
	}
	matrix_tmp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		matrix_tmp = ft_strjoin_modified(matrix_tmp, line);
		free(line);
		map->rows++;
	}
	map->matrix = ft_split(matrix_tmp, '\n');
	free(matrix_tmp);
	close(fd);
}

/* 
Functions arguments_are_valid checks
- if we get exactly 2 arguments from the terminal and
- if the 2nd argument (the path to the game map) is correct. Specifically if
the name of the file ends with .ber
*/
int	arguments_are_valid(int argc, char *map_path)
{
	int	i;

	if (argc != 2 || !map_path)
	{
		perror("Error\nExactly two arguments needed.\n");
		return (0);
	}
	i = 0;
	while (map_path[i++])
		;
	if (map_path[i - 2] == 'r' && map_path[i - 3] == 'e' 
		&& map_path[i - 4] == 'b' && map_path[i - 5] == '.' )
		return (1);
	else
	{
		perror("Error\nFile name invalid.\n");
		return (0);
	}
}

int	main(int argc, char **argv)
{
	t_map_data	*map;

	map = NULL;
	if (arguments_are_valid(argc, argv[1]))
	{
		if (!ft_map_init(&map))
			return (-1);
		ft_retrieve_matrix(map, argv[1]);
		if (map->matrix == NULL || !ft_validate_map(map, argv[1]))
		{
			free_map_struct(map);
			return (-1);
		}
	}
	free_map_struct(map);
	return (0);
}

/*
Function flood_fill contains the matrix
*/
// void	flood_fill(char **matrix, int xP, int yP, char "0CE")
// {
// }

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

	return (0);
}
*/