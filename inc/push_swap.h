/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:50:16 by jhotchki          #+#    #+#             */
/*   Updated: 2024/01/04 09:48:01 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INTMIN -2147483648
# define INTMAX 2147483647

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

//counter for total moves to sort
extern int moves;

//buffer to save moves

typedef struct s_buffer
{
	char 			*move;
	struct s_buffer *next;
} t_buffer;

typedef struct s_stack
{
	int				content;
	int				final_pos;
	int				curr_pos;
	int				cost;
	int				above_mid;
	int				return_cost;
	bool			leave;
	int				direction;
	struct s_stack	*target;
	struct s_stack	*swap_target;
	bool			use_swap;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;


typedef struct s_lists
{
	t_stack 	*a;
	t_stack 	*b;
	t_buffer	*buff;
	t_buffer	*tail;
	int 		count;

} t_lists;

typedef struct s_params
{
	t_stack	*curr;
	t_stack	*nxt_st;
	int		i;
	int		min_diff;
}	t_params;

/*** UTILITY FUNCTIONS ***/
int		len_av(char **av);
int		ft_size(t_stack *lst);
int		get_curr_pos(t_stack *stack, t_stack *node);
char	**ft_join_args(char **argv);
long	ft_atoil(const char *nptr);
void	check_and_build_stack(t_stack **a, char **av, int *tab, int i);
void	init(t_stack **a, char **av, int len);
void	set_curr_pos_cost(t_stack *stack);
void	move_to_top_a(t_lists *all, t_stack *node);
void	add_node(t_stack **stack, char **av, int *tab, long n);
void	ft_assign(t_stack *a, int *tab, int len);
t_stack	*lowest(t_stack *stack);
t_stack	*highest(t_stack *stack);
t_stack	*ft_last(t_stack *lst);
t_stack	*stack_copy(t_stack *to_copy);
void	print_stack(t_stack *stack);

void	write_ops(const char *s, int len, int cost);
bool	swap_test(t_lists *all, int loop);
void	add_move(t_lists *all, char *move);
void	print_moves(t_buffer *buff);



/****SORTING****/
int		leave_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int		is_cyclic_sorted(t_stack *stack);

void	sort_3(t_lists *all, t_stack *stack);

void	sort_small(t_lists *all, t_stack *a);
void	push_swap(t_lists *all, t_stack *a, int len);


void	ft_quicksort(int *tab, int start, int end);
void	sort_now(t_lists *all, t_stack *a);

void	take_it_home_100(t_lists *all);
void	take_it_home_500(t_lists *all);
void	take_it_home(t_lists *all);
void	cycle(t_lists *all);

void	get_biggest_cyclic(t_stack *a, int start, int biggest);

/*SOME SORT 5 HARDCODES*/

int		rasararasara(t_lists *all);
int		pbpbssparrapara(t_lists *all);
int		sararasararasa(t_lists *all);
int		rapbpbsbrapapa(t_lists *all);
int		rrapbrrarrasapara(t_lists *all);

/****ROUTES****/
void	route_1(t_lists *all, t_stack *target, t_stack *node);
void	route_2(t_lists *all, t_stack *target, t_stack *node);
void	route_3(t_lists *all, t_stack *target, t_stack *node);
void	route_4(t_lists *all, t_stack *target, t_stack *node);
void	route_5(t_lists *all, t_stack *target, t_stack *node);
void	route_6(t_lists *all, t_stack *target, t_stack *node);

/****TARGETS AND COST****/
int		get_least_cost(t_stack *target, t_stack *node, t_stack *a, t_stack *b);
void	set_return_cost(t_stack *a, t_stack *b);
void	take_route(t_lists *all, t_stack *target, t_stack *node);
t_stack	*closest_match_target(t_stack *a, int needed);
t_stack	*get_cheapest(t_stack *stack, int num);
t_stack	*get_cheapest_2(t_stack *stack, int num);
t_stack *get_2nd_cheapest(t_stack *stack, int num, t_stack *cheapest);
t_stack	*get_cheapest_return(t_stack *b);
t_stack	*get_cheapest_return_interval(t_stack *b, int start, int end);

/***STACK OPS***/
void	sa(t_lists *all, int checker);
void	sb(t_lists *all, int checker);
void	ss(t_lists *all, int checker);
void	pa(t_lists *all, int checker);
void	pb(t_lists *all, int checker);
void	ra(t_lists *all, int checker);
void	rb(t_lists *all, int checker);
void	rr(t_lists *all, int checker);
void	rra(t_lists *all, int checker);
void	rrb(t_lists *all, int checker);
void	rrr(t_lists *all, int checker);

/**** CLEAN UP ****/
void	free_stack(t_stack **stack);
void	free_args(char **av);
void	free_all(t_stack **a, char **av, int *tab);
int		error_doubles(t_stack *a, int num);
int		error_value(char *str);

#endif
