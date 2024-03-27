/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:13:13 by srudman           #+#    #+#             */
/*   Updated: 2024/03/27 18:47:28 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void 	check_input_cmd(t_struct **data)
{
	int	i;
	int	j;
	char *tmp_cmd;

	i = 0;
	while ((*data)->full_cmd[i])
	{
		j = 0;
		tmp_cmd = NULL;
		while ((*data)->cmd_path[j])
		{
			tmp_cmd = ft_strjoin((*data)->cmd_path[j], (*data)->full_cmd[i]->cmd);
			if (!tmp_cmd)
			{
				free(tmp_cmd);
				pipex_exit(*data, NO_MEMORY);
			}
			if (access(tmp_cmd, F_OK) == 0)
			{
				free((*data)->full_cmd[i]->cmd);
				(*data)->full_cmd[i]->cmd = strdup(tmp_cmd);
				free(tmp_cmd);
				break ;
			}
			else
				free(tmp_cmd);
			j++;
		}
		if (access((*data)->full_cmd[i]->cmd, F_OK) == -1)
			pipex_exit(*data, CMD_NOT_FOUND);
		i++;
	}
}

void	parse_flags(char *argv, t_struct *data, int j);
{
	char	*space_pos;

	space_pos = 
	data->full_cmd[j]->flag = ft_strchr(argv, " ");
	data->full_cmd[j]->cmd = ft_substr(argv, 0, ft_strlen(argv - data->full_cmd[j]->flag));
}

// how to handle "wc -l" input?
// struct pointer to a pointer
void	parse_input_cmd(int argc, char **argv, t_struct **data)
{
	int	i;
	int	j;
	
	i = 2;
	j = 0;
	(*data)->full_cmd = malloc(sizeof(t_cmd_strt *) * (argc - i));
	if (!(*data)->full_cmd)
		pipex_exit(*data, NO_MEMORY);
	while(i < argc - 1)
	{
		(*data)->full_cmd[j] = malloc(sizeof(t_cmd_strt));
		if (!(*data)->full_cmd[j])
			pipex_exit(*data, NO_MEMORY);
		if (ft_strchr(argv[i], " ") != NULL)
			parse_flags(argv[i], *data, j);
		else
			(*data)->full_cmd[j]->flag = NULL;
			(*data)->full_cmd[j]->cmd = ft_strdup(argv[i]);
		j++;
		i++;
	}
	(*data)->full_cmd[j] = NULL;
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