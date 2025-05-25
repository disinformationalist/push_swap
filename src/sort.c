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

static void	harmony_ops(t_stack **a, t_stack **b, int num, int j)
{
	t_stack	*next_node;

	next_node = get_cheapest_2(*a, num * j);
	if ((*b)->next && (*b)->next->final_pos + 1 == (*b)->final_pos)//trying consecutives...
		return ;
	else if (next_node && next_node->curr_pos == 1 && (*b)->next //try moving this back
			&& (((*b)->final_pos + 1 == (*b)->next->final_pos)))
		   ss(a, b, 0);
	else if (next_node && ((*b)->final_pos < num * (j - 1) + num / 2)
		&& next_node->curr_pos != 0 && next_node->curr_pos < ft_size(*a) / 2
		&& (*b)->next && (*b)->next->final_pos >= num * (j - 1) + num / 2)
		rr(a, b, 0);
	else if ((*b)->final_pos < num * (j - 1) + num / 2 && (*b)->next
		&& (*b)->next->final_pos >= num * (j - 1) + num / 2)
		rb(b, 0);
	/* else if (next_node && next_node->curr_pos == 0 && (*a)->next->final_pos < next_node->final_pos && (*b)->next \
		&& ((*b)->final_pos + 1 == (*b)->next->final_pos))
	   ss(a, b, 0); */
}


//leave largest cyclic sorted set

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
			/* if (swap_test(a, b))//new
				return; */
			node = get_cheapest_2(*a, num * j);
			if (node == NULL)
				break ;
			move_to_top_a(a, node);
			pb(b, a, 0);
			harmony_ops(a, b, num, j);
			if (is_sorted(*a) || is_cyclic_sorted(*a))
				return ;
		}
	}
}

//trying shuffle in idea..
// way to use double rots during sending...not working yet, conditions not met oft enough to work
/* static int	sort_500_ops(t_stack **a, t_stack **b, int num_prev, int num)
{
	t_stack	*to_send;
	t_stack	*next_node;
	bool	flag = 0;

	to_send = get_cheapest(*a, num_prev + num);
	if (!to_send)
		return 0;
	next_node = get_2nd_cheapest(*a, num_prev + num, to_send);
	//-----
	if (to_send && !to_send->above_mid && *b && ft_last(*b)->final_pos + 1 == to_send->final_pos && next_node && next_node->above_mid && next_node->cost > 1)
	{
		rrr(a, b, 0);
		flag = 1;
		//next_node->direction = 3;//flag
	}
	else
		move_to_top_a(a, to_send);
	//----
	pb(b, a, 0);
	if (flag)
	{
		rr(a, b, 0);
		rr(a, b, 0);
	}
		//next_node = get_cheapest(*a, num_prev + num);
	else if ((next_node && (*b)->final_pos < num_prev + num / 2)
		&& next_node->curr_pos != 0 && next_node->curr_pos < ft_size(*a) / 2)
		rr(a, b, 0);
	else if ((*b)->final_pos < num_prev + num / 2)
		rb(b, 0);
	else if (next_node && next_node->curr_pos == 1 && (*b)->next \
		&& ((*b)->final_pos + 1 == (*b)->next->final_pos))
	   ss(a, b, 0); 
	if (is_sorted(*a) || is_cyclic_sorted(*a))
		return (1);
	return (0);
} */

static int	sort_500_ops(t_stack **a, t_stack **b, int num_prev, int num)
{
	t_stack	*to_send;
	t_stack	*next_node;

	/* if (swap_test(a, b))//new
		return (1); */
	to_send = get_cheapest(*a, num_prev + num);
	move_to_top_a(a, to_send);
	pb(b, a, 0);
	next_node = get_cheapest(*a, num_prev + num);
	if (next_node && next_node->final_pos + 1 == (*b)->final_pos)//trying consecutives...
		return (0);
	if ((next_node && (*b)->final_pos < num_prev + num / 2)
		&& next_node->curr_pos != 0 && next_node->curr_pos < ft_size(*a) / 2)
		rr(a, b, 0);
	else if ((*b)->final_pos < num_prev + num / 2)
		rb(b, 0);
	else if (next_node && next_node->curr_pos == 1 && (*b)->next \
		&& ((*b)->final_pos + 1 == (*b)->next->final_pos))
	   ss(a, b, 0);
	if (is_sorted(*a) || is_cyclic_sorted(*a))
		return (1);
	return (0);
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
	int lim = 10;//85 for harm

	if (len < lim || *a == NULL)
		return ;
	num_blocks = 2;
	len_start = len;
	while (num_blocks < 4 && len >= lim)
	{
		i = -1;
		num = len_start / num_blocks;
		while (++i < num && len >= lim)
		{
			if (sort_500_ops(a, b, num_prev, num))
				len = lim;
			len--;
		}
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
		sort_5(a, b);
	else if (len > 9 && len <= 210)
	{
		get_biggest_cyclic(*a, 0, 0);
		//printf("--------------size: %d\n", leave_size(*a));
		harmony_sort(a, b, 3, 3 * len / 4 + 2);
		take_it_home(a, b);
	}
	else
	{
		//t_stack *copy = stack_copy(*a);
		

		sort_500(a, b, 0, len);
		sort_now(a, b);

		/* if ((*a)->final_pos > (*a)->next->final_pos && (*b)->final_pos < (*b)->next->final_pos)
			ss(a, b, 0);*/
		if (len == 500)
			take_it_home_500(a, b);
		else
			take_it_home_100(a, b);
	}
}


