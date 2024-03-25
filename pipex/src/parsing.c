/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:13:13 by srudman           #+#    #+#             */
/*   Updated: 2024/03/25 22:25:06 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// how to handle "wc -l" input? - add a command struct!
// this function below will have to be changed

void 	check_input_cmd(t_struct **data)
{
	int	i;
	int	j;
	char *tmp_cmd;

	i = 0;
	while ((*data)->cmd_argv[i])
	{
		j = 0;
		tmp_cmd = NULL;
		while ((*data)->cmd_path[j])
		{
			tmp_cmd = ft_strjoin((*data)->cmd_path[j], (*data)->cmd_argv[i]);
			if (!tmp_cmd)
			{
				free(tmp_cmd);
				pipex_exit(*data, NO_MEMORY);
			}
			if (access(tmp_cmd, F_OK) == 0)
			{
				free((*data)->cmd_argv[i]);
				(*data)->cmd_argv[i] = strdup(tmp_cmd);
				free(tmp_cmd);
				break ;
			}
			else
				free(tmp_cmd);
			j++;
		}
		if (access((*data)->cmd_argv[i], F_OK) == -1)
			pipex_exit(*data, CMD_NOT_FOUND);
		// printf("Cmd[%i]: %s\n", i, (*data)->cmd_argv[i]);
		i++;
	}
}

void	parse_input_cmd(int argc, char **argv, t_struct **data)
{
	int	i;
	int	j;
	
	i = 2;
	j = 0;
	(*data)->cmd_argv = malloc(sizeof(char *) * (argc - i));
	if (!(*data)->cmd_argv)
		pipex_exit(*data, NO_MEMORY);
	while(i < argc - 1)
		(*data)->cmd_argv[j++] = ft_strdup(argv[i++]);
	(*data)->cmd_argv[j] = NULL;
	// DON'T FORGET TO DELETE
	// i = 0;
	// while ((*data)->cmd_argv[i])
	// {
	// 	printf("Cmd[%i]: %s\n", i, (*data)->cmd_argv[i]);
	// 	i++;

	
	///////////////////////// LEFT HEEEEREEE, now put cmd_argv[j] into t_cmd_strt;
	// }
}

void	parse_envp_path(char **envp, t_struct **data)
{
	int i;

	i = 0;
	if (envp[i] == NULL)
		pipex_exit(*data, NO_PATH);
	while (envp[i] && ft_strncmp("PATH=", envp[i], 5) != 0)
		i++;
	if (ft_strncmp("PATH=", envp[i], 5) != 0)
		pipex_exit(*data, NO_PATH);
	(*data)->cmd_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while ((*data)->cmd_path[i])
	{
		(*data)->cmd_path[i] = ft_strjoin_modified((*data)->cmd_path[i], "/");
		i++;
	}
	// DON'T FORGET TO DELETE
	// i = 0;
	// while((*data)->cmd_path[i])
	// {
	// 	printf("Path[%i]: %s\n", i, (*data)->cmd_path[i]);
	// 	i++;
	// }
}

/* I parse **envp to get the path to commands in my struct (*data)->cmd_path
I also allocate commands from the terminal input to my struct, specifically
to the (*data)->cmd_argv.*/

void	parse_input(int argc, char **argv, char **envp, t_struct **data)
{
	parse_envp_path(envp, data);
	parse_input_cmd(argc, argv, data);
	check_input_cmd(data);
}