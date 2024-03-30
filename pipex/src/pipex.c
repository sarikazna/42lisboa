/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:24:19 by srudman           #+#    #+#             */
/*   Updated: 2024/03/30 21:23:41 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void    pipex(t_pipex_strt **data)
{
	(*data)->infile = open();
	(*data)->outfile = open();
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