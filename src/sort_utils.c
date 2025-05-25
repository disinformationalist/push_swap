/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:43:53 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:43:56 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if only rotation is needed to sort the current stack

int	is_cyclic_sorted(t_stack *stack)
{
	t_stack	*rot_loc;
	t_stack	*start;

	if (!stack)
		return (0);
	rot_loc = NULL;
	start = stack;
	while ((stack)->next)
	{
		if (stack->content > stack->next->content)
		{
			rot_loc = stack;
			stack = stack->next;
			break ;
		}
		stack = stack->next;
	}
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (rot_loc == highest(start)
		&& ft_last(start)->content < start->content);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_3(t_stack **stack)
{
	t_stack	*high;

	high = highest(*stack);
	if (*stack == high)
		ra(stack, 0);
	else if ((*stack)->next == high)
		rra(stack, 0);
	if ((*stack)->content > (*stack)->next->content)
		sa(stack, 0);
}

void	write_ops(const char *s, int len, int cost)
{
	write(1, s, len);
	moves += cost;
}

int	rasararasara(t_stack **a)
{
	ra(a, 1);
	sa(a, 1);
	ra(a, 1);
	ra(a, 1);
	sa(a, 1);
	if (is_sorted(*a))
		return (write_ops("ra\nsa\nra\nra\nsa\n", 15, 5), 1);
	ra(a, 1);
	if (is_sorted(*a))
		return (write_ops("ra\nsa\nra\nra\nsa\nra\n", 18, 6), 1);
	rra(a, 1);
	rra(a, 1);
	if (is_sorted(*a))
		return (write_ops("ra\nsa\nra\nra\nsa\nrra\n", 19, 6), 1);
	rra(a, 1);
	if (is_sorted(*a))
		return (write_ops("ra\nsa\nra\nra\nsa\nrra\nrra\n", 23, 7), 1);
	ra(a, 1);
	ra(a, 1);
	sa(a, 1);
	rra(a, 1);
	rra(a, 1);
	sa(a, 1);
	rra(a, 1);
	return (0);
}

int pbpbssparrapara(t_stack **a, t_stack **b)
{
	pb(b, a, 1);
	pb(b, a, 1);
	ss(a, b, 1);
	pa(a, b, 1);
	rra(a, 1);
	pa(a, b, 1);
	ra(a, 1);
	if (is_sorted(*a))
		return (write_ops("pb\npb\nss\npa\nrra\npa\nra\n", 22, 7), 1);
	ra(a, 1);
	if (is_sorted(*a))
		return (write_ops("pb\npb\nss\npa\nrra\npa\nra\nra\n", 25, 8), 1);
	rra(a, 1);
	rra(a, 1);
	pb(b, a, 1);
	ra(a, 1);
	pb(b, a, 1);
	ss(a, b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	return (0);
}

int	sararasararasa(t_stack **a)
{
	sa(a, 1);
	ra(a, 1);
	ra(a, 1);
	sa(a, 1);
	ra(a, 1);
	ra(a, 1);
	if (is_sorted(*a))
		return (write_ops("sa\nra\nra\nsa\nra\nra\n", 18, 6), 1);
	sa(a, 1);
	if (is_sorted(*a))
		return (write_ops("sa\nra\nra\nsa\nra\nra\nsa\n", 21, 7), 1);
	sa(a, 1);
	rra(a, 1);
	rra(a, 1);
	sa(a, 1);
	rra(a, 1);
	rra(a, 1);
	sa(a, 1);
	return (0);
}

int	rapbpbsbrapapa(t_stack **a, t_stack**b)
{
	ra(a, 1);
	pb(b, a, 1);
	pb(b, a, 1);
	sb(b, 1);
	ra(a, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	if (is_sorted(*a))
		return (write_ops("ra\npb\npb\nsb\nra\npa\npa\n", 21, 7), 1);
	rra(a, 1);
	if (is_sorted(*a))
		return (write_ops("ra\npb\npb\nsb\nra\npa\npa\nrra\n", 25, 8), 1);
	ra(a, 1);
	pb(b, a, 1);
	pb(b, a, 1);
	rra(a, 1);
	sb(b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	rra(a, 1);
	return (0);
}

int	rrapbrrarrasapara(t_stack **a, t_stack **b)
{
	rra(a, 1);
	pb(b, a, 1);
	rra(a, 1);
	rra(a, 1);
	sa(a, 1);
	pa(a, b, 1);
	ra(a, 1);
	if (is_sorted(*a))
		return (write_ops("rra\npb\nrra\nrra\nsa\npa\nra\n", 24, 7), 1);
	rra(a, 1);
	pb(b, a, 1);
	sa(a, 1);
	ra(a, 1);
	ra(a, 1);
	pa(a, b, 1);
	ra(a, 1);
	return (0);
}

/* printf("---------\n");
print_stack(*a);	
printf("---------\n"); */

//try sa to see if it makes sorted or cyclic sorted
//then check ra + sa, ra + ra + sa
//then rra + sa, rra + rra + sa
//uses ss instead of sa when two in B and smaller is on top

bool	swap_test(t_stack **a, t_stack **b, int loop)
{
	bool condition;
	
	condition = *b && (*b)->next && (*b)->final_pos < ((*b)->next->final_pos);
	if (condition)
		ss(a, b, 1);
	else
		sa(a, 1);
	if (is_sorted(*a) || is_cyclic_sorted(*a))
	{
		if (loop ==  1)
			write_ops("ra\n", 3, 1);
		else if (loop == 2)
			write_ops("ra\nra\n", 6, 2);
		else if (loop ==  3)
			write_ops("rra\n", 4, 1);
		else if (loop == 4)
			write_ops("rra\nrra\n", 8, 2);
		if (condition)
			write(1, "ss\n", 3);
		else
			write(1, "sa\n", 3);
		moves++;
		return (1);
	}
	else if (condition)//backtrack ss or sa
		ss(a, b, 1);
	else
		sa(a, 1);
	if (!loop)
	{
		loop++;
		ra(a, 1);//try ra sa
		if (swap_test(a, b, loop))
			return (1);
		else
		{
			loop++;
			ra(a, 1);//try ra ra sa
			if (swap_test(a, b, loop))
				return (1);
			rra(a, 1);
		}
		rra(a, 1);//backtrack
		rra(a, 1);// try rra sa
		loop++;
		if (swap_test(a, b, loop))
			return (1);
		else
		{
			loop++;
			rra(a, 1);//try rra rra sa
			if (swap_test(a, b, loop))
				return (1);
			ra(a, 1);
		}
			ra(a, 1);
	}
	return (0);
}



//sorts between 4 and 9

void	sort_5(t_stack **a, t_stack **b)
{
	int	len;
	len = ft_size(*a) + 1;
	while (--len > 3)
	{
		if (len >= 5)
			if (rasararasara(a) || sararasararasa(a) 
				|| pbpbssparrapara(a, b) || rapbpbsbrapapa(a, b) 
				|| rrapbrrarrasapara(a, b))
				break;
		if (swap_test(a, b, 0))//new
			break;
		
		pb(b, a, 0);
		if (is_sorted(*a) || is_cyclic_sorted(*a))
			break ;
	}
	if (ft_size(*a) == 3 && !is_sorted(*a) && !is_cyclic_sorted(*a))
		sort_3(a);
	take_it_home(a, b);
	cycle(a);
}

//
//get lowest, move it to b, contiue until 3 left, sorts 3, moves all back to a 
//good only for small stacks, leaves sorted or cyclic sorted

void	sort_now(t_stack **a, t_stack **b)
{
	int	count;
	int	len;

	count = 0;
	len = ft_size(*a) + 1;
	while (--len > 3)
	{
	/* 	if (len >= 5)
			if (rasararasara(a) || sararasararasa(a) 
				|| pbpbssparrapara(a, b) || rapbpbsbrapapa(a, b)
				|| rrapbrrarrasapara(a, b))
				break; */
		if (is_sorted(*a) || is_cyclic_sorted(*a))
			return ;
		if (swap_test(a, b, 0))
			return;
		move_to_top_a(a, lowest(*a));
		pb(b, a, 0);
		count++;
	}
	sort_3(a);
	while (count)
	{
		pa(a, b, 0);
		count--;
	}
}
