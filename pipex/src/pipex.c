/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:24:19 by srudman           #+#    #+#             */
/*   Updated: 2024/04/15 15:37:30 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	execute(t_cmd_strt *full_cmd, char **envp)
{
	return(execve(full_cmd->cmd, full_cmd->flag, envp));
}

void	pipex(t_pipex_strt **data, char **envp)
{
	int pipefd[2];
	int	status;
	pid_t	pid;

	if (pipe(pipefd) == -1)
		pipex_exit(*data, PIPE_ERR, "pipe");
	pid = fork();
	if (pid < 0)
		pipex_exit(*data, FORK_ERR, "Fork failed");
	if (!pid)
	{
		if ((*data)->infile_valid == true)
		{
			if (dup2((*data)->infile, STDIN_FILENO) < 0)
			{
				put_error(DUP_ERR, "dup2 failed");
				// return ;
			}
			if (dup2(pipefd[1], STDOUT_FILENO) < 0)
			{
				put_error(DUP_ERR, "dup2 failed");
				// return ;
			}
			close (pipefd[0]);
			close ((*data)->infile);
			status = execute((*data)->full_cmd[0], envp);
			waitpid(pid, NULL, 0);
		}
	}
	else
	{
		// waitpid(child pid to wait for (return value of fork), pointer to integer that stores child's exit status, 0);
		if ((*data)->outfile_valid == true)
		{
			if (dup2((*data)->outfile, STDOUT_FILENO) < 0)
			{
				put_error(DUP_ERR, "dup2 failed");
				// return ;
			}
			if (dup2(pipefd[0], STDIN_FILENO) < 0)
			{
				put_error(DUP_ERR, "dup2 failed");
				// return ;
			}
			close (pipefd[1]);
			close ((*data)->outfile);
			execute((*data)->full_cmd[1], envp);
			waitpid(pid, &status, 0);
		}
		// WHERE TO PUT WAITPID?
		// HERE: https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901
	}
}