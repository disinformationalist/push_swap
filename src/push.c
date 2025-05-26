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

void	pa(t_lists *all, int checker)
{
	push(&(all->a), &(all->b));
	if (!checker)
		add_move(all, "pa\n");
}

void	pb(t_lists *all, int checker)
{
	push(&(all->b), &(all->a));
	if (!checker)
		add_move(all, "pb\n");
}

