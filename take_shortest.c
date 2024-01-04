/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_shortest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:44:21 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:44:24 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest_return_interval(t_stack *b, int start, int end)
{
	t_stack	*node;
	t_stack	*b_curr;
	int		cheapest_return_val;

	b_curr = b;
	node = NULL;
	cheapest_return_val = INTMAX;
	while (b_curr)
	{
		if (b_curr->return_cost < cheapest_return_val
			&& (b_curr->final_pos >= start && b_curr->final_pos <= end))
		{
			node = b_curr;
			cheapest_return_val = b_curr->return_cost;
		}
		b_curr = b_curr->next;
	}
	return (node);
}

t_stack	*get_cheapest_return(t_stack *b)
{
	t_stack	*node;
	t_stack	*b_curr;
	int		cheapest_return_val;

	b_curr = b;
	node = NULL;
	cheapest_return_val = INTMAX;
	while (b_curr)
	{
		if (b_curr->return_cost < cheapest_return_val)
		{
			node = b_curr;
			cheapest_return_val = b_curr->return_cost;
		}
		b_curr = b_curr->next;
	}
	return (node);
}

static void	take1234(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	if (take_help(*a, *b, target, node) == 1)
	{
		if (node->curr_pos <= target->curr_pos)
			route_1(a, b, target, node);
		else
			route_2(a, b, target, node);
	}
	else
	{
		if ((ft_size(*b) - node->curr_pos) >= (ft_size(*a) - target->curr_pos))
			route_3(a, b, target, node);
		else
			route_4(a, b, target, node);
	}
}

static void	take_5_6(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	if (target->above_mid)
		route_5(a, b, target, node);
	else if (node->above_mid)
		route_6(a, b, target, node);
}

void	take_route(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	int	first;
	int	second;

	first = target->cost + node->cost;
	if (take_help(*a, *b, target, node) == 1)
	{
		if (target->curr_pos >= node->curr_pos)
			second = target->curr_pos;
		else
			second = node->curr_pos;
	}
	else
	{
		if ((ft_size(*b) - node->curr_pos) >= ft_size(*a) - target->curr_pos)
			second = ft_size(*b) - node->curr_pos;
		else
			second = ft_size(*a) - target->curr_pos;
	}
	if (first < second)
		take_5_6(a, b, target, node);
	else
		take1234(a, b, target, node);
}
