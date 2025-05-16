/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:42:25 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:42:27 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cycle(t_stack **a)
{
	t_stack	*curr_a;
	t_stack	*node;
	int		rot;

	curr_a = *a;
	while (curr_a)
	{
		if (curr_a->final_pos == 0)
			node = curr_a;
		curr_a = curr_a->next;
	}
	set_curr_pos_cost(*a);
	rot = node->cost + 1;
	if (node->above_mid)
		while (--rot)
			ra(a, 0);
	else
		while (--rot)
			rra(a, 0);
}

static void	reverse_loops(t_stack **a, t_stack **b, int start, int end)
{
	t_stack	*node_to_return;
	t_stack	*target;
	int		i;
	int		j;
	int		size;

	size = end - start + 1;
	j = -1;
	while (++j < 2)
	{
		i = -1;
		while (++i < size)
		{
			set_curr_pos_cost(*a);
			set_curr_pos_cost(*b);
			set_return_cost(*a, *b);
			node_to_return = get_cheapest_return_interval(*b, start, end);
			target = closest_match_target(*a, node_to_return->final_pos);
			take_route(a, b, target, node_to_return);
		}
		start -= size;
		end -= size;
	}
}

void	take_it_home_500(t_stack **a, t_stack **b)
{
	t_stack	*node_to_return;
	t_stack	*target;
	int		i;

	i = -1;
	while (++i < 5)
	{
		set_curr_pos_cost(*a);
		set_curr_pos_cost(*b);
		set_return_cost(*a, *b);
		node_to_return = get_cheapest_return_interval(*b, 486, 499);
		target = closest_match_target(*a, node_to_return->final_pos);
		take_route(a, b, target, node_to_return);
	}
	reverse_loops(a, b, 472, 485);
	reverse_loops(a, b, 437, 457);
	reverse_loops(a, b, 333, 415);
	reverse_loops(a, b, 125, 249);
	cycle(a);
}

void	take_it_home(t_stack **a, t_stack **b)
{
	t_stack	*node_to_return;
	t_stack	*target;

	while (*b)
	{
		set_curr_pos_cost(*a);
		set_curr_pos_cost(*b);
		set_return_cost(*a, *b);
		node_to_return = get_cheapest_return(*b);
		target = closest_match_target(*a, node_to_return->final_pos);
		take_route(a, b, target, node_to_return);
	}
	cycle(a);
}
