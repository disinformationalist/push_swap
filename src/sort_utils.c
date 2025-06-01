/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:43:53 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:43:56 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if only rotation is needed to sort the current stack

int	is_cyclic_sorted(t_stack *stack)
{
	t_stack	*rot_loc;
	t_stack	*start;

	if (!stack)
		return (0);
	rot_loc = NULL;
	start = stack;
	while ((stack)->next)
	{
		if (stack->content > stack->next->content)
		{
			rot_loc = stack;
			stack = stack->next;
			break ;
		}
		stack = stack->next;
	}
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (rot_loc == highest(start)
		&& ft_last(start)->content < start->content);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_3(t_stack **stack)
{
	t_stack	*high;

	high = highest(*stack);
	if (*stack == high)
		ra(stack, 0);
	else if ((*stack)->next == high)
		rra(stack, 0);
	if ((*stack)->content > (*stack)->next->content)
		sa(stack, 0);
}

//sorts between 4 and 9

void	sort_small(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_size(*a) + 1;
	while (--len > 3)
	{
		if (is_sorted(*a) || is_cyclic_sorted(*a))
			break ;
		if (swap_test(a, b, 0))
			break;
		if (len >= 5)
			if (rasararasara(a) || sararasararasa(a) 
				|| pbpbssparrapara(a, b) || rapbpbsbrapapa(a, b) 
				|| rrapbrrarrasapara(a, b))
				break;
		pb(b, a, 0);
	}
	if (len == 3 && !is_sorted(*a) && !is_cyclic_sorted(*a))
		sort_3(a);
	take_it_home(a, b);
	cycle(a);
}

//get lowest, move it to b, contiue until 3 left, sorts 3, moves all back to a 
//good only for small stacks, leaves sorted or cyclic sorted

void	sort_now(t_stack **a, t_stack **b)
{
	int	count;
	int	len;

	count = 0;
	len = ft_size(*a) + 1;
	while (--len > 3)
	{
		if (is_sorted(*a) || is_cyclic_sorted(*a))
			return ;
		/* if (swap_test(a, b, 0))
			return; */
		move_to_top_a(a, lowest(*a));
		pb(b, a, 0);
		count++;
	}
	sort_3(a);
	while (count)
	{
		pa(a, b, 0);
		count--;
	}
}
