/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:33:13 by srudman           #+#    #+#             */
/*   Updated: 2023/11/25 20:10:53 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// handle errors: integre overflow, dubplicates, syntax errors (+, -)
// if it's string, convert it into long integer
// append the nodes to stack 'a'
// run a check if stack 'a' is sorted, if it's not sorted, implement our
// sorting algoritm
// ALGORITM
// Check for 2 numbers, if yes. Simply swap the numbers.
// Check for 3 numbers, if so implement our simple 'sort three' algorithm.
// check if stack has more than 3 numbers, implement our Turk Algorithm.
//

t_stack_node	*stack_init(t_stack_node *a, int stack_len, char **nptr)
{	
	long tmp;
	
	tmp = 0; // do I have to initialise it?
	while (stack_len--)
	{
		// write function to handle syntax errors
		if (syntax_error(*nptr++)) // nptr++ or *nptr++, learn this shit
			return (NULL);
		tmp = ft_atol(nptr);
		/* If ft_atol returns 0, your code currently returns NULL. 
		This might be misleading because returning NULL typically 
		indicates a failure related to memory allocation, not 
		necessarily a failure in parsing the input. Consider using 
		a different return value or a separate variable to indicate 
		parsing failure. */
		if (!tmp || tmp < INT_MIN || tmp > INT_MAX)
			return (NULL);
		// can a 0 be an input? If yes, then fuck.
		ft_nodeadd_back(&a, (ft_nodenew((int) tmp)));
		// run a check or duplicates
	}
	return (a);
}
