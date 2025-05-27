#include "push_swap.h"

void	free_buff(t_buffer *buff)
{
	t_buffer *tmp;

	while (buff)
	{
		tmp = buff->next;
		free(buff);
		buff = tmp;
	}
}

void add_move(t_lists *all, char *move)//needs to free other lists if a failure occurs
{
	t_buffer *new;
	
	new = (t_buffer *)malloc(sizeof(t_buffer));
	if (!new)
	{
		free_stack(&all->a);
		free_stack(&all->b);
		free_buff(all->buff);
	}
	new->move = move;
	new->next = NULL;
	if (!all->tail)
	{
		all->buff = new;
		all->tail = new;
	}
	else
	{
		all->tail->next = new;
		all->tail = new;
	}
	all->count++;
}	

void	init_all(t_lists *all)
{
	all->a = NULL;
	all->b = NULL;
	all->count = 0;
	all->buff = NULL;
	all->tail = NULL;
}

void	free_all_list(t_lists *all)
{
	free_stack(&all->a);
	free_buff(all->buff);
	free(all);
}