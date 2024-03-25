/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:26:51 by srudman           #+#    #+#             */
/*   Updated: 2024/03/25 19:07:12 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*Also, it was crucial to save most info on a t_pipexdata struct 
so that functions could be much more easily accessible. I made 
a function pipex_perror that will print a custom error message 
based on the error code, and also made another function pipex_exit 
which easily frees the t_pipexdata struct to ensure all memory 
is freed flawlessly.*/

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

/* Also we need to check that the infile and outfile exist
and/or have the correct permissions. 

Not to mention that 
the commands from the input may not exist. Hence, to handle 
all possible errors I created an enum to distinguish and handle 
all these different errors properly. 

*/

void	pipex_exit(t_struct *data, int errno)
{
	if (errno <= 1)
		put_error(errno);
	free_data(data);
	exit(1);
}
