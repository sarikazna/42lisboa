/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:08:04 by srudman           #+#    #+#             */
/*   Updated: 2024/03/24 23:12:25 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// check if argc is even used
// consider skipping 
t_struct	data_init(int argc, char **argv, char **envp, t_struct *data)
{
	t_struct	*data;
	int				i;

	data = malloc(sizeof(data));
	if (!data)
		pipex_exit(data, NO_MEMORY);
	data->raw_path = NULL;
	data->cmd_path = NULL; // at what point do I need to initialise those?
	data->cmd_argv = NULL;
	i = 2;
	if (envp[i] == NULL)
		pipex_exit(data, NO_PATH);
	while (envp[i] && ft_strncmp("PATH=", envp[i], 5) != 0)
		i++;
	if (ft_strncmp("PATH=", envp[i], 5) != 0) // are we sure it's 5?
		pipex_exit(data, NO_PATH);
	data->raw_path = malloc(sizeof(char) * (ft_strlen(envp[i]) + 1));
	data->cmd_path = split(data->raw_path, ':');
}

/* We ran checks on the number of arguments, check if the infile is existing and
is readable. */
int	main(int argc, char **argv, char **envp)
{
    t_struct	*data;
	
	data = NULL;
	if (!(argc == 5 && argv[1][0] && argv[2][0] && argv[3][0] && argv[4][0]))
		pipex_exit(data, INV_ARGS);
	if (access((argv[1]), F_OK) == -1)
		pipex_exit(data, NO_FILE);
	if (access((argv[1]), R_OK) == -1)
		pipex_exit(data, NO_PERM);
	// use access to see if the file can be openned
    // Check if the input file exists, check if it is readable, has correct premissions
    // Check if the output file is writable or can be created, has correct permissions
	data_init(argc, argv, envp, data);
    // Check if a pipe can be created

    // Obtain parth fro the commands, look for PATH varaible
    // check for errors

}