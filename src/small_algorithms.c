/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:04:21 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/30 23:36:31 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->num > (*a)->next->num)
		swap(a, SA);
}

void	sort_three(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (is_not_sorted(*a, ASCENT))
	{
		first = *a;
		second = first->next;
		third = (*a)->tail;
		if (first->num > second->num && second->num < third->num
			&& first->num < third->num)
			swap(a, SA);
		else if (first->num > second->num && second->num > third->num
			&& first->num > third->num)
			(swap(a, SA), reverse_rotate(a, RRA));
		else if (first->num > second->num && second->num < third->num
			&& first->num > third->num)
			rotate(a, RA);
		else if (first->num < second->num && second->num > third->num
			&& first->num < third->num)
			(swap(a, SA), rotate(a, RA));
		else if (first->num < second->num && second->num > third->num
			&& first->num > third->num)
			reverse_rotate(a, RRA);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	while (is_not_sorted(*a, ASCENT))
	{
		get_min_to_top(a);
		if (is_not_sorted(*a, ASCENT))
		{
			push_b(a, b);
			sort_three(a);
			push_a(a, b);
		}
	}
}

/* worst cases for 5 found:
4 3 1 2 5  = 11 moves
4 3 2 1 5  = 12 moves
*/

void	sort_five(t_stack **a, t_stack **b)
{
	while (is_not_sorted(*a, ASCENT))
	{
		get_min_to_top(a);
		if (is_not_sorted(*a, ASCENT))
		{
			push_b(a, b);
			sort_four(a, b);
			push_a(a, b);
		}
	}
}

void	sort_six(t_stack **a, t_stack **b)
{
	while (is_not_sorted(*a, ASCENT))
	{
		get_min_to_top(a);
		if (is_not_sorted(*a, ASCENT))
		{
			push_b(a, b);
			sort_five(a, b);
			push_a(a, b);
		}
	}
}
