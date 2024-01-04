/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:49:26 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:49:30 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void	moves(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		sa(a, 1);
	else if (!ft_strcmp(move, "sb\n"))
		sb(b, 1);
	else if (!ft_strcmp(move, "ss\n"))
		ss(a, b, 1);
	else if (!ft_strcmp(move, "pa\n"))
		pa(a, b, 1);
	else if (!ft_strcmp(move, "pb\n"))
		pb(b, a, 1);
	else if (!ft_strcmp(move, "ra\n"))
		ra(a, 1);
	else if (!ft_strcmp(move, "rb\n"))
		rb(b, 1);
	else if (!ft_strcmp(move, "rr\n"))
		rr(a, b, 1);
	else if (!ft_strcmp(move, "rra\n"))
		rra(a, 1);
	else if (!ft_strcmp(move, "rrb\n"))
		rrb(b, 1);
	else if (!ft_strcmp(move, "rrr\n"))
		rrr(a, b, 1);
	else
		error(a, b);
}

static void	print_and_free(t_stack *a, int len)
{
	if (is_sorted(a) && len == ft_size(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
}

int	main(int ac, char **argv)
{
	int		len;
	char	**av;
	char	*line;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !argv[1][0]))
		return (0);
	else
		av = ft_join_args(argv);
	len = len_av(av);
	init(&a, av, len);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		moves(&a, &b, line);
		line = get_next_line(STDIN_FILENO);
	}
	print_and_free(a, len);
	return (0);
}
