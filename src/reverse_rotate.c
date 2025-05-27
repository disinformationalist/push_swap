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

void	rra(t_lists *all, int checker)
{
	reverse_rotate(&(all->a));
	if (!checker)
		add_move(all, "rra\n");
}

void	rrb(t_lists *all, int checker)
{
	reverse_rotate(&(all->b));
	if (!checker)
		add_move(all, "rrb\n");
}

void	rrr(t_lists *all, int checker)
{
	reverse_rotate(&(all->a));
	reverse_rotate(&(all->b));
	if (!checker)
		add_move(all, "rrr\n");
}
