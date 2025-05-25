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
	int		cheapest_return_val;

	b_curr = b;
	to_return = NULL;
	cheapest_return_val = INTMAX;
	while (b_curr)
	{
		if ((b_curr->final_pos >= start && b_curr->final_pos <= end)
			&& ((b_curr->return_cost < cheapest_return_val)
			|| (b_curr->return_cost == cheapest_return_val 
			&& b_curr->final_pos > to_return->final_pos)))
		{
			to_return = b_curr;
			cheapest_return_val = b_curr->return_cost;
		}
		b_curr = b_curr->next;
	}
	return (to_return);
}


/* t_stack	*get_2nd_cheapest_return(t_stack *b, t_stack *cheapest)
{
	t_stack	*to_return;
	t_stack	*b_curr;
	int		cheapest_return_val;

	b_curr = b;
	to_return = NULL;
	cheapest_return_val = INTMAX;
	while (b_curr)
	{
		if (((b_curr->return_cost < cheapest_return_val) 
			|| (b_curr->return_cost == cheapest_return_val 
			&& b_curr->final_pos > to_return->final_pos)) && b_curr != cheapest)
		{
			to_return = b_curr;
			cheapest_return_val = b_curr->return_cost;
		}
		b_curr = b_curr->next;
	}
	return (to_return);
}

t_stack	*get_cheapest_return(t_stack *b)
{
	t_stack	*cheapest;
	t_stack	*b_curr;
	int		cheapest_return_val;
	t_stack	*cheap2;

	set_curr_pos_cost(b);
	b_curr = b;
	cheapest = NULL;
	cheapest_return_val = INTMAX;
	while (b_curr)
	{
		if ((b_curr->return_cost < cheapest_return_val) 
			|| (b_curr->return_cost == cheapest_return_val 
			&& b_curr->final_pos > cheapest->final_pos))
		{
			cheapest = b_curr;
			cheapest_return_val = b_curr->return_cost;
		}
		b_curr = b_curr->next;
	}
	cheap2 = get_2nd_cheapest_return(b, cheapest);
	if (cheap2 && !cheapest->above_mid && cheap2->cost < cheapest->cost + 2)
		return (cheap2);
	else
		return (cheapest);
}
 */

// delivers the node with the cheapest return to stack A

t_stack	*get_cheapest_return(t_stack *b)
{
	t_stack	*to_return;
	t_stack	*b_curr;
	int		cheapest_return_val;

	b_curr = b;
	to_return = NULL;
	cheapest_return_val = INTMAX;
	while (b_curr)
	{
		if ((b_curr->return_cost < cheapest_return_val) 
			|| (b_curr->return_cost == cheapest_return_val 
			&& b_curr->final_pos > to_return->final_pos))
		{
			to_return = b_curr;
			cheapest_return_val = b_curr->return_cost;
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
