/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:08:04 by srudman           #+#    #+#             */
/*   Updated: 2024/03/25 22:25:33 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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