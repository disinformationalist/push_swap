/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:42:33 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:42:37 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!(*stack) || !((*stack)->next))
		return ;
	last = ft_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **a, int checker)
{
	reverse_rotate(a);
	if (!checker)
	{
		write(1, "rra\n", 4);
		moves++;
	}
}

void	rrb(t_stack **b, int checker)
{
	reverse_rotate(b);
	if (!checker)
	{
		write(1, "rrb\n", 4);
		moves++;
	}
}

void	rrr(t_stack **a, t_stack **b, int checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
	{
		write(1, "rrr\n", 4);
		moves++;
	}
}
