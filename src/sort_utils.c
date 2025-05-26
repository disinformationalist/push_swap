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

void	sort_3(t_lists *all, t_stack *stack)
{
	t_stack	*high;

	high = highest(stack);
	if (stack == high)
		ra(all, 0);
	else if (stack->next == high)
		rra(all, 0);
	if (all->a->content > all->a->next->content)
		sa(all, 0);
}

//sorts between 4 and 9

void	sort_small(t_lists *all, t_stack *a)
{
	int	len;

	len = ft_size(a) + 1;
	while (--len > 3)
	{
		if (is_sorted(all->a) || is_cyclic_sorted(all->a))
			break ;
		if (swap_test(all, 0))
			break;
		if (len >= 5)
			if (rasararasara(all) || sararasararasa(all) 
				|| pbpbssparrapara(all) || rapbpbsbrapapa(all) 
				|| rrapbrrarrasapara(all))
				break;
		pb(all, 0);
	}
	if (len == 3 && !is_sorted(all->a) && !is_cyclic_sorted(all->a))
		sort_3(all, all->a);
	take_it_home(all);
	cycle(all);
}

//get lowest, move it to b, contiue until 3 left, sorts 3, moves all back to a 
//good only for small stacks, leaves sorted or cyclic sorted

void	sort_now(t_lists *all, t_stack *a)
{
	int	count;
	int	len;

	count = 0;
	len = ft_size(a) + 1;
	while (--len > 3)
	{
		if (is_sorted(all->a) || is_cyclic_sorted(all->a))
			return ;
		/* if (swap_test(all, 0))
			return; */
		move_to_top_a(all, lowest(all->a));
		pb(all, 0);
		count++;
	}
	sort_3(all, all->a);
	while (count)
	{
		pa(all, 0);
		count--;
	}
}
