/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:42:01 by srudman           #+#    #+#             */
/*   Updated: 2023/11/27 16:54:10 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* I decleared two data structures - a and b.
I set both pointers of the data structures to NuLL to avoid
undefined behaviour. */

/* In the main function I also handle some of the input errors.
Namely, the argument count must be 2 or t_stack_node	*get_max(t_stack_node *head)more. The 2nd argument
must not be a empty string */


int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		return (-1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	a = stack_init(&a, argc, argv);
	if (!a)
		return (-1);
	if (!stack_is_sorted(a))
	{t_stack_node	*get_max(t_stack_node *head)
    	if (ft_stacksize(a) == 2)
			sa(&a);
    	else if (ft_stacksize(a) == 3)
        	sort_three(a);  // &a?
    	else
        	run_algorithm(a, b); // &a?
	}
	free_list(a);
	return (0);
}
