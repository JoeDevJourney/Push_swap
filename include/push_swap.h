/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:21:42 by jbrandt           #+#    #+#             */
/*   Updated: 2024/12/11 11:38:26 by jbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				over_median;
	bool				under_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				main(int argc, char **argv);
// all operations
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			rotate_both(t_stack_node **a, \
				t_stack_node **b, t_stack_node *low_cost_node);
void			rev_rotate_both(t_stack_node **a, \
				t_stack_node **b, t_stack_node *low_cost_node);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
// algorithm
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
// stack util
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
// initiation nodes
void			current_index(t_stack_node *stack);
void			set_lowest_cost(t_stack_node *stack);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
t_stack_node	*get_lowest_cost(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack, t_stack_node *top_node, \
				char stack_name);
// iniating stack
void			init_stack_a(t_stack_node **a, char **argv);
char			**split(char *s, char c);
// error handling
int				error_syntax(char *str);
int				error_duplicate(t_stack_node *a, int n);
void			free_stacks(t_stack_node **stack);
void			free_errors(t_stack_node **a);

#endif