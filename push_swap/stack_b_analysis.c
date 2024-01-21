/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:01:54 by srudman           #+#    #+#             */
/*   Updated: 2024/01/21 20:17:16 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Every B needs a ´closest larger nbr to B' from stack A. 
A has to have a larger number to B when we push it.
If A is smaller to B, then the 'closes smaller number to A' is the max_value in B.
Every A node is assigned a ´closest smallest number to A´
*/

t_stack_node    *set_target_b(t_stack_node **a, t_stack_node **b)
{
    long            tmp_best_match;
    t_stack_node    *current_a;
    t_stack_node    *current_b;
    t_stack_node    *target_node;

    current_b = *b;
    while (current_b)
    {
        tmp_best_match = LONG_MAX;
        current_a = *a;
        target_node = NULL;
        while (current_a)
        {
            if (current_a->value > current_b->value 
                && current_a->value < tmp_best_match)
            {
                tmp_best_match = current_a->value;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (tmp_best_match == LONG_MAX)
            current_b->target = get_min(*a);
        else 
            current_b->target = target_node;
        current_b = current_b->next;
    }
    return (*b);
}

/*
// Main to test out set_target
void print_list(t_stack_node *head)
{
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void print_stack(t_stack_node *head)
{
    while (head)
    {
        printf("%d and target %d; ", head->value, head->target->value);
        head = head->next;
    }>
    t_stack_node node3 = {7, 3, 0, false, NULL, &node2, NULL};
    t_stack_node node4 = {5, 4, 0, false, NULL, &node3, NULL};
    t_stack_node nodeb1 = {1, 1, 0, false, NULL, NULL, NULL}1;
    t_stack_node nodeb2 = {6, 2, 0, false, NULL, &nodeb1, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    nodeb1.next = &nodeb2;

    t_stack_node *a = &node1;
    t_stack_node *b = &nodeb1;

    printf("Original List A: ");
    print_list(a);

    printf("List B: ");
    print_list(b);1

    t_stack_node *modifiedListA = set_target(&a, &b);

    printf("Modified List A: ");
    print_stack(modifiedListA);

    return 0;
}

*/