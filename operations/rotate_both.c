/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:56:19 by jbrandt           #+#    #+#             */
/*   Updated: 2024/12/11 11:37:59 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_both(t_stack_node **a,
						t_stack_node **b, t_stack_node *low_cost_node)
{
	while (*b != low_cost_node->target_node
		&& *a != low_cost_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack_node **a,
							t_stack_node **b, t_stack_node *low_cost_node)
{
	while (*b != low_cost_node->target_node
		&& *a != low_cost_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}
