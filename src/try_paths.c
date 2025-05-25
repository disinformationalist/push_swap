#include "push_swap.h"

//save instructions to buffer instead, print all alt once, count compare







void	try_route_1(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	int	rr_rots;
	int	a_rots;

	rr_rots = node->curr_pos;
	a_rots = target->curr_pos - node->curr_pos;
	while (rr_rots)
	{
		rr(a, b, 1);
		rr_rots--;
	}
	while (a_rots)
	{
		ra(a, 1);
		a_rots--;
	}
}

void	try_route_2(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	int	rr_rots;
	int	b_rots;

	rr_rots = target->curr_pos;
	b_rots = node->curr_pos - target->curr_pos;
	while (rr_rots)
	{
		rr(a, b, 1);
		rr_rots--;
	}
	while (b_rots)
	{
		rb(b, 1);
		b_rots--;
	}
}

void	try_route_3(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	int	rrr_rots;
	int	b_rots;

	rrr_rots = ft_size(*a) - target->curr_pos;
	b_rots = (ft_size(*b) - node->curr_pos) - rrr_rots;
	while (rrr_rots)
	{
		rrr(a, b, 1);
		rrr_rots--;
	}
	while (b_rots)
	{
		rrb(b, 1);
		b_rots--;
	}
}

void	try_route_4(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	int	rrr_rots;
	int	a_rots;

	rrr_rots = ft_size(*b) - node->curr_pos;
	a_rots = (ft_size(*a) - target->curr_pos) - rrr_rots;
	while (rrr_rots)
	{
		rrr(a, b, 1);
		rrr_rots--;
	}
	while (a_rots)
	{
		rra(a, 1);
		a_rots--;
	}
}

void	try_route_5(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	int	a_rots;
	int	b_rots;

	a_rots = target->cost;
	b_rots = node->cost;
	while (a_rots)
	{
		ra(a, 1);
		a_rots--;
	}
	while (b_rots)
	{
		rrb(b, 1);
		b_rots--;
	}
}


static int	try_sort_500_ops(t_stack **a, t_stack **b, int num_prev, int num)
{
	t_stack	*to_send;
	t_stack	*next_node;

	/* if (swap_test(a, b))//new
		return (1); */
	to_send = get_cheapest(*a, num_prev + num);
	move_to_top_a(a, b, to_send);
	pb(b, a, 1);
	next_node = get_cheapest(*a, num_prev + num);
	if ((next_node && (*b)->final_pos < num_prev + num / 2)
		&& next_node->curr_pos != 0 && next_node->curr_pos < ft_size(*a) / 2)
		rr(a, b, 1);
	else if ((*b)->final_pos < num_prev + num / 2)
		rb(b, 1);
	else if (next_node && next_node->curr_pos == 1 && (*b)->next \
		&& ((*b)->final_pos + 1 == (*b)->next->final_pos))
	   ss(a, b, 1);
	if (is_sorted(*a) || is_cyclic_sorted(*a))
		return (1);
	return (0);
}

// recursively send blocks of numbers to stack b while a is larger than lim
// first does 1/2 of orig size, then 1/3 of orig size
// then recurs with the new current size, 1/2, 1/3, ... until 9 remain
// troubshoot: printf("----num_p: %d\n---num:  %d\n\n", num_prev, num);

static void	try_sort_500(t_stack **a, t_stack **b, int num_prev, int len)
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
			if (try_sort_500_ops(a, b, num_prev, num))
				len = lim;
			len--;
		}
		num_blocks++;
		num_prev += num;
	}
	try_sort_500(a, b, num_prev, len);
	return ;
}