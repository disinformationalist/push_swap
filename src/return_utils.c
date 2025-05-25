/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:42:25 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:42:27 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cycle(t_stack **a)
{
	t_stack	*curr_a;
	t_stack	*node;
	int		rot;

	curr_a = *a;
	while (curr_a)
	{
		if (curr_a->final_pos == 0)
			node = curr_a;
		curr_a = curr_a->next;
	}
	set_curr_pos_cost(*a);
	rot = node->cost + 1;
	if (node->above_mid)
		while (--rot)
			ra(a, 0);
	else
		while (--rot)
			rra(a, 0);
}

static void	reverse_loops(t_stack **a, t_stack **b, int end, int start)
{
	t_stack	*node_to_return;
	int		i;
	int		j;
	int		size;

	size = end - start + 1;
	j = -1;
	while (++j < 2)
	{
		i = -1;
		while (++i < size)
		{
			set_curr_pos_cost(*a);
			set_curr_pos_cost(*b);
			set_return_cost(*a, *b);
			node_to_return = get_cheapest_return_interval(*b, start, end);
			take_route(a, b, node_to_return->target, node_to_return);
		}
		start -= size;
		end -= size;
	}
}

void	take_it_home_500(t_stack **a, t_stack **b)
{
	t_stack	*node_to_return;
	int		i;
	int		len;
	//	while (++i < 5)
	//int len = 84 - ft_size(*a);
	i = -1;
	len = 14 - ft_size(*a);
	while (++i < len)
	{
		set_curr_pos_cost(*a);
		set_curr_pos_cost(*b);
		set_return_cost(*a, *b);
				node_to_return = get_cheapest_return_interval(*b, 486, 499);
		//node_to_return = get_cheapest_return_interval(*b, 416, 499);//harm
		take_route(a, b, node_to_return->target, node_to_return);
	}

	reverse_loops(a, b, 485, 472);
	reverse_loops(a, b, 457, 437);
	reverse_loops(a, b, 415, 333);//just these two with harm
	reverse_loops(a, b, 249, 125);//125);
	/* set_curr_pos_cost(*a);
	set_curr_pos_cost(*b);
	set_return_cost(*a, *b);
	if ((*b)->final_pos < (*b)->next->final_pos)
		node_to_return = *b;
	else
		node_to_return = (*b)->next;
	take_route(a, b, node_to_return->target, node_to_return);
	set_curr_pos_cost(*a);
	set_curr_pos_cost(*b);
	set_return_cost(*a, *b);
	node_to_return = *b;
	take_route(a, b, node_to_return->target, node_to_return); */
	//take_it_home(a, b);
	cycle(a);
}

//returns all remaining in B to correct place in A, rotates lowest to top

void	take_it_home(t_stack **a, t_stack **b)
{
	t_stack	*node_to_return;
	
	while (*b)
	{
		set_curr_pos_cost(*a);
		set_curr_pos_cost(*b);
		set_return_cost(*a, *b);
		node_to_return = get_cheapest_return(*b);
		take_route(a, b, node_to_return->target, node_to_return);
	}
	cycle(a);
}

//trying check on last 2 or 3 send, try with 3 and go from highest to lowest, maybe with entire last set for 500, or send back smallest last?
void	take_it_home_100(t_stack **a, t_stack **b)
{
/* 	t_stack	*node_to_return;
	int		i;

	i = -1;
	int len = ft_size(*b) - 2;
	while (++i < len)
	{
		set_curr_pos_cost(*a);
		set_curr_pos_cost(*b);
		set_return_cost(*a, *b);
		node_to_return = get_cheapest_return(*b);
		take_route(a, b, node_to_return->target, node_to_return);
	}
	set_curr_pos_cost(*a);
	set_curr_pos_cost(*b);
	set_return_cost(*a, *b);
	if ((*b)->final_pos < (*b)->next->final_pos)
		node_to_return = *b;
	else
		node_to_return = (*b)->next;
	take_route(a, b, node_to_return->target, node_to_return);
	set_curr_pos_cost(*a);
	set_curr_pos_cost(*b);
	set_return_cost(*a, *b);
	node_to_return = *b;
	take_route(a, b, node_to_return->target, node_to_return);
	cycle(a); */
	
	reverse_loops(a, b, ft_size(*b) - 1, (ft_size(*b) + 10) / 2);//this might be good
	//reverse_loops(a, b, ft_size(*b), ft_size(*b) / 2);
	take_it_home(a, b);
}


//below is a method of reversing the recursion for all
//starting numbers not just 500
//it seems to not give predictable improvement as with 500
//NOTE: Instead create interval data struct with values saved to do this,
// add pointer to all nodes, and just stick in any. needs array of vec2,
//length must be precomputed from stack size.  

/* typedef struct s_rec
{
	int	num;
	int	div;
	int num_p;
	int size;
} t_rec;

typedef struct s_args
{
	int	val1;
	int	val2;
} t_args;

static t_rec	set_info(t_stack **a, t_stack **b)
{
	int		i;
	int		num_blocks;
	int		init_size;
	int		size;
	t_rec	info;

	size = ft_size(*a) + ft_size(*b);
	init_size = size;
	info.size = size;
	info.num_p = 0;
	while (size >= 10 && init_size != 0)
	{
		num_blocks = 2;
		while (num_blocks < 4 && size >= 10)
		{
			i = -1;
			info.num = init_size / num_blocks;
			while (++i < info.num && size >= 10)
				size--;
			num_blocks++;
			info.num_p += info.num;
		}
		init_size = size;
	}
	info.div = num_blocks - 1;
	//printf("num: %d num_p: %d div: %d\n", info.num, info.num_p, info.div);
	return (info);
}

void	take_it_home_all(t_stack **a, t_stack **b)
{
	t_stack	*node_to_return;
	t_stack	*target;
	int		i;
	int		last_interval;
	t_rec	info;

	info = set_info(a, b);
	last_interval = info.size - (info.num_p - info.num);
	i = -1;
	//printf("loop: %d\n", last_interval - 9);
	while (++i < last_interval - 9)
	{
		set_curr_pos_cost(*a);
		set_curr_pos_cost(*b);
		set_return_cost(*a, *b);
		node_to_return = get_cheapest_return_interval(*b, info.size - \
		last_interval, info.size - 1);
		target = closest_match_target(*a, node_to_return->final_pos);
		take_route(a, b, target, node_to_return);
	}
	int		size = info.size;
	t_args	stored[100];
	int		calls = 0;
	int		val = -1;
	int		flag = 0;
	while (1)
	{
		i = 1;
		int size_orig = size;
		while (++i < 4)
		{
				val = val + size_orig / i;
			int val2 = val - (size_orig / i) / 2 + 1;
			stored[calls++] = (t_args){val, val2};
			size -= size_orig / i;
			if (size <= last_interval)
			{
				flag = 1;
				break ;
			}
		}
		if (flag)
			break ;
	}
	i = calls;
	//perform stored calls
	while (--i >= 0)
	{
		//printf("val1: %d val2: %d\n", stored[i].val1, stored[i].val2);
		reverse_loops(a, b, stored[i].val1, stored[i].val2);
	}
	take_it_home(a, b);
	cycle(a);

} */
