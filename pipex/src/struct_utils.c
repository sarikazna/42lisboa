/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:26:51 by srudman           #+#    #+#             */
/*   Updated: 2024/03/25 21:32:19 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/* I initialise my struct called 'data'. Most of it's variables I set to NULL or
to an invalid file descriptor. This is to avoid undefined behaviour laer on. */

void	data_init(t_struct **data)
{
	int	i;

	*data = malloc(sizeof(t_struct));
	if (!*data)
	{
		free(*data);
		put_error(NO_MEMORY);
		exit(0);
	}
	(*data)->cmd_path = NULL;
	(*data)->cmd_argv = NULL;
	(*data)->infile = -1;
	(*data)->outfile = -1;	
	i = 0;
}

/* Also, it was crucial to save most info on a t_struct *data 
so that variables could be much more easily accessible and memory
management as well. */

void	free_data(t_struct *data)
{
	int	i;

	if (data == NULL)
		return ;
	close(STDIN_FILENO); // learn this shit, is there a way to know if they are open?
	if (data->infile >= 0)
		close(data->infile);
	if (data->outfile >= 0)
		close(data->outfile);
	i = 0;
	if (data->cmd_path != NULL)
	{
		while (data->cmd_path[i])
			free(data->cmd_path[i++]);
		free(data->cmd_path);
	}
	i = 0;
	if (data->cmd_argv != NULL)
	{
		while (data->cmd_argv[i])
			free(data->cmd_argv[i++]);
		free(data->cmd_argv);
	}
	free(data);
}

// deal with freaking errors later
void	put_error(int err)
{
	if (err == END)
		return ;
	if (err == INV_ARGS)
		ft_putstr_fd("Error: Invalid arguments\n", 2);
	if (err == CMD_NOT_FOUND)
		ft_putstr_fd("Error: Command not found\n", 2);
	if (err == NO_FILE || err == NO_PERM)
		perror("Error");
	if (err == NO_MEMORY)
		ft_putstr_fd("Error: Memory allocation failed\n", 2);
	if (err == PIPE_ERR)
		ft_putstr_fd("Error: Pipe error\n", 2);
	if (err == DUP_ERR)
		ft_putstr_fd("Error: Dup error\n", 2);
	if (err == FORK_ERR)
		ft_putstr_fd("Error: Fork error\n", 2);
	if (err == NO_PATH)
		ft_putstr_fd("Error: PATH not found\n", 2);
	if (err == CMD_FAIL)
		ft_putstr_fd("Error: Command failed\n", 2);
}

void	pipex_exit(t_struct *data, int errno)
{
	if (errno <= 1)
		put_error(errno);
	free_data(data);
	exit(1);
}
