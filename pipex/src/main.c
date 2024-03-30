/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:08:04 by srudman           #+#    #+#             */
/*   Updated: 2024/03/30 21:33:33 by srudman          ###   ########.fr       */
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
	// Check if the output file exists, if not, how to create it
	parse_input(argc, argv, envp, &data);
	// pipex(&data);
	// Check if a pipe can be created
	pipex_exit(data, END, "Happy End\n");
}
