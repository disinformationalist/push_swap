#include "push_swap.h"

//trouble shoot:
/* printf("---------\n");
print_stack(*a);	
printf("---------\n"); */

void print_case(t_lists *all, int loop, bool condition)
{
	if (loop ==  1)
		add_move(all, "ra\n");
	else if (loop == 2)
	{
		add_move(all, "ra\n");
		add_move(all, "ra\n");
	}
	else if (loop ==  3)
		add_move(all, "rra\n");
	else if (loop == 4)
	{
		add_move(all, "rra\n");
		add_move(all, "rra\n");
	}
	if (condition)
		add_move(all, "ss\n");
	else
		add_move(all, "sa\n");
}

//try sa to see if it makes sorted or cyclic sorted, using small recursive tree
//then check ra + sa, ra + ra + sa
//then rra + sa, rra + rra + sa
//uses ss instead of sa when two in B and smaller is on top

bool	swap_test(t_lists *all, int loop)
{
	bool condition;
	
	condition = all->b && all->b->next && all->b->final_pos < all->b->next->final_pos;
	if (condition)
		ss(all, 1);
	else
		sa(all, 1);
	if (is_sorted(all->a) || is_cyclic_sorted(all->a))
		return (print_case(all, loop, condition), 1);
	else if (condition)//backtrack ss or sa
		ss(all, 1);
	else
		sa(all, 1);
	if (!loop)
	{
		loop++;
		ra(all, 1);//try ra sa
		if (swap_test(all, loop))
			return (1);
		else
		{
			loop++;
			ra(all, 1);//try ra ra sa
			if (swap_test(all, loop))
				return (1);
			rra(all, 1);
		}
		rra(all, 1);//backtrack
		rra(all, 1);// try rra sa
		loop++;
		if (swap_test(all, loop))
			return (1);
		else
		{
			loop++;
			rra(all, 1);//try rra rra sa
			if (swap_test(all, loop))
				return (1);
			ra(all, 1);
		}
			ra(all, 1);
	}
	return (0);
}
