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

void	sort_path(t_lists *all, int len)
{
	if (len == 2)
		sa(all, 0);
	else if (len == 3)
		sort_3(all, all->a);
	else
		push_swap(all, all->a, len);
	if (len == 2 || len == 3)
		print_moves(all->buff);
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
		init_all(all);
	}
	len = len_av(av);
	init(&all->a, av, len);
	if (!is_sorted(all->a))
		sort_path(all, len);
	free_all_list(all);
	return (EXIT_SUCCESS);
}
//printf("\nMoves: %d\n", all->count);
//./test.pl <number in stack>  <number of test runs>