/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:37:29 by srudman           #+#    #+#             */
/*   Updated: 2023/12/28 14:04:50 by srudman          ###   ########.fr       */
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
	int		push_cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack_node *near_b_val;
	struct s_stack_node *prev;
	struct s_stack_node *next;
}				t_stack_node;

// Error handling
int				syntax_error(char *nptr);
int				contains_duplicate(t_stack_node *a, int tmp);

// Stack initialisation
t_stack_node	*stack_init(t_stack_node *a, int stack_len, char **nptr);

// Sorting algorithms
t_stack_node	*sort_three(t_stack_node **a);

// Linked list utils
t_stack_node	*ft_nodeadd_back(t_stack_node **first, t_stack_node *new);
t_stack_node	*ft_nodenew(int nbr);
int				ft_stacksize(t_stack_node *first);
void			ft_position_nbr(t_stack_node *first, int nbr);
t_stack_node	*ft_nodelast(t_stack_node *first);
void			free_list(t_stack_node *head);
int				stack_is_sorted(t_stack_node *a);

// Math operations
int				find_mean(t_stack_node *head);
long			ft_atol(const char *nptr);
t_stack_node	*get_min(t_stack_node *head);
t_stack_node	*get_max(t_stack_node *head);

// Movements
t_stack_node	**swap_movement(t_stack_node **head);
int				sa(t_stack_node **a);
int				sb(t_stack_node **b);
int				ss(t_stack_node **a, t_stack_node **b);
t_stack_node	**rotate_movement(t_stack_node **head);
int				ra(t_stack_node **a);
int				rb(t_stack_node **b);
int				rr(t_stack_node **a, t_stack_node **b);
t_stack_node	**rev_rotate_movement(t_stack_node **head);
int				rra(t_stack_node **a);
int				rrb(t_stack_node **b);
int				rrr(t_stack_node **a, t_stack_node **b);
int				push_movement(t_stack_node **a_head, t_stack_node **b_head);
int				pa(t_stack_node **a, t_stack_node **b);
int				pb(t_stack_node **a, t_stack_node **b);

#endif
