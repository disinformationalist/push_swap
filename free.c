/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:38:57 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:39:18 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*temp;

	if (stack == NULL)
		return ;
	curr = *stack;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*stack = NULL;
}

void	free_args(char **av)
{
	int	i;

	if (av == NULL || *av == NULL)
		return ;
	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	free_all(t_stack **a, char **av, int *tab)
{
	free_stack(a);
	free_args(av);
	free(tab);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_doubles(t_stack *a, int num)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->content == num)
			return (1);
		a = a->next;
	}
	return (0);
}

int	error_value(char *str)
{
	if ((*str == '+' || *str == '-') && !ft_isdigit(str[1]))
		return (1);
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
		return (1);
	while (*(++str))
	{
		if (!(ft_isdigit(*str)))
			return (1);
	}
	return (0);
}
