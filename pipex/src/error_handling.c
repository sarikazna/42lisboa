/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:26:57 by srudman           #+#    #+#             */
/*   Updated: 2024/04/08 18:50:15 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/* This function is executed after parsing has taken place. It checks if the 
parsed command is valid. If the command is not valid, it is flagged to be 
skipped. Additionally, if the infile and outfile are already flagged as
invalid, the function does not return an error for the command being invalid.
This is because the terminal command only reports on the infile/outfile 
errors in that instance and does not report other errors. */

void	check_input_cmd(t_pipex_strt *data, int j, int i, int argc)
{
	if (access(data->full_cmd[j]->cmd, F_OK) == -1)
	{
		data->full_cmd[j]->skip = true;
		if (!((j == 0 && data->infile_valid == false)
				|| (i == argc - 2 && data->outfile_valid == false)))
		{
			put_error(CMD_NOT_FOUND, data->full_cmd[j]->cmd + 1);
			// if (errno)
			// 	perror("");
		}
	}
}

// deal with freaking errors later
// problem, printf does not print into STDERR
void	put_error(int err, char *argument)
{
	// Save the file descriptor for stdout
	int stdout_fd = dup(fileno(stdout));
	// Redirect stdout to stderr
	dup2(fileno(stderr), fileno(stdout));
	// Now print error messages to stderr
	if (err == END)
		return ;
	else
		ft_putstr_fd("Error: ", 2);
	if (errno)
	{
		ft_printf("%s: ", argument);
		perror("");
	}
	else if (err == INV_ARGS)
		ft_putstr_fd("Invalid argument\n", 2);
	else if (err == CMD_NOT_FOUND)
		ft_printf("%s: command not found\n", argument);
	else if (err == NO_FILE)
		ft_printf("%s: No such file or directory\n", argument);
	else if (err == NO_MEMORY)
		ft_putstr_fd("Memory allocation failed\n", 2);
	else if (err == PIPE_ERR)
		ft_putstr_fd("pipe: Too many open files\n", 2);
	else if (err == DUP_ERR)
		ft_putstr_fd("Dup error\n", 2);
	else if (err == FORK_ERR)
		ft_putstr_fd("Fork failed: Cannot allocate memory\n", 2);
	else if (err == NO_PATH)
		ft_printf("%s: PATH not found\n", argument);
	else if (err == CMD_FAIL)
		ft_putstr_fd("Command failed\n", 2);
	// Restore the original stdout
	fflush(stdout); // Flush stdout before redirecting
	dup2(stdout_fd, fileno(stdout));
	// Close the duplicate file descriptor
	close(stdout_fd);
}

void	check_files(int argc, char **argv, t_pipex_strt **data)
{
	if (access((argv[1]), F_OK) == -1)
		put_error(NO_FILE, argv[1]);
	else if (access((argv[1]), R_OK) == -1)
		put_error(NO_PERM, argv[1]);
	else if (!argv[1][0])
		put_error(NO_FILE, "No such file or directory\n");
	if (access((argv[1]), F_OK) == -1 || access((argv[1]), R_OK) == -1
		|| !argv[1][0])
		(*data)->infile_valid = false;
	if (access((argv[argc - 1]), F_OK) == -1)
		return ;
	else if (access((argv[argc - 1]), W_OK) == -1)
	{
		(*data)->outfile_valid = false;
		put_error(NO_PERM, argv[argc - 1]);
	}
}
