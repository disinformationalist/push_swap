#include "push_swap.h"

//troubleshooting utility

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		printf("index: %d     content %d  final_pos: %d\n", \
		i++, stack->content, stack->final_pos);
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