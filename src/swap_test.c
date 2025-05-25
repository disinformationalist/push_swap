#include "push_swap.h"

//trouble shoot:
/* printf("---------\n");
print_stack(*a);	
printf("---------\n"); */

void	write_ops(const char *s, int len, int cost)
{
	write(1, s, len);
	moves += cost;
}

void print_case(int loop, bool condition)
{
	if (loop ==  1)
		write_ops("ra\n", 3, 1);
	else if (loop == 2)
		write_ops("ra\nra\n", 6, 2);
	else if (loop ==  3)
		write_ops("rra\n", 4, 1);
	else if (loop == 4)
		write_ops("rra\nrra\n", 8, 2);
	if (condition)
		write(1, "ss\n", 3);
	else
		write(1, "sa\n", 3);
	moves++;
}

//try sa to see if it makes sorted or cyclic sorted, using small recursive tree
//then check ra + sa, ra + ra + sa
//then rra + sa, rra + rra + sa
//uses ss instead of sa when two in B and smaller is on top

bool	swap_test(t_stack **a, t_stack **b, int loop)
{
	bool condition;
	
	condition = *b && (*b)->next && (*b)->final_pos < ((*b)->next->final_pos);
	if (condition)
		ss(a, b, 1);
	else
		sa(a, 1);
	if (is_sorted(*a) || is_cyclic_sorted(*a))
		return (print_case(loop, condition), 1);
	else if (condition)//backtrack ss or sa
		ss(a, b, 1);
	else
		sa(a, 1);
	if (!loop)
	{
		loop++;
		ra(a, 1);//try ra sa
		if (swap_test(a, b, loop))
			return (1);
		else
		{
			loop++;
			ra(a, 1);//try ra ra sa
			if (swap_test(a, b, loop))
				return (1);
			rra(a, 1);
		}
		rra(a, 1);//backtrack
		rra(a, 1);// try rra sa
		loop++;
		if (swap_test(a, b, loop))
			return (1);
		else
		{
			loop++;
			rra(a, 1);//try rra rra sa
			if (swap_test(a, b, loop))
				return (1);
			ra(a, 1);
		}
			ra(a, 1);
	}
	return (0);
}
