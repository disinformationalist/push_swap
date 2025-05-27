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

//try, when rra on send over, is lastb_fp == topb_fp + 1? if so rrr to build consecutive

static void	harmony_ops(t_lists *all, int set_mid, int top_lim)
{
	t_stack	*next_node;
	t_stack *b_next;
	int		topb_fp;
	int		bnext_fp;

	next_node = get_cheapest_2(all->a, top_lim);
	b_next = (all->b)->next;
	topb_fp = (all->b)->final_pos;
	if (b_next)
	{
		bnext_fp = b_next->final_pos;
		//t_stack *b_last = ft_last(*b);

		
		/* if (next_node && ft_last(*b)->final_pos == topb_fp + 1 && !next_node->above_mid)
			rrr(a, b, 0); */
		/* if (next_node && next_node->cost > 1 && bnext_fp + 1 == topb_fp && bnext_fp < set_mid && topb_fp < set_mid)
		{
			rr(a, b, 0);
			rr(a, b, 0);
		} */
		/* else if (bnext_fp + 1 == topb_fp)//trying consecutives..., if both are bot half, and 2 or more for next_node, do rr rr?
			return ; */
		if (next_node && next_node->curr_pos == 1
			&& (topb_fp + 1 == bnext_fp))
			ss(all, 0);
		else if (next_node && (topb_fp < set_mid)
			&& next_node->curr_pos != 0 && next_node->above_mid
			&& bnext_fp >= set_mid)
			rr(all, 0);
		else if (topb_fp < set_mid && bnext_fp >= set_mid)
			rb(all, 0);
	}
}
//leave largest cyclic sorted set, presort those going to B

static void	harmony_sort(t_lists *all, int num_blocks, int num)
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
			node = get_cheapest_2(all->a, num * j);
			if (node == NULL)
				break ;
			move_to_top_a(all, node);
			pb(all, 0);
			harmony_ops(all, num * (j - 1) + num / 2, num * j);
		}
	}
}

static void	sort_500_ops(t_lists *all, int top_lim, int set_mid)
{
	t_stack	*next_node;
	t_stack *b_next;
	int		topb_fp;
	int		bnext_fp;

	move_to_top_a(all, get_cheapest(all->a, top_lim));
	pb(all, 0);
	b_next = (all->b)->next;
	topb_fp = (all->b)->final_pos;
	next_node = get_cheapest(all->a, top_lim);
	if (b_next)
	{
		bnext_fp = b_next->final_pos;
		/* if (next_node && ft_last(*b)->final_pos == topb_fp + 1 && !next_node->above_mid)
			rrr(a, b, 0);
		else if (next_node && next_node->cost > 1 && bnext_fp + 1 == topb_fp && bnext_fp < set_mid && topb_fp < set_mid)
		{
			rr(a, b, 0);
			rr(a, b, 0);
		}
		else if (bnext_fp + 1 == topb_fp)//trying consecutives..., if both are bot half, and 2 or more for next_node, do rr rr?
			return ; */
		if (next_node && next_node->curr_pos == 1 && (topb_fp + 1 == bnext_fp))
			ss(all, 0);
		else if (next_node && (topb_fp < set_mid) && next_node->curr_pos != 0 
			&& next_node->above_mid && bnext_fp >= set_mid)
			rr(all, 0);
		else if (topb_fp < set_mid && bnext_fp >= set_mid)
			rb(all, 0);
	}
}

// recursively send blocks of numbers to stack b while a is larger than lim
// first does 1/2 of orig size, then 1/3 of orig size
// then recurs with the new current size, 1/2, 1/3, ... until 9 remain
// troubshoot: printf("----num_p: %d\n---num:  %d\n\n", num_prev, num);

static void	sort_500(t_lists *all, int num_prev, int len)
{
	int	i;
	int	num;
	int	num_blocks;
	int	len_start;
	int lim = 10;//85 for harm

	if (len < lim || all->a == NULL)
		return ;
	num_blocks = 2;
	len_start = len;
	while (num_blocks < 4 && len >= lim)
	{
		i = -1;
		num = len_start / num_blocks;
		while (++i < num && len >= lim)
		{
			sort_500_ops(all, num_prev + num, num_prev + num / 2);
			len--;
		}
		num_blocks++;
		num_prev += num;
	}
	sort_500(all, num_prev, len);
	return ;
}

