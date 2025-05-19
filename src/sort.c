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
	t_stack	*node;

	node = get_cheapest_2(*a, num * j);
	if (((*b)->final_pos < num * (j - 1) + num / 2)
		&& node->curr_pos != 0 && node->curr_pos < ft_size(*a) / 2
		&& (*b)->next && (*b)->next->final_pos >= num * (j -1) + num / 2)
		rr(a, b, 0);
	else if ((*b)->final_pos < num * (j - 1) + num / 2 && (*b)->next
		&& (*b)->next->final_pos >= num * (j - 1) + num / 2)
		rb(b, 0);
}

t_stack	*get_node_at(t_stack *stack, int pos)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->final_pos == pos)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	harmony_sort(t_stack **a, t_stack **b, int num_blocks, int num)
{
	t_stack	*node;
	int		i;
	int		j;

	j = 0;
	while (++j < num_blocks + 1)
	{
		i = -1;
		while (++i < num)
		{
			move_to_top_a(a, get_cheapest_2(*a, num * j));
			pb(b, a, 0);
			if (is_sorted(*a) || is_cyclic_sorted(*a))
				return ;
			node = get_cheapest_2(*a, num * j);
			if (node == NULL)
				break ;
			harmony_ops(a, b, num, j);
		}
	}
}

static void	sort_500_ops(t_stack **a, t_stack **b, int num_prev, int num)
{
	t_stack	*node;

	move_to_top_a(a, get_cheapest(*a, num_prev + num));
	pb(b, a, 0);
	node = get_cheapest(*a, num_prev + num);
	if ((node && (*b)->final_pos < num_prev + num / 2)
		&& node->curr_pos != 0 && node->curr_pos < ft_size(*a) / 2)
		rr(a, b, 0);
	else if ((*b)->final_pos < num_prev + num / 2)
		rb(b, 0);
}

// recursively send blocks of numbers to stack b while a is larger than 10
// first does 1/2 of orig size, then 1/3 of orig size
// then recurs with the new current size, 1/2, 1/3, ... until 9 remain
// troubshoot: printf("----num_p: %d\n---num:  %d\n\n", num_prev, num);

static void	sort_500(t_stack **a, t_stack **b, int num_prev, int len)
{
	int	i;
	int	num;
	int	num_blocks;

	if (ft_size(*a) < 10 || *a == NULL)
		return ;
	num_blocks = 2;
	while (num_blocks < 4 && ft_size(*a) >= 10)
	{
		i = -1;
		num = len / num_blocks;
		while (++i < num && ft_size(*a) >= 10)
		{
			sort_500_ops(a, b, num_prev, num);
		}
		num_blocks++;
		num_prev += num;
	
	}
	sort_500(a, b, num_prev, ft_size(*a));
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
		harmony_sort(a, b, 3, 100);
		take_it_home(a, b);
	}
	else
	{
		sort_500(a, b, 0, ft_size(*a));
		sort_now(a, b);
		if (len == 500)
			take_it_home_500(a, b);
		else
			take_it_home(a, b);
	}
}
