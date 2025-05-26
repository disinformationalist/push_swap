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

void	free_buff(t_buffer *buff)
{
	t_buffer *tmp;

	while (buff)
	{
		tmp = buff->next;
		free(buff);
		buff = tmp;
	}
}

void add_move(t_lists *all, char *move)
{
	t_buffer *new;
	
	new = (t_buffer *)malloc(sizeof(t_buffer));
	if (!new)
	{
		free_stack(&all->a);
		free_stack(&all->b);
		free_buff(all->buff);
	}
	new->move = move;
	new->next = NULL;
	if (!all->tail)
	{
		all->buff = new;
		all->tail = new;
	}
	else
	{
		all->tail->next = new;
		all->tail = new;
	}
	all->count++;
}	


void	print_moves(t_buffer *buff)
{
	t_buffer *tmp;

	tmp = buff;
	while (tmp)
	{
		ft_putstr_fd(tmp->move, 1);
		tmp = tmp->next;
	}
}

int	main(int ac, char **argv)
{
	int			len;
	char		**av;
	t_lists		*all;

	if (ac == 1 || (ac == 2 && !argv[1][0]))
		return (1);
	else
	{
		av = ft_join_args(argv);
		all = (t_lists *)malloc(sizeof(t_lists));
		if (!all)
			return (EXIT_FAILURE);
		all->a = NULL;
		all->b = NULL;
		all->count = 0;
		all->buff = NULL;
		all->tail = NULL;
	}
	len = len_av(av);
	init(&all->a, av, len);
	if (!is_sorted(all->a))
	{
		if (len == 2)
			sa(all, 0);
		else if (len == 3)
			sort_3(all, all->a);
		else
		{
			push_swap(all, all->a, len);
		}
		print_moves(all->buff);
		free_buff(all->buff);
	}
	//print_stack(all->a);
	free_stack(&all->a);
	free(all);
	//printf("\nMoves: %d\n", moves);
	return (0);
}
//./test.pl <number in stack>  <number of test runs>