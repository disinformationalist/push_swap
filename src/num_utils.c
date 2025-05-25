/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:41:06 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:41:10 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

long	ft_atoil(const char *nptr)
{
	long	result;
	int		i;
	int		sign;

	result = 0;
	sign = 1;
	i = spaces(nptr);
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		sign = 44 - nptr[i];
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}

void	ft_assign(t_stack *a, int *tab, int len)
{
	int	i;

	while (a)
	{
		a->leave = 0;
		i = -1;
		while (++i < len)
		{
			if (a->content == tab[i])
				a->final_pos = i;
		}
		a = a->next;
	}
	free(tab);
}

int	leave_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->leave)
			count++;
		stack = stack->next;
	}
	return (count);
}

//gets 2nd cheapest to send to B ignoring flagged nodes

t_stack *get_2nd_cheapest_2(t_stack *stack, int num, t_stack *cheapest)
{
	t_stack	*cheapest2;
	int		n;
	int		cost;

	n = INTMAX;
	cheapest2 = NULL;
	while (stack)
	{
		cost = stack->cost;
		if (cost < n && stack->final_pos < num 
			&& stack != cheapest && !stack->leave)
		{
			n = cost;
			cheapest2 = stack;
		}
		stack = stack->next;
	}
	return (cheapest2);
}

//gets cheapest to send to B ignoring flagged nodes

t_stack	*get_cheapest_2(t_stack *stack, int num)
{
	int		n;
	t_stack	*cheapest;
	int		cost;

	if (stack == NULL)
		return (NULL);
	set_curr_pos_cost(stack);
	n = INTMAX;
	cheapest = NULL;
	while (stack)
	{
		cost = stack->cost;
		if (cost < n && stack->final_pos < num && !stack->leave 
			&& (stack->above_mid || cost == 1))
		{
			n = cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
		return (cheapest);
}
