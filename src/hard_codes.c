#include "push_swap.h"

/* This set of 11 hardcodes to check handles the cases for 5 numbers that the
algo needs 9 or 10 moves to sort. This way 5 always sorts in 8 or fewer. */

int	rasararasara(t_stack **a)
{
	ra(a, 1);
	sa(a, 1);
	ra(a, 1);
	ra(a, 1);
	sa(a, 1);
	if (is_sorted(*a))
		return (write_ops("ra\nsa\nra\nra\nsa\n", 15, 5), 1);
	ra(a, 1);
	if (is_sorted(*a))
		return (write_ops("ra\nsa\nra\nra\nsa\nra\n", 18, 6), 1);
	rra(a, 1);
	rra(a, 1);
	if (is_sorted(*a))
		return (write_ops("ra\nsa\nra\nra\nsa\nrra\n", 19, 6), 1);
	rra(a, 1);
	if (is_sorted(*a))
		return (write_ops("ra\nsa\nra\nra\nsa\nrra\nrra\n", 23, 7), 1);
	ra(a, 1);
	ra(a, 1);
	sa(a, 1);
	rra(a, 1);
	rra(a, 1);
	sa(a, 1);
	rra(a, 1);
	return (0);
}

int pbpbssparrapara(t_stack **a, t_stack **b)
{
	pb(b, a, 1);
	pb(b, a, 1);
	ss(a, b, 1);
	pa(a, b, 1);
	rra(a, 1);
	pa(a, b, 1);
	ra(a, 1);
	if (is_sorted(*a))
		return (write_ops("pb\npb\nss\npa\nrra\npa\nra\n", 22, 7), 1);
	ra(a, 1);
	if (is_sorted(*a))
		return (write_ops("pb\npb\nss\npa\nrra\npa\nra\nra\n", 25, 8), 1);
	rra(a, 1);
	rra(a, 1);
	pb(b, a, 1);
	ra(a, 1);
	pb(b, a, 1);
	ss(a, b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	return (0);
}

int	sararasararasa(t_stack **a)
{
	sa(a, 1);
	ra(a, 1);
	ra(a, 1);
	sa(a, 1);
	ra(a, 1);
	ra(a, 1);
	if (is_sorted(*a))
		return (write_ops("sa\nra\nra\nsa\nra\nra\n", 18, 6), 1);
	sa(a, 1);
	if (is_sorted(*a))
		return (write_ops("sa\nra\nra\nsa\nra\nra\nsa\n", 21, 7), 1);
	sa(a, 1);
	rra(a, 1);
	rra(a, 1);
	sa(a, 1);
	rra(a, 1);
	rra(a, 1);
	sa(a, 1);
	return (0);
}

int	rapbpbsbrapapa(t_stack **a, t_stack**b)
{
	ra(a, 1);
	pb(b, a, 1);
	pb(b, a, 1);
	sb(b, 1);
	ra(a, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	if (is_sorted(*a))
		return (write_ops("ra\npb\npb\nsb\nra\npa\npa\n", 21, 7), 1);
	rra(a, 1);
	if (is_sorted(*a))
		return (write_ops("ra\npb\npb\nsb\nra\npa\npa\nrra\n", 25, 8), 1);
	ra(a, 1);
	pb(b, a, 1);
	pb(b, a, 1);
	rra(a, 1);
	sb(b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	rra(a, 1);
	return (0);
}

int	rrapbrrarrasapara(t_stack **a, t_stack **b)
{
	rra(a, 1);
	pb(b, a, 1);
	rra(a, 1);
	rra(a, 1);
	sa(a, 1);
	pa(a, b, 1);
	ra(a, 1);
	if (is_sorted(*a))
		return (write_ops("rra\npb\nrra\nrra\nsa\npa\nra\n", 24, 7), 1);
	rra(a, 1);
	pb(b, a, 1);
	sa(a, 1);
	ra(a, 1);
	ra(a, 1);
	pa(a, b, 1);
	ra(a, 1);
	return (0);
}