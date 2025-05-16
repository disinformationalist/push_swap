/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harmony_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:39:48 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:40:00 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_leave(t_stack *stack)
{
	while (stack)
	{
		stack->leave = 0;
		stack = stack->next;
	}
}

static t_stack	*get_st(t_stack *stack, int st)
{
	t_stack	*node;

	node = NULL;
	while (stack)
	{
		if (stack->final_pos == st)
			node = stack;
		stack = stack->next;
	}
	return (node);
}

static t_stack	*cyc_2(t_stack *a, t_stack *curr, t_stack *nxt_st, t_stack *st)
{
	if (nxt_st == NULL)
	{
		if (!curr)
			curr = a;
	}
	else
	{
		st = nxt_st;
		nxt_st->leave = 1;
		if (!curr)
			curr = a;
		else
			curr = st->next;
	}
	return (curr);
}

static void	create_cyc(t_stack *a, t_stack *st, int limit, int chk_ahead)
{
	t_params	par;

	st->leave = 1;
	par.curr = st->next;
	while (1)
	{
		par.i = -1;
		par.min_diff = ft_size(a) / limit;
		par.nxt_st = NULL;
		while (++par.i < chk_ahead && par.curr && par.curr->final_pos != 0)
		{
			if (par.curr->final_pos - st->final_pos < par.min_diff
				&& par.curr->final_pos >= st->final_pos)
			{
				par.nxt_st = par.curr;
				par.min_diff = par.curr->final_pos - st->final_pos;
			}
			par.curr = par.curr->next;
		}
		if (par.curr != NULL && par.curr->final_pos == 0)
			break ;
		par.curr = cyc_2(a, par.curr, par.nxt_st, st);
		if (par.nxt_st)
			st = par.nxt_st;
	}
}

void	get_biggest_cyclic(t_stack *a, int st, int biggest)
{
	int	i;
	int	j;
	int	max_i;
	int	max_j;
	int	size;

	i = 1;
	while (++i < 30)
	{
		j = 1;
		while (++j < 30)
		{
			create_cyc(a, get_st(a, st), i, j);
			size = leave_size(a);
			if (size > biggest)
			{
				biggest = size;
				max_i = i;
				max_j = j;
			}
			reset_leave(a);
		}
	}
	create_cyc(a, get_st(a, st), max_i, max_j);
}
