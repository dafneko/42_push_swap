/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:05:49 by dkoca             #+#    #+#             */
/*   Updated: 2024/06/01 16:02:52 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_closest(t_stack *a, t_stack *b, int flag)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	int		prev_diff;
	int		diff;

	cur_b = b;
	cur_a = a;
	diff = 0;
	prev_diff = 0;
	while (cur_b)
	{
		if ((cur_b->num < cur_a->num && flag == SMALL)
			|| (cur_b->num > cur_a->num && flag == BIG))
		{
			diff = ft_abs(cur_a->num - cur_b->num);
			if (prev_diff > 0 && diff > prev_diff)
				;
			else
			{
				cur_a->target = cur_b;
				prev_diff = diff;
			}
		}
		cur_b = cur_b->next;
	}
}

void	find_target(t_stack *a, t_stack *b, int flag)
{
	t_stack	*cur_a;

	cur_a = a;
	while (cur_a)
	{
		cur_a->target = cur_a;
		find_closest(cur_a, b, flag);
		if (cur_a->target->num == cur_a->num && flag == SMALL)
			cur_a->target = search_list(b, find_max(b));
		else if (cur_a->target->num == cur_a->num && flag == BIG)
			cur_a->target = search_list(b, find_min(b));
		cur_a = cur_a->next;
	}
}

void	find_median(t_stack *stack, int ac)
{
	t_stack	*cur;

	cur = stack;
	while (cur)
	{
		if (cur->index <= ac / 2)
			cur->location = UPPER_MEDIAN;
		else
			cur->location = LOWER_MEDIAN;
		cur = cur->next;
	}
}

void	get_min_to_top(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	first = *a;
	second = first->next;
	last = (*a)->tail;
	if (first->num < second->num && first->num < last->num)
		return ;
	else if (second->num < first->num && second->num < last->num
		&& first->num > last->num)
		rotate(a, RA);
	else if (second->num < first->num && second->num < last->num)
		swap(a, SA);
	else if (last->num < first->num && last->num < second->num)
		reverse_rotate(a, RRA);
}
