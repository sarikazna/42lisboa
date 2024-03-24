/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:26:51 by srudman           #+#    #+#             */
/*   Updated: 2024/03/24 22:54:51 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"


void	pipex_exit(t_struct *data, int err)
{
	// if err < 1 then call pipex+Error
	free_data(data);
	exit(0);
}

/*Also, it was crucial to save most info on a t_pipexdata struct 
so that functions could be much more easily accessible. I made 
a function pipex_perror that will print a custom error message 
based on the error code, and also made another function pipex_exit 
which easily frees the t_pipexdata struct to ensure all memory 
is freed flawlessly.*/

void	free_data(t_struct *data)
{
	int	i;
	
	if (data == NULL)
		return ;
	close(STDIN_FILENO); // learn this shit, is there a way to know if they are open?
	close(data->infile); // is there a way to know if they are open?
	close(data->outfile); // is there a way to know if they are open?
	if (data->raw_path != NULL)
		free(data->raw_path);
	i = 0;
	if (data->cmd_path != NULL)
	{
		while (data->cmd_path[i])
			free(data->cmd_path[i++]);
		free(data->cmd_path);
	}
	free(data);
}


/* Also we need to check that the infile and outfile exist
and/or have the correct permissions. 

Not to mention that 
the commands from the input may not exist. Hence, to handle 
all possible errors I created an enum to distinguish and handle 
all these different errors properly. 

*/