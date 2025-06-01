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
}

t_stack	*closest_match_target(t_stack *a, int needed)
{
	t_stack	*curr_a;
	t_stack	*node;
	int		diff;
	int		curr_fp;
	int		curr_diff;

	node = NULL;
	curr_a = a;
	diff = INTMAX;
	while (curr_a)
	{
		curr_fp = curr_a->final_pos;
		curr_diff = curr_fp - needed;
		if ((curr_diff < diff)
			&& (curr_fp >= needed))
		{
			node = curr_a;
			diff = curr_diff;
		}
		curr_a = curr_a->next;
	}
	if (diff == INTMAX)
		node = lowest(a);
	return (node);
}

//get the target for a swap.. may not need only need to try this for the top value of A....

t_stack	*swap_target(t_stack *a, int needed)
{
	t_stack	*curr_a;
	t_stack	*node;
	int		diff;
	int		curr_fp;
	int		curr_diff;

	node = NULL;
	curr_a = a;
	diff = INTMAX;
	while (curr_a)
	{
		curr_fp = curr_a->final_pos;
		curr_diff = curr_fp - needed;
		if ((curr_diff < diff)
			&& (curr_fp <= needed))
		{
			node = curr_a;
			diff = curr_diff;
		}
		curr_a = curr_a->next;
	}
	if (diff == INTMAX)
		node = highest(a);
	return (node);
}

int	set_up_down(t_stack *a, t_stack *b, t_stack *target, t_stack *node)
{
	int	size_a;
	int	size_b;
	int	moves_up;
	int	moves_down;

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
	{
		node->return_cost = moves_up;
		return (node->direction = 1);
	}
	else
	{
		node->return_cost = moves_down;
		return (node->direction = -1);
	}
}

int	get_least_cost(t_stack *target, t_stack *node, t_stack *a, t_stack *b)
{
	int	opposite;
	int	up_down;

	opposite = target->cost + node->cost;
	set_up_down(a, b, target, node);
	up_down = node->return_cost;
	if (opposite + 1 < up_down)
	{
		node->direction = 0;
		return (opposite);
	}
	else
		return (up_down);
}

//orig
void	set_return_cost(t_stack *a, t_stack *b)
{
	t_stack	*curr_b;

	curr_b = b;
	while (curr_b)
	{
		curr_b->target = closest_match_target(a, curr_b->final_pos);
		curr_b->return_cost = get_least_cost(curr_b->target, curr_b, a, b);
		curr_b = curr_b->next;
	}
}

//version to try with swap_send

/* void	set_return_cost(t_stack *a, t_stack *b)
{
	t_stack	*curr_b;
	int		swap_cost;
	int		cost;

	curr_b = b;
	while (curr_b)
	{
		curr_b->target = closest_match_target(a, curr_b->final_pos);
		curr_b->swap_target = swap_target(a, curr_b->final_pos);
		cost = get_least_cost(curr_b->target, curr_b, a, b);
		swap_cost = get_least_cost(curr_b->swap_target, curr_b, a, b) + 1;
		//printf("--------------swaptarg_fp: %d  curr: %d\n" , curr_b->swap_target->final_pos, curr_b->final_pos);
		if (swap_cost <= cost)
		{
			curr_b->return_cost = swap_cost;
			curr_b->use_swap = true;
		}
		else
		{
			curr_b->return_cost = get_least_cost(curr_b->target, curr_b, a, b);
			curr_b->use_swap = false;
		}
		curr_b = curr_b->next;
	}
} */

//now with top swap target
/* void	set_return_cost(t_stack *a, t_stack *b)
{
	t_stack	*curr_b;

	curr_b = b;
	curr_b->swap_target = swap_target(a, curr_b->final_pos);
	if (a == curr_b->swap_target && b->next && b->next->final_pos > b->final_pos)
	{
		curr_b->return_cost = 1;
		curr_b->use_swap = true;
		curr_b = curr_b->next;
	}
	else
		curr_b->use_swap = false;
	while (curr_b)
	{
		curr_b->target = closest_match_target(a, curr_b->final_pos);
		curr_b->return_cost = get_least_cost(curr_b->target, curr_b, a, b);
		curr_b = curr_b->next;
	}
	
} */

