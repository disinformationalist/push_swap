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

void	ra(t_stack **a, int checker)
{
	rotate(a);
	if (!checker)
	{
		write(1, "ra\n", 3);
		moves++;
	}
}

void	rb(t_stack **b, int checker)
{
	rotate(b);
	if (!checker)
	{
		write(1, "rb\n", 3);
		moves++;
	}
}

void	rr(t_stack **a, t_stack **b, int checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
	{
		write(1, "rr\n", 3);
		moves++;
	}
}
