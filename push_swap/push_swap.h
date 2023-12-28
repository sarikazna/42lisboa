/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:37:29 by srudman           #+#    #+#             */
/*   Updated: 2023/12/28 13:22:47 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct	s_stack_node
{
	int		value;
	int		position;
	struct s_stack_node *prev;
	struct s_stack_node *next;
	// more meta data missing
}				t_stack_node;

int				syntax_error(char *nptr);
long			ft_atol(const char *nptr);
t_stack_node	*ft_nodeadd_back(t_stack_node **first, t_stack_node *new);
t_stack_node	*ft_nodenew(int nbr);
int				ft_stacksize(t_stack_node *first);
t_stack_node	*ft_nodelast(t_stack_node *first);
t_stack_node	**swap_movement(t_stack_node **head);
int				sa(t_stack_node **a);
int				sb(t_stack_node **b);
int				ss(t_stack_node **a, t_stack_node **b);
t_stack_node	**rotate_movement(t_stack_node **head);
int				ra(t_stack_node **a);
int				rb(t_stack_node **b);
int				rr(t_stack_node **a, t_stack_node **b);


#endif
