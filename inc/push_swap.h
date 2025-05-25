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

//# define TOL 5

//counter for total moves to sort
extern int moves;

//buffer to save moves
/* 
typedef struct s_buffer
{
	int positon;
	char buffer[3][100000];
} t_buffer; */

//types to int buffer

/* typedef enum e_op
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_op; */

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

typedef struct s_data
{
	t_stack **a;
	t_stack **b;
	//add some kind of buffer for ops (list for resize?)
} t_data;

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
void	move_to_top_a(t_stack **a, t_stack *node);
void	add_node(t_stack **stack, char **av, int *tab, long n);
void	ft_assign(t_stack *a, int *tab, int len);
t_stack	*lowest(t_stack *stack);
t_stack	*highest(t_stack *stack);
t_stack	*ft_last(t_stack *lst);
t_stack	*stack_copy(t_stack *to_copy);
void	print_stack(t_stack *stack);


/****SORTING****/
int		leave_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int		is_cyclic_sorted(t_stack *stack);
void	push_swap(t_stack **a, t_stack **b, int len);
void	sort_3(t_stack **stack);
void	sort_5(t_stack **a, t_stack **b);
void	ft_quicksort(int *tab, int start, int end);
void	sort_now(t_stack **a, t_stack **b);
void	take_it_home(t_stack **a, t_stack **b);
void	take_it_home_100(t_stack **a, t_stack **b);
void	take_it_home_500(t_stack **a, t_stack **b);
void	cycle(t_stack **a);
void	get_biggest_cyclic(t_stack *a, int start, int biggest);


/****ROUTES****/
void	route_1(t_stack **a, t_stack **b, t_stack *target, t_stack *node);
void	route_2(t_stack **a, t_stack **b, t_stack *target, t_stack *node);
void	route_3(t_stack **a, t_stack **b, t_stack *target, t_stack *node);
void	route_4(t_stack **a, t_stack **b, t_stack *target, t_stack *node);
void	route_5(t_stack **a, t_stack **b, t_stack *target, t_stack *node);
void	route_6(t_stack **a, t_stack **b, t_stack *target, t_stack *node);

/****TARGETS AND COST****/
int		get_least_cost(t_stack *target, t_stack *node, t_stack *a, t_stack *b);
void	set_return_cost(t_stack *a, t_stack *b);
void	take_route(t_stack **a, t_stack **b, t_stack *target, t_stack *node);
t_stack	*closest_match_target(t_stack *a, int needed);
t_stack	*get_cheapest(t_stack *stack, int num);
t_stack	*get_cheapest_2(t_stack *stack, int num);
t_stack *get_2nd_cheapest(t_stack *stack, int num, t_stack *cheapest);
t_stack	*get_cheapest_return(t_stack *b);
t_stack	*get_cheapest_return_interval(t_stack *b, int start, int end);

/***STACK OPS***/
void	sa(t_stack **a, int checker);
void	sb(t_stack **b, int checker);
void	ss(t_stack **a, t_stack **b, int checker);
void	pa(t_stack **a, t_stack **b, int checker);
void	pb(t_stack **b, t_stack **a, int checker);
void	ra(t_stack **a, int checker);
void	rb(t_stack **b, int checker);
void	rr(t_stack **a, t_stack **b, int checker);
void	rra(t_stack **a, int checker);
void	rrb(t_stack **b, int checker);
void	rrr(t_stack **a, t_stack **b, int checker);

/**** CLEAN UP ****/
void	free_stack(t_stack **stack);
void	free_args(char **av);
void	free_all(t_stack **a, char **av, int *tab);
int		error_doubles(t_stack *a, int num);
int		error_value(char *str);

#endif
