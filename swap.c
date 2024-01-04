/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:44:09 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:44:11 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*n_1;
	t_stack	*n_2;

	if (!(*head) || !((*head)->next))
		return ;
	n_1 = *head;
	n_2 = (*head)->next;
	n_1->next = n_2->next;
	if (n_2->next != NULL)
		n_2->next->prev = n_1;
	n_2->prev = NULL;
	n_2->next = n_1;
	n_1->prev = n_2;
	*head = n_2;
}

void	sa(t_stack **a, int checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}
