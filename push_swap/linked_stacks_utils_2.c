/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_stacks_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:28:59 by srudman           #+#    #+#             */
/*   Updated: 2024/01/27 16:16:52 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Incorportate the PREVIOUS node address as well. */
/*
This is in the header file already.
typedef struct	s_stack_node
{
	int		value;
	int		position;
	struct s_stack_node *prev;
	struct s_stack_node *next;
	// more meta data missing
}				t_stack_node;
*/

void	ft_position_nbr(t_stack_node *first, int nbr)
{
	t_stack_node	*current;

	current = first;
	while (current != NULL)
	{
		current->position = nbr++;
		current = current->next;
	}
}

// TO DO, free the "target node" as wellif it's dynamically allocated
void	free_list(t_stack_node *head)
{
	t_stack_node	*current;
	t_stack_node	*buffer;

	current = head;
	while (current)
	{
		buffer = current->next;
		free(current);
		current = buffer;
	}
}

int	stack_is_sorted(t_stack_node *a)
{
	t_stack_node	*current;

	if (!a)
		return (0);
	current = a;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

/*
void print_stack(t_stack_node *head) {
    t_stack_node *current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

int main() {
    // Create a sample sorted stack
    t_stack_node *sorted_stack = malloc(sizeof(t_stack_node));
    sorted_stack->value = 1;
    sorted_stack->next = malloc(sizeof(t_stack_node));
    sorted_stack->next->value = 5;
    sorted_stack->next->next = malloc(sizeof(t_stack_node));
    sorted_stack->next->next->value = 3;
    sorted_stack->next->next->next = NULL;

    // Print the sorted stack
    printf("Sorted Stack:\n");
    print_stack(sorted_stack);

    // Check if the stack is sorted
    if (stack_is_sorted(sorted_stack)) {
        printf("The stack is sorted.\n");
    } else {
        printf("The stack is not sorted.\n");
    }

    // Free the allocated memory
    free_list(sorted_stack);

    return 0;
}

*/