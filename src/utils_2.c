/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:45:30 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:45:34 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_curr_pos(t_stack *stack, t_stack *node)
{
	int	curr_pos;

	curr_pos = 0;
	while (stack != node)
	{
		stack = stack->next;
		curr_pos++;
	}
	return (curr_pos);
}

void	set_curr_pos_cost(t_stack *stack)
{
	int	i;
	int	size;
	int	center;

	i = 0;
	size = ft_size(stack);
	center = size / 2;
	while (stack)
	{
		stack->curr_pos = i;
		if (i <= center)
		{
			stack->cost = i;
			stack->above_mid = 1;
		}
		else if (i > center)
		{
			stack->cost = size - i;
			stack->above_mid = 0;
		}
		stack = stack->next;
		i++;
	}
}

/* void	move_to_top_a(t_stack **a, t_stack **b, t_stack *node)
{
	int	i;
	int	pos;
	int	size;
	int	center;

	if (!node)
		return ;
	i = -1;
	pos = get_curr_pos(*a, node);
	size = ft_size(*a);
	center = size / 2;
	if (pos <= center)
	{
		while (++i < pos)
			ra(a, 0);
	}
	else if (pos > center)
	{
		if ((*b) && (*b)->next && ft_last(*b)->final_pos == (*b)->final_pos + 1)
		{
			rrr(a, b, 0);
			pos--;
		}
		while (++i < size - pos)
			rra(a, 0);
	}
} */

void	move_to_top_a(t_stack **a, t_stack *node)
{
	int	i;
	int	pos;
	int	size;
	int	center;

	if (!node)
		return ;
	i = -1;
	pos = get_curr_pos(*a, node);
	size = ft_size(*a);
	center = size / 2;
	if (pos <= center)
	{
		while (++i < pos)
			ra(a, 0);
	}
	else if (pos > center)
	{
		while (++i < size - pos)
			rra(a, 0);
	}
}

t_stack *get_2nd_cheapest(t_stack *stack, int num, t_stack *cheapest)
{
	t_stack	*cheapest2;
	int		n;
	int		cost;

	n = INTMAX;
	cheapest2 = NULL;
	while (stack)
	{
		cost = stack->cost;
		if (cost < n && stack->final_pos < num && stack != cheapest 
			&& (stack->above_mid || cost == 1))
		{
			n = cost;
			cheapest2 = stack;
		}
		stack = stack->next;
	}
	return (cheapest2);
}

t_stack	*get_cheapest(t_stack *stack, int num)
{
	int		n;
	t_stack	*cheapest;
	int		cost;

	if (stack == NULL)
		return (NULL);
	set_curr_pos_cost(stack);
	n = INTMAX;
	cheapest = NULL;
	while (stack)
	{
		cost = stack->cost;
		if (cost < n && stack->final_pos < num 
			&& (stack->above_mid || cost == 1))
		{
			n = cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}
