/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:37:29 by srudman           #+#    #+#             */
/*   Updated: 2023/11/23 17:10:20 by srudman          ###   ########.fr       */
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
	struct s_stack_node
	
}				s_stack_node;

#endif
