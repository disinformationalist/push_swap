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

// delivers the node with the cheapest return to stack A, 
// when searching only through nodes with a final position
// within a given interval.

t_stack	*get_cheapest_return_interval(t_stack *b, int start, int end)
{
	t_stack	*to_return;
	t_stack	*b_curr;
	int		least_cost;
	int		cost;
	int		fp;

	b_curr = b;
	to_return = NULL;
	least_cost = INTMAX;
	while (b_curr)
	{
		cost = b_curr->return_cost;
		fp = b_curr->final_pos;
		if ((fp >= start && fp <= end) && ((cost < least_cost) 
		|| (cost == least_cost && fp > to_return->final_pos)))
		{
			to_return = b_curr;
			least_cost = cost;
		}
		b_curr = b_curr->next;
	}
	return (to_return);
}

// delivers the node with the cheapest return to stack A
// Ties are broken by choosing the largest final pos node

t_stack	*get_cheapest_return(t_stack *b)
{
	t_stack	*to_return;
	t_stack	*b_curr;
	int		least_cost;
	int		cost;

	b_curr = b;
	to_return = NULL;
	least_cost = INTMAX;
	while (b_curr)
	{
		cost = b_curr->return_cost;
		if ((cost < least_cost) || (cost == least_cost 
			&& b_curr->final_pos > to_return->final_pos))
		{
			to_return = b_curr;
			least_cost = cost;
		}
		b_curr = b_curr->next;
	}
	return (to_return);
}

//take the shortest up/down route: 1,2 ups : 3,4 downs

static void	take1234(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	if (node->direction == 1)
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

// up/down, or opposite directions

void	take_route(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	if (!node->direction)
	{
		if (target->above_mid)
			route_5(a, b, target, node);
		else if (node->above_mid)
			route_6(a, b, target, node);
	}
	else
		take1234(a, b, target, node);
	pa(a, b, 0);
}
