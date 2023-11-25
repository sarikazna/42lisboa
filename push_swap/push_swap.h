/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:37:29 by srudman           #+#    #+#             */
/*   Updated: 2023/11/25 12:57:03 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_stack_node
{
	int		value;
	int		position;
	struct s_stack_node *prev;
	struct s_stack_node *next;
	// more meta data missing
}				t_stack_node;

#endif
