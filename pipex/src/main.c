/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:08:04 by srudman           #+#    #+#             */
/*   Updated: 2024/03/25 19:22:27 by srudman          ###   ########.fr       */
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

/* I parse **envp to get the path to commands in my struct (*data)->cmd_path
I also allocate commands from the terminal input to my struct, specifically
to the (*data)->cmd_argv.*/

void	parse_input(int argc, char **argv, char **envp, t_struct **data)
{
	int i;
	int	j;

	i = 0;
	if (envp[i] == NULL)
		pipex_exit(*data, NO_PATH);
	while (envp[i] && ft_strncmp("PATH=", envp[i], 5) != 0)
		i++;
	if (ft_strncmp("PATH=", envp[i], 5) != 0)
		pipex_exit(*data, NO_PATH);
	(*data)->cmd_path = ft_split(envp[i] + 5, ':');
	i = 2;
	j = 0;
	(*data)->cmd_argv = malloc(sizeof(char *) * (argc - i));
	if (!(*data)->cmd_argv)
		pipex_exit(*data, NO_MEMORY);
	while(i < argc - 1)
		(*data)->cmd_argv[j++] = ft_strdup(argv[i++]);
	(*data)->cmd_argv[j] = NULL;
	// check if the input commands are actual commands, using access?
}

/* We ran checks on the number of arguments, check if the infile is existing
and is readable. We initialise the stack and performing parsing. */

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
    // Check if the output file is writable or can be created
	data_init(&data);
	parse_input(argc, argv, envp, &data);
    // Check if a pipe can be created
	pipex_exit(data, END);
}