static void	sort_500_2(t_lists *all, int num_prev, int len, int block)
{
	int	i;
	int	num;
	int	len_start;
	int lim = 10;//85 for harm

	if (len < lim || all->a == NULL)
		return ;
	len_start = len;
		i = -1;
		num = len_start / block;
		while (++i < num && len >= lim)
		{
			sort_500_ops(all, num_prev + num, num_prev + num / 2);
			len--;
		}
		num_prev += num;
	sort_500_2(all, num_prev, len, block);
	return ;
}

void	protect_lists(t_lists *all, t_lists *all2, t_lists *all3)
{
	free_all_list(all);
	if (all2)
		free_all_list(all2);
	if (all3)
		free_all_list(all3);
	ft_putstr_fd("lists malloc failure\n", 2);
	exit(EXIT_FAILURE);
}

//init 2nd and 3rd list 

void	init_lists(t_lists *all, t_lists **all2, t_lists **all3)
{
	(*all2) = (t_lists *)malloc(sizeof(t_lists));
	if (!(*all2))
		protect_lists(all, *all2, *all3);
	init_all(*all2);
	(*all2)->a = stack_copy(all->a);
	if (!(*all2)->a)
		protect_lists(all, *all2, *all3);
	(*all3) = (t_lists *)malloc(sizeof(t_lists));
	if (!(*all3))
		protect_lists(all, *all2, *all3);
	init_all(*all3);
	(*all3)->a = stack_copy(all->a);
	if (!(*all3)->a)
		protect_lists(all, *all2, *all3);
}

void	print_results(t_lists *all, t_lists *all2, t_lists *all3)
{
	if (all->count < all2->count)
	{
		if (all->count < all3->count)
			print_moves(all->buff);
		else
			print_moves(all3->buff);
	}
	else
	{
		if (all2->count < all3->count)
			print_moves(all2->buff);
		else
			print_moves(all3->buff);
	}
	printf("count1: %d   count2: %d   count3: %d\n", all->count, all2->count, all3->count);
}

void	paths_500(t_lists *all, int len)
{
	sort_now(all, all->a);
	if (len == 500)
		take_it_home_500(all);
	else
		take_it_home(all);
}


void	try_paths(t_lists *all, int len)
{
	t_lists	*all2;
	t_lists	*all3;
	
	all2 = NULL;
	all3 = NULL;
	init_lists(all, &all2, &all3);
	if (len <= 210)
	{
		harmony_sort(all, 4, 3 * len / 4 + 2);
		harmony_sort(all2, 4, 71);
		harmony_sort(all3, 10, 76);//71, 88, 92
		take_it_home(all);
		take_it_home(all2);
		take_it_home(all3);
	}
	else
	{
		sort_500(all, 0, len);
		sort_500_2(all2, 0, len, 3);
		sort_500_2(all3, 0, len, 2);
		sort_now(all2, all2->a);
		sort_now(all3, all3->a);

		/* harmony_sort(all2, 5, 130);
		harmony_sort(all3, 8, 300); */
		/* take_it_home(all);
		take_it_home(all2);
		take_it_home(all3); */
//		sort_500(all2, 0, len);
//		sort_500(all3, 0, len);
		paths_500(all, len);
		take_it_home(all2);
		take_it_home(all3); 
		/* paths_500(all2, len);
		paths_500(all3, len); */
	}
	print_results(all, all2, all3);
	free_all_list(all2);
	free_all_list(all3);
}



void	push_swap(t_lists *all, t_stack *a, int len)
{
	if (is_cyclic_sorted(a))
	{
		cycle(all);
		return ;
	}
	else if (len >= 4 && len < 10)
	{
		sort_small(all, a);
		print_moves(all->buff);
	}
	else if (len > 9 && len <= 210)
	{
		get_biggest_cyclic(all->a, 0, 0);
	//	printf("--------------size: %d\n", leave_size(all->a));
		try_paths(all, len);
	}
	else
	{
		try_paths(all, len);
		
	}
}
