/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:20:13 by jbrandt           #+#    #+#             */
/*   Updated: 2024/12/11 12:49:48 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->over_median = true;
		else
			stack->over_median = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_fit;

	while (a)
	{
		best_fit = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr \
				&& current_b->nbr > best_fit)
			{
				best_fit = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_fit == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	finding_cost_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->over_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->over_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_lowest_cost(t_stack_node *stack)
{
	long			low_cost_value;
	t_stack_node	*low_cost_node;

	if (!stack)
		return ;
	low_cost_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < low_cost_value)
		{
			low_cost_value = stack->push_cost;
			low_cost_node = stack;
		}
		stack = stack->next;
	}
	low_cost_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	finding_cost_a(a, b);
	set_lowest_cost(a);
}
