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
	return (0);
}
