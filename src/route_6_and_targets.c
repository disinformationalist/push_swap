/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_6_and_targets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:43:26 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:43:28 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	route_6(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	int	a_rots;
	int	b_rots;

	a_rots = target->cost;
	b_rots = node->cost;
	while (a_rots)
	{
		rra(a, 0);
		a_rots--;
	}
	while (b_rots)
	{
		rb(b, 0);
		b_rots--;
	}
	pa(a, b, 0);
}

t_stack	*closest_match_target(t_stack *a, int needed)
{
	t_stack	*curr_a;
	t_stack	*node;
	int		diff;

	node = NULL;
	curr_a = a;
	diff = INTMAX;
	while (curr_a)
	{
		if (((curr_a->final_pos - needed) < diff)
			&& (curr_a->final_pos >= needed))
		{
			node = curr_a;
			diff = curr_a->final_pos - needed;
		}
		curr_a = curr_a->next;
	}
	if (diff == INTMAX)
		node = lowest(a);
	return (node);
}

int	take_help(t_stack *a, t_stack *b, t_stack *target, t_stack *node)
{
	int	size_a;
	int	size_b;
	int	moves_up;
	int	moves_down;

	if (!a || !b ||!target ||!node)
		return (0);
	size_b = ft_size(b);
	size_a = ft_size(a);
	if (node->curr_pos >= target->curr_pos)
		moves_up = node->curr_pos;
	else
		moves_up = target->curr_pos;
	if (size_b - node->curr_pos >= size_a - target->curr_pos)
		moves_down = size_b - node->curr_pos;
	else
		moves_down = size_a - target->curr_pos;
	if (moves_up <= moves_down)
		return (1);
	else
		return (-1);
}

int	get_least_cost(t_stack *target, t_stack *node, t_stack *a, t_stack *b)
{
	int	first;
	int	second;

	first = target->cost + node->cost;
	if (take_help(a, b, target, node) == 1)
	{
		if (target->curr_pos >= node->curr_pos)
			second = target->curr_pos;
		else
			second = node->curr_pos;
	}
	else
	{
		if ((ft_size(b) - node->curr_pos) >= ft_size(a) - target->curr_pos)
			second = ft_size(b) - node->curr_pos;
		else
			second = ft_size(a) - target->curr_pos;
	}
	if (first < second)
		return (first);
	else
		return (second);
}

void	set_return_cost(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*curr_b;

	curr_b = b;
	while (curr_b)
	{
		target = closest_match_target(a, curr_b->final_pos);
		curr_b->return_cost = get_least_cost(target, curr_b, a, b);
		curr_b = curr_b->next;
	}
}
