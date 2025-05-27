/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:42:48 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:42:51 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = ft_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_lists *all, int checker)
{
	rotate(&(all->a));
	if (!checker)
		add_move(all, "ra\n");
}

void	rb(t_lists *all, int checker)
{
	rotate(&(all->b));
	if (!checker)
		add_move(all, "rb\n");
}

void	rr(t_lists *all, int checker)
{
	rotate(&(all->a));
	rotate(&(all->b));
	if (!checker)
		add_move(all, "rr\n");
}
