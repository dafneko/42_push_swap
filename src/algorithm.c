/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:42:38 by dkoca             #+#    #+#             */
/*   Updated: 2024/06/01 04:18:11 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_sort(t_stack **a)
{
	t_stack	*min;

	while (is_not_sorted(*a, ASCENT))
	{
		min = search_list(*a, find_min(*a));
		if (min->location == UPPER_MEDIAN)
			rotate(a, RA);
		else
			reverse_rotate(a, RRA);
	}
}

void	sort_back_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		find_median(*a, (*a)->tail->index);
		find_target(*b, *a, BIG);
		calculate_move_cost(*a, (*a)->tail->index);
		if ((*a)->num == (*b)->target->num)
			push_a(a, b);
		else
		{
			while ((*b)->target->num != (*a)->num && (*b)->target->cost > 0)
			{
				if ((*b)->target->location == UPPER_MEDIAN)
					rotate(a, RA);
				else
					reverse_rotate(a, RRA);
				(*b)->target->cost--;
			}
			push_a(a, b);
		}
	}
	last_sort(a);
}

void	sort_big(t_stack **a, t_stack **b)
{
	t_stack	*cur_a;

	push_b(a, b);
	push_b(a, b);
	cur_a = *a;
	while (cur_a && cur_a->tail && cur_a->tail->index > 3)
	{
		find_median(*b, (*b)->tail->index);
		calculate_move_cost(*b, (*b)->tail->index);
		find_target(*a, *b, SMALL);
		find_median(*a, (*a)->tail->index);
		calculate_move_cost(*a, (*a)->tail->index);
		find_cheapest(*a);
		exec_operations(a, b, (*a)->cheapest);
		push_b(a, b);
		cur_a = *a;
	}
	sort_three(a);
	sort_back_to_a(a, b);
}

void	sort_small(t_stack **a, t_stack **b, int ac)
{
	if (ac == 2)
		sort_two(a);
	if (ac == 3)
		sort_three(a);
	if (ac == 4)
		sort_four(a, b);
	if (ac == 5)
		sort_five(a, b);
	if (ac == 6)
		sort_six(a, b);
	if (ac == 7)
		sort_seven(a, b);
}

void	push_swap(t_stack **a, t_stack **b, int ac)
{
	--ac;
	if (is_not_sorted(*a, ASCENT))
	{
		if (ac <= 7)
			sort_small(a, b, ac);
		if (ac >= 8)
			sort_big(a, b);
	}
}
