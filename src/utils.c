/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:45:11 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:45:13 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_stack	*ft_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*lowest(t_stack *stack)
{
	long	n;
	t_stack	*lowest;

	if (stack == NULL)
		return (NULL);
	n = INTMAX;
	while (stack)
	{
		if (stack->content < n)
		{
			n = stack->content;
			lowest = stack;
		}
		stack = stack->next;
	}
	return (lowest);
}

t_stack	*highest(t_stack *stack)
{
	long	n;
	t_stack	*highest;

	if (stack == NULL)
		return (NULL);
	n = INTMIN;
	while (stack)
	{
		if (stack->content > n)
		{
			n = stack->content;
			highest = stack;
		}
		stack = stack->next;
	}
	return (highest);
}

void	add_node(t_stack **stack, char **av, int *tab, long n)
{
	t_stack	*new;
	t_stack	*last;

	if (stack == NULL)
		return ;
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		free_all(stack, av, tab);
	new->next = NULL;
	new->content = n;
	new->target = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = ft_last(*stack);
		last->next = new;
		new->prev = last;
	}
}
