/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:26:51 by srudman           #+#    #+#             */
/*   Updated: 2024/03/30 20:28:12 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	cmd_strt_init(t_pipex_strt **data, int j)
{
	(*data)->full_cmd[j] = malloc(sizeof(t_cmd_strt));
	if (!(*data)->full_cmd[j])
		pipex_exit(*data, NO_MEMORY, NULL);
	(*data)->full_cmd[j]->path = NULL;
	(*data)->full_cmd[j]->cmd = NULL;
	(*data)->full_cmd[j]->flag = NULL;
	(*data)->full_cmd[j]->skip = false;
}

/* I initialise my struct called 'data'. Most of it's variables I set to NULL or
to an invalid file descriptor. This is to avoid undefined behaviour laer on. */

void	data_init(t_pipex_strt **data)
{
	*data = malloc(sizeof(t_pipex_strt));
	if (!*data)
	{
		free(*data);
		put_error(NO_MEMORY, NULL);
		exit(0);
	}
	(*data)->full_cmd = NULL;
	(*data)->infile = -1;
	(*data)->outfile = -1;
	(*data)->infile_valid = true;
	(*data)->outfile_valid = true;
}

void	free_cmd_strt(t_pipex_strt *data)
{
	int	i;
	int j;

	i = 0;
	while (data->full_cmd[i])
	{
		if (data->full_cmd[i]->cmd != NULL)
			free(data->full_cmd[i]->cmd);
		// We never allocated memory so no need to free it
		// if (data->full_cmd[i]->flag != NULL)
		// 	free(data->full_cmd[i]->flag);
		if (data->full_cmd[i]->path != NULL)
		{
			j = 0;
			while (data->full_cmd[i]->path[j])
				free(data->full_cmd[i]->path[j++]);
			free(data->full_cmd[i]->path);
		}		
		free(data->full_cmd[i]);
		i++;
	}
}

/* Also, it was crucial to save most info on a t_pipex_strt *data 
so that variables could be much more easily accessible and memory
management as well. */

void	free_data(t_pipex_strt *data)
{
	if (data == NULL)
		return ;
	close(STDIN_FILENO); // learn this shit, is there a way to know if they are open?
	if (data->infile >= 0)
		close(data->infile);
	if (data->outfile >= 0)
		close(data->outfile);
	if (data->full_cmd != NULL)
	{
		free_cmd_strt(data);
		free(data->full_cmd);
	}
	free(data);
}

void	pipex_exit(t_pipex_strt *data, int errno, char *argument)
{
	if (errno <= 1)
		put_error(errno, argument);
	free_data(data);
	exit(1);
}
