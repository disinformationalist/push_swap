/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:43:09 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:43:12 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	route_1(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	int	rr_rots;
	int	a_rots;

	rr_rots = node->curr_pos;
	a_rots = target->curr_pos - node->curr_pos;
	while (rr_rots)
	{
		rr(a, b, 0);
		rr_rots--;
	}
	while (a_rots)
	{
		ra(a, 0);
		a_rots--;
	}
	pa(a, b, 0);
}

void	route_2(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	int	rr_rots;
	int	b_rots;

	rr_rots = target->curr_pos;
	b_rots = node->curr_pos - target->curr_pos;
	while (rr_rots)
	{
		rr(a, b, 0);
		rr_rots--;
	}
	while (b_rots)
	{
		rb(b, 0);
		b_rots--;
	}
	pa(a, b, 0);
}

void	route_3(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	int	rrr_rots;
	int	b_rots;

	rrr_rots = ft_size(*a) - target->curr_pos;
	b_rots = (ft_size(*b) - node->curr_pos) -(ft_size(*a) - target->curr_pos);
	while (rrr_rots)
	{
		rrr(a, b, 0);
		rrr_rots--;
	}
	while (b_rots)
	{
		rrb(b, 0);
		b_rots--;
	}
	pa(a, b, 0);
}

void	route_4(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	int	rrr_rots;
	int	a_rots;

	rrr_rots = ft_size(*b) - node->curr_pos;
	a_rots = (ft_size(*a) - target->curr_pos) - (ft_size(*b) - node->curr_pos);
	while (rrr_rots)
	{
		rrr(a, b, 0);
		rrr_rots--;
	}
	while (a_rots)
	{
		rra(a, 0);
		a_rots--;
	}
	pa(a, b, 0);
}

void	route_5(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	int	a_rots;
	int	b_rots;

	a_rots = target->cost;
	b_rots = node->cost;
	while (a_rots)
	{
		ra(a, 0);
		a_rots--;
	}
	while (b_rots)
	{
		rrb(b, 0);
		b_rots--;
	}
	pa(a, b, 0);
}
