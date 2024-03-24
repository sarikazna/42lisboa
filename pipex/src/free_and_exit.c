/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:26:51 by srudman           #+#    #+#             */
/*   Updated: 2024/03/24 19:29:31 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex_exit(t_struct *data)
{
	
}

typedef struct s_struct
{
	char	*path;
	char	**cmd_path;
	t_pid	pid1;
	t_pid	pid2;
	int		infile;
	int		outfile;
}	t_struct;

void	free_data(t_struct *data)
{
	if (fata)
}

void	free_map_struct(t_map_data *map)
{
	int	i;

	if (map == NULL)
		return ;
	if (map->matrix != NULL)
	{
		i = 0;
		while (map->matrix[i])
			free(map->matrix[i++]);
		free(map->matrix);
	}
	if (map->img != NULL)
	{
		i = 0;
		while (i < 7 && map->img[i] != NULL)
			mlx_destroy_image(map->mlx_ptr, map->img[i++]);
		free(map->img);
	}
}