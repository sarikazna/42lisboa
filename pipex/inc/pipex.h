/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:54:40 by srudman           #+#    #+#             */
/*   Updated: 2024/03/27 12:26:37 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h> // needed?
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"


enum e_pipex_error
{
	END = 1,
	CMD_NOT_FOUND = 0,
	NO_FILE = -1,
	NO_PERM = -2,
	INV_ARGS = -3,
	NO_MEMORY = -4,
	PIPE_ERR = -5,
	DUP_ERR = -6,
	FORK_ERR = -7,
	NO_PATH = -8,
	CMD_FAIL = -9
};

typedef struct s_cmd_strt
{
	char		*cmd;
	char		*flag;
}	t_cmd_strt;

typedef struct s_struct
{
	char		**cmd_path;
	t_cmd_strt 	**full_cmd;
	pid_t		pid1;
	pid_t		pid2;
	int			infile;
	int			outfile;
}	t_struct;

void	pipex_exit(t_struct *data, int errno);
void	put_error(int errno);
void	parse_input(int argc, char **argv, char **envp, t_struct **data);
void	data_init(t_struct **data);

#endif