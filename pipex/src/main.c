/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:08:04 by srudman           #+#    #+#             */
/*   Updated: 2024/03/29 18:27:17 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/* We ran checks on the number of arguments, check if the infile is existing
and is readable. We initialise the stack and performing parsing. */

int	main(int argc, char **argv, char **envp)
{
    t_pipex_strt	*data;
	
	data = NULL;
	data_init(&data);
	if (!(argc == 5))
		pipex_exit(data, INV_ARGS, argv[1]);
	check_files(argc, argv, &data);
	// what if outfile is /dev/stdout or infile is /dev/stdout
    // Check if the output file is writable or can be created
	// Check  && argv[1][0] && argv[2][0] && argv[3][0] && argv[4][0])
	parse_input(argc, argv, envp, &data);
    // Check if a pipe can be created
	pipex_exit(data, END, "Happy End\n");
}