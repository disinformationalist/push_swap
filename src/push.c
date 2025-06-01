/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:41:38 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:41:41 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **to, t_stack **from)
{
	t_stack	*node;

	if (*from == NULL)
		return ;
	node = *from;
	*from = node->next;
	if (*from)
		(*from)->prev = NULL;
	if (*to == NULL)
	{
		*to = node;
		(*to)->next = NULL;
	}
	else
	{
		(*to)->prev = node;
		node->next = *to;
		*to = node;
	}
}

void	pa(t_stack **a, t_stack **b, int checker)
{
	push(a, b);
	if (!checker)
	{
		write(1, "pa\n", 3);
		moves++;
	}
}

void	pb(t_stack **b, t_stack **a, int checker)
{
	push(b, a);
	if (!checker)
	{
		write(1, "pb\n", 3);
		moves++;
	}
}
