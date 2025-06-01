/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:43:39 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:43:42 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves = 0;

static void	harmony_ops(t_stack **a, t_stack **b, int set_mid, int top_lim)
{
	t_stack	*next_node;
	t_stack *b_next;
	int		topb_fp;
	int		bnext_fp;

	next_node = get_cheapest_2(*a, top_lim);
	b_next = (*b)->next;
	topb_fp = (*b)->final_pos;
	if (b_next)
	{
		bnext_fp = b_next->final_pos;
		if (next_node && next_node->curr_pos == 1
			&& (topb_fp + 1 == bnext_fp))
			ss(a, b, 0);
		else if (next_node && (topb_fp < set_mid)
			&& next_node->curr_pos != 0 && next_node->above_mid
			&& bnext_fp >= set_mid)
			rr(a, b, 0);
		else if (topb_fp < set_mid && bnext_fp >= set_mid)
			rb(b, 0);
	}
}
//leave largest cyclic sorted set, presort those going to B

static void	harmony_sort(t_stack **a, t_stack **b, int num_blocks, int num)
{
	t_stack	*node;
	int		i;
	int		j;

	j = 0;
	while (++j < num_blocks + 1)
	{
		i = -1;
		while (++i < num - 1)
		{
			node = get_cheapest_2(*a, num * j);
			if (node == NULL)
				break ;
			move_to_top_a(a, node);
			pb(b, a, 0);
			harmony_ops(a, b, num * (j - 1) + num / 2, num * j);
		}
	}
}

static void	sort_500_ops(t_stack **a, t_stack **b, int top_lim, int set_mid)
{
	t_stack	*next_node;
	t_stack *b_next;
	int		topb_fp;
	int		bnext_fp;

	move_to_top_a(a, get_cheapest(*a, top_lim));
	pb(b, a, 0);
	b_next = (*b)->next;
	topb_fp = (*b)->final_pos;
	next_node = get_cheapest(*a, top_lim);
	if (b_next)
	{
		bnext_fp = b_next->final_pos;
		if (next_node && next_node->curr_pos == 1 && (topb_fp + 1 == bnext_fp))
			ss(a, b, 0);
		else if (next_node && (topb_fp < set_mid) && next_node->curr_pos != 0 
			&& next_node->above_mid && bnext_fp >= set_mid)
			rr(a, b, 0);
		else if (topb_fp < set_mid && bnext_fp >= set_mid)
			rb(b, 0);
		}
}

// recursively send blocks of numbers to stack b while a is larger than lim
// first does 1/2 of orig size, then 1/3 of orig size
// then recurs with the new current size, 1/2, 1/3, ... until 9 remain
// troubshoot: printf("----num_p: %d\n---num:  %d\n\n", num_prev, num);

static void	sort_500(t_stack **a, t_stack **b, int num_prev, int len)
{
	int	i;
	int	num;
	int	num_blocks;
	int	len_start;
	int lim = 10;

	if (len < lim || *a == NULL)
		return ;
	num_blocks = 2;
	len_start = len;
	while (num_blocks < 4 && len >= lim)
	{
		i = -1;
		num = len_start / num_blocks;
		while (++i < num && len-- >= lim)
			sort_500_ops(a, b, num_prev + num, num_prev + num / 2);
		num_blocks++;
		num_prev += num;
	}
	sort_500(a, b, num_prev, len);
	return ;
}

void	push_swap(t_stack **a, t_stack **b, int len)
{
	if (is_cyclic_sorted(*a))
	{
		cycle(a);
		return ;
	}
	else if (len >= 4 && len < 10)
		sort_small(a, b);
	else if (len > 9 && len <= 210)
	{
		get_biggest_cyclic(*a, 0, 0);
		if (len == 100)
			harmony_sort(a, b, 4, 77);
		else
			harmony_sort(a, b, 4, 3 * len / 4 + 3);
		take_it_home(a, b);
	}
	else
	{
		sort_500(a, b, 0, len);
		sort_now(a, b);
		if (len == 500)
			take_it_home_500(a, b);
		else
			take_it_home(a, b);
	}
}


