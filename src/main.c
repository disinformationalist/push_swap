/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:40:30 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:40:34 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves = 0;

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		printf("index: %d     content %d\n", i++, stack->content);
		stack = stack->next;
	}
}

//add_node copied node

void	add_copy_node(t_stack **copy, t_stack *new)
{
	t_stack	*last;
	
	new->next = NULL;
	if (*copy == NULL)
	{
		*copy = new;
		new->prev = NULL;
	}
	else
	{
		last = ft_last(*copy);
		last->next = new;
		new->prev = last;
	}
}

//make a copy of a stacks current state

t_stack	*stack_copy(t_stack *to_copy)
{
	t_stack *copy;
	t_stack *curr;
	t_stack *new;

	copy = NULL;
	curr = to_copy;
	while (curr)
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
		{	
			free_stack(&copy);
			return (NULL);
		}
		*new = *curr;
		add_copy_node(&copy, new);
		curr = curr->next;
	}
	return (copy);
}

int	main(int ac, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			len;
	char		**av;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !argv[1][0]))
		return (1);
	else
		av = ft_join_args(argv);
	len = len_av(av);
	init(&a, av, len);
	if (!is_sorted(a))
	{
		if (len == 2)
			sa(&a, 0);
		else if (len == 3)
			sort_3(&a);
		else
			push_swap(&a, &b, len);
	}
	free_stack(&a);
	//printf("\nMoves: %d\n", moves);
	return (0);
}
//./test.pl <number in stack>  <number of test runs>