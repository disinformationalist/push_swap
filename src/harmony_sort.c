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

//gets node with given final position

static t_stack	*get_node(t_stack *stack, int fp)
{
	t_stack	*node;

	node = NULL;
	while (stack)
	{
		if (stack->final_pos == fp)
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
		while (++par.i < chk_ahead && par.curr && !par.curr->leave)
		{
			if (par.curr->final_pos - st->final_pos < par.min_diff
				&& par.curr->final_pos >= st->final_pos)
			{
				par.nxt_st = par.curr;
				par.min_diff = par.curr->final_pos - st->final_pos;
			}
			par.curr = par.curr->next;
		}
		if (par.curr != NULL && par.curr->leave)
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
			create_cyc(a, get_node(a, st), i, j);
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
	create_cyc(a, get_node(a, st), max_i, max_j);
}



//normal lis in prog to test
/* int	*stack_to_array(t_stack *stack, int len)
{
	int *tab;
	int	i;

	tab = (int *)malloc(len * sizeof(int));
	if (!tab)
	{
		free_stack(&stack);
		exit(1);
	}
	i = 0;
	while (stack)
	{
		tab[i++] = stack->content;
		stack = stack->next;
	}
	return (tab);
}

void	set_lis(t_stack **stack, int len)
{
	int 	*tails;
	int 	*prev;
	int		*tab;
	t_stack	*start;
	int 	i;
	int		t_len;

	i = -1;
	t_len = 1;
	tab = stack_to_array(*stack, len);
	set_curr_pos_cost(*stack);
	start = *stack;
	tails = (int *)malloc(sizeof(int) * len);
	if (!tails)
	{
		free_stack(stack);
		exit(1);
	}
	prev = (int *)malloc(sizeof(int) * len);
	if (!prev)
	{
		free(tails);
		free_stack(stack);
		exit(1);
	}
	while(++i < len)
		prev[i] = -1;
	i = -1;
	//start->leave = 1;
	tails[0] = 0;
	while (++i < len)
	{
		if (tab[i] < tab[tails[0]])//tails[0] holds index of smallest
			tails[0] = i;
		else if (tab[i] > tab[tails[t_len - 1]])//extend subsequence
		{
			prev[i] = tails[t_len - 1];
			tails[t_len++] = i;
		}
		else
		{
			int pos = get_index(tab, tails, 0, t_len - 1, tab[i]);
			tails[pos] = i;
			prev[i] = pos > 0? tails[pos - 1] : -1;
		}
	}
} */