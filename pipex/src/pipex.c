/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:24:19 by srudman           #+#    #+#             */
/*   Updated: 2024/04/07 20:49:03 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	open_files(t_pipex_strt *data)
{
	if (data->infile_valid == true)
		(*data)->infile = open(O_WRONLY);
	if (data->outfile_valid == false)
		(*data)->infile = open( O_WRONLY | O_CREAT);
	else if (data->outfile_valid == true)
		(*data)->outfile = open(O_WRONLY);
}

void    pipex(t_pipex_strt **data)
{
	pipe(int pipefd[2]);
	(*data)->pid1 = fork(void);

	// In child
	dup2();
	close end[0];
	execve((*data)->full_cmd[i]->cmd);

	// In parent
	dup2();
	close end[1];
	execve((*data)->full_cmd[i]->cmd);
}