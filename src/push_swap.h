/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:08:58 by dkoca             #+#    #+#             */
/*   Updated: 2024/06/01 09:27:51 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "definitions.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				cost;
	int				location;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*tail;
	struct s_stack	*cheapest;
}					t_stack;

typedef struct s_pushswap
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

int					main(int ac, char *av[]);
int					init_data(t_stacks *stacks, int ac, char **argv);
int					is_not_valid_input(char **input, int ac);
long long			ft_atoll(const char *nptr);
void				error_handler(int err);

/* list.c */
t_stack				*create_dll(int ac, char **argv, t_stacks *stacks);
t_stack				*insert_all(t_stacks *stacks, int ac, char **argv, int i);
t_stack				*search_list(t_stack *list, int key);
t_stack				*update_index(t_stack *list);
t_stack				*create_new_node(int i, int nb);
t_stack				*remove_node(t_stack *list, int key);
t_stack				*insert_at_front(t_stack *list, int new_node_num);
t_stack				*insert_to_end(t_stack *list, int new_node_num);
void				push_b(t_stack **a, t_stack **b);
void				push_a(t_stack **a, t_stack **b);
int					swap(t_stack **stack, int op);
void				swap_a_and_b(t_stack **a, t_stack **b);
void				rotate(t_stack **stack, int op);
void				rotate_a_and_b(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **stack, int op);
void				print_stacks(t_stack *a, t_stack *b);
void				rr_a_and_b(t_stack **a, t_stack **b);
void				push_swap(t_stack **a, t_stack **b, int ac);
void				print_op(int op);

/*algorithm utils*/
int					is_not_sorted(t_stack *stack, int flag);
void				find_closest(t_stack *a, t_stack *b, int flag);
void				find_target(t_stack *a, t_stack *b, int flag);
void				find_median(t_stack *stack, int ac);
void				get_min_to_top(t_stack **a);
int					find_max(t_stack *stack);

/*alg utils 2, 3*/
void				exec_operations(t_stack **a, t_stack **b, t_stack *best);
void				move_cheap_to_top(t_stack **a, t_stack **b,
						void (*rotation_dir)(t_stack **, int),
						void (*rot_together)(t_stack **, t_stack **));
void				find_cheapest(t_stack *stack);
void				find_rotation(t_stack **stack, t_stack *best, int flag);
int					compare_costs(t_stack *cur, t_stack *stack, int min);

/*algortihm*/
void				sort_small(t_stack **a, t_stack **b, int ac);
void				sort_big(t_stack **a, t_stack **b);
void				calculate_move_cost(t_stack *stack, int ac);

/*small alg*/
void				sort_two(t_stack **a);
void				sort_three(t_stack **a);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
void				sort_six(t_stack **a, t_stack **b);
void				sort_seven(t_stack **a, t_stack **b);
void				find_tail(t_stack **stack);

int					free_stack(t_stacks *stacks);
int					free_list(t_stack *stack);

int					find_min(t_stack *stack);

/*bonus*/
void				pb(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rrr(t_stack **a, t_stack **b);

#endif