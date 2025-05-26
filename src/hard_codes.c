#include "push_swap.h"

/* This set of 11 hardcodes to check handles the cases for 5 numbers that the
algo needs 9 or 10 moves to sort. This way 5 always sorts in 8 or fewer. */

int	rasararasara(t_lists *all)
{
	ra(all, 1);
	sa(all, 1);
	ra(all, 1);
	ra(all, 1);
	sa(all, 1);
	if (is_sorted(all->a))
	{
		add_move(all, "ra\n");
		add_move(all, "sa\n");
		add_move(all, "ra\n");
		add_move(all, "ra\n");
		add_move(all, "sa\n");
		return (1);
	}
	ra(all, 1);
	if (is_sorted(all->a))
	{
		add_move(all, "ra\n");
		add_move(all, "sa\n");
		add_move(all, "ra\n");
		add_move(all, "ra\n");
		add_move(all, "sa\n");
		add_move(all, "ra\n");
		return (1);
	}
	rra(all, 1);
	rra(all, 1);
	if (is_sorted(all->a))
	{
		add_move(all, "ra\n");
		add_move(all, "sa\n");
		add_move(all, "ra\n");
		add_move(all, "ra\n");
		add_move(all, "sa\n");
		add_move(all, "rra\n");
		return (1);
	}
	rra(all, 1);
	if (is_sorted(all->a))
	{
		add_move(all, "ra\n");
		add_move(all, "sa\n");
		add_move(all, "ra\n");
		add_move(all, "ra\n");
		add_move(all, "sa\n");
		add_move(all, "rra\n");
		add_move(all, "rra\n");
		return (1);
	}
	ra(all, 1);
	ra(all, 1);
	sa(all, 1);
	rra(all, 1);
	rra(all, 1);
	sa(all, 1);
	rra(all, 1);
	return (0);
}

int pbpbssparrapara(t_lists *all)
{
	pb(all, 1);
	pb(all, 1);
	ss(all, 1);
	pa(all, 1);
	rra(all, 1);
	pa(all, 1);
	ra(all, 1);
	if (is_sorted(all->a))
	{
		add_move(all, "pb\n");
		add_move(all, "pb\n");
		add_move(all, "ss\n");
		add_move(all, "pa\n");
		add_move(all, "rra\n");
		add_move(all, "pa\n");
		add_move(all, "ra\n");
		return (1);
	}
	ra(all, 1);
	if (is_sorted(all->a))
	{
		add_move(all, "pb\n");
		add_move(all, "pb\n");
		add_move(all, "ss\n");
		add_move(all, "pa\n");
		add_move(all, "rra\n");
		add_move(all, "pa\n");
		add_move(all, "ra\n");
		add_move(all, "ra\n");
		return (1);
	}
	rra(all, 1);
	rra(all, 1);
	pb(all, 1);
	ra(all, 1);
	pb(all, 1);
	ss(all, 1);
	pa(all, 1);
	pa(all, 1);
	return (0);
}

int	sararasararasa(t_lists *all)
{
	sa(all, 1);
	ra(all, 1);
	ra(all, 1);
	sa(all, 1);
	ra(all, 1);
	ra(all, 1);
	if (is_sorted(all->a))
	{
		add_move(all, "sa\n");
		add_move(all, "ra\n");
		add_move(all, "ra\n");
		add_move(all, "sa\n");
		add_move(all, "ra\n");
		add_move(all, "ra\n");
		return (1);
	}
	sa(all, 1);
	if (is_sorted(all->a))
	{
		add_move(all, "sa\n");
		add_move(all, "ra\n");
		add_move(all, "ra\n");
		add_move(all, "sa\n");
		add_move(all, "ra\n");
		add_move(all, "ra\n");
		add_move(all, "sa\n");
		return (1);
	}
	sa(all, 1);
	rra(all, 1);
	rra(all, 1);
	sa(all, 1);
	rra(all, 1);
	rra(all, 1);
	sa(all, 1);
	return (0);
}

int	rapbpbsbrapapa(t_lists *all)
{
	ra(all, 1);
	pb(all, 1);
	pb(all, 1);
	sb(all, 1);
	ra(all, 1);
	pa(all, 1);
	pa(all, 1);
	if (is_sorted(all->a))
	{
		add_move(all, "ra\n");
		add_move(all, "pb\n");
		add_move(all, "pb\n");
		add_move(all, "sb\n");
		add_move(all, "ra\n");
		add_move(all, "pa\n");
		add_move(all, "pa\n");		
		return (1);
	}
	rra(all, 1);
	if (is_sorted(all->a))
	{
		add_move(all, "ra\n");
		add_move(all, "pb\n");
		add_move(all, "pb\n");
		add_move(all, "sb\n");
		add_move(all, "ra\n");
		add_move(all, "pa\n");
		add_move(all, "pa\n");	
		add_move(all, "rra\n");		
		return (1);
	}
	ra(all, 1);
	pb(all, 1);
	pb(all, 1);
	rra(all, 1);
	sb(all, 1);
	pa(all, 1);
	pa(all, 1);
	rra(all, 1);
	return (0);
}

int	rrapbrrarrasapara(t_lists *all)
{
	rra(all, 1);
	pb(all, 1);
	rra(all, 1);
	rra(all, 1);
	sa(all, 1);
	pa(all, 1);
	ra(all, 1);
	if (is_sorted(all->a))
	{
		add_move(all, "rra\n");
		add_move(all, "pb\n");
		add_move(all, "rra\n");
		add_move(all, "rra\n");
		add_move(all, "sa\n");
		add_move(all, "pa\n");
		add_move(all, "ra\n");
		return ( 1);
	}
	rra(all, 1);
	pb(all, 1);
	sa(all, 1);
	ra(all, 1);
	ra(all, 1);
	pa(all, 1);
	ra(all, 1);
	return (0);
}