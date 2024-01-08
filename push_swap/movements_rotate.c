/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:53:14 by srudman           #+#    #+#             */
/*   Updated: 2023/12/28 15:25:20 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// typedef struct	s_stack_node
// {
// 	int		value;
// 	int		position;
// 	struct s_stack_node *prev;
// 	struct s_stack_node *next;
// 	// more meta data missing
// }				t_stack_node;

int				ft_stacksize(t_stack_node *first);
void			ft_position_nbr(t_stack_node *first, int nbr);
t_stack_node	*ft_nodelast(t_stack_node *first);

// Should I also check if the len of stack is higher than 1?
// TO DO: protections needed
t_stack_node	**rotate_movement(t_stack_node **head)
{
	if (head == NULL || (*head) == NULL || (*head)->next == NULL)
		return(NULL);
    (*head)->position = ft_stacksize(*head);
    ft_position_nbr((*head)->next, 1);
    (*head)->prev = (ft_nodelast(*head));
    (*head)->next->prev = NULL;
    (ft_nodelast(*head))->next = *head;
    (*head)->next = NULL;
    while ((*head)->prev)
        (*head) = (*head)->prev;
    return (head);
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

int ra(t_stack_node **a)
{
	if (rotate_movement(a))
	{
 		write(1, "ra\n", 3);
		return (1);
	}
	return (0);
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

int rb(t_stack_node **b)
{
	b = rotate_movement(b);
	if (b)
	{
 		write(1, "rb\n", 3);
		return (1);
	}
	return (0);
}

// rr : ra and rb at the same time.

int rr(t_stack_node **a, t_stack_node **b)
{
	a = rotate_movement(a);
	b = rotate_movement(b);
	if (a && b)
	{
 		write(1, "rr\n", 3);
		return (1);
	}
	return (0);
}

/*
void print_stack(t_stack_node *head)
{
    while (head != NULL)
    {
        printf("Value: %d, Pos.: %d\n", head->value, head->position);
        head = head->next;
    }
    printf("\n");
}


int main() {
    // I add 4 nodes
    t_stack_node *stack = malloc(sizeof(t_stack_node));
    stack->value = 3;
    stack->position = 1;
    stack->prev = NULL;

    t_stack_node *node2 = malloc(sizeof(t_stack_node));
    node2->value = 6;
    node2->position = 2;
    node2->prev = stack;
    node2->next = NULL;
    stack->next = node2;

    t_stack_node *node3 = malloc(sizeof(t_stack_node));
    node3->value = 9;
    node3->position = 3;
    node3->prev = node2;
    node3->next = NULL;
    node2->next = node3;

    t_stack_node *node4 = malloc(sizeof(t_stack_node));
    node4->value = 12;
    node4->position = 4;
    node4->prev = node3;
    node4->next = NULL;
    node3->next = node4;

    // Print the original stack
    printf("Original Stack: \n");
    print_stack(stack);

    // Apply ra function
    ra(&stack);

    // Print the modified stack
    printf("Modified Stack: \n");
    print_stack(stack);

    // Free the allocated memory for the stack
    free_list(stack);
    return 0;
}
*/