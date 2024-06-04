/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:08:00 by dkoca             #+#    #+#             */
/*   Updated: 2024/06/01 02:31:53 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* worst cases for 7

 3 7 4 6 2 1 5 = 21
 6 3 1 5 4 7 2 = 16
*/
void	sort_seven(t_stack **a, t_stack **b)
{
	while (is_not_sorted(*a, ASCENT))
	{
		get_min_to_top(a);
		if (is_not_sorted(*a, ASCENT))
		{
			push_b(a, b);
			sort_six(a, b);
			push_a(a, b);
		}
	}
}

void	error_handler(int err)
{
	if (err == INIT_ERROR)
		ft_putendl_fd("Could not initialize.", 2);
	else if (err == ENOMEM)
		ft_putendl_fd("No memory left.", 2);
	else if (err == INPUT_ERROR)
		ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	print_op(int op)
{
	if (op == TRY)
		return ;
	else if (op == SA)
		ft_printf("sa\n");
	else if (op == SB)
		ft_printf("sb\n");
	if (op == PA)
		ft_printf("pa\n");
	if (op == PB)
		ft_printf("pb\n");
	if (op == RA)
		ft_printf("ra\n");
	if (op == RB)
		ft_printf("rb\n");
	if (op == RR)
		ft_printf("rr\n");
	if (op == RRA)
		ft_printf("rra\n");
	if (op == RRB)
		ft_printf("rrb\n");
	if (op == RRR)
		ft_printf("rra\n");
}
