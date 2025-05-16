/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:41:58 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:48:39 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

char	**ft_join_args(char **argv)
{
	char	**values;
	char	*tmp;
	char	*str;
	int		i;

	i = 0;
	tmp = ft_strdup(" ");
	if (!tmp)
		exit(1);
	while (argv[++i])
	{
		str = ft_strjoin(tmp, argv[i]);
		free(tmp);
		if (!str)
			exit(1);
		tmp = ft_strjoin(str, " \0");
		free(str);
		if (!tmp)
			exit(1);
	}
	values = ft_split(tmp, ' ');
	free(tmp);
	if (!values)
		exit(1);
	return (values);
}

void	check_and_build_stack(t_stack **a, char **av, int *tab, int i)
{
	long	n;

	if (error_value(av[i]))
		free_all(a, av, tab);
	n = ft_atoil(av[i]);
	if (n > INTMAX || n < INTMIN)
		free_all(a, av, tab);
	if (error_doubles(*a, n))
		free_all(a, av, tab);
	tab[i] = n;
	add_node(a, av, tab, n);
}

void	init(t_stack **a, char **av, int len)
{
	int	i;
	int	*tab;

	tab = (int *)malloc(len * sizeof(int));
	if (!tab)
	{
		free_args(av);
		exit(1);
	}
	i = -1;
	while (av[++i])
		check_and_build_stack(a, av, tab, i);
	ft_quicksort(tab, 0, len - 1);
	ft_assign(*a, tab, len);
	free_args(av);
}
