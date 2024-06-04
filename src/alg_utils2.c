/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:36:28 by dkoca             #+#    #+#             */
/*   Updated: 2024/06/01 02:17:58 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_move_cost(t_stack *stack, int ac)
{
	t_stack	*cur;

	cur = stack;
	while (cur)
	{
		if (cur->location == UPPER_MEDIAN)
		{
			cur->cost = cur->index - 1;
		}
		else
			cur->cost = ft_abs(ac - cur->index + 1);
		cur = cur->next;
	}
}

void	find_cheapest(t_stack *stack)
{
	t_stack	*cur;
	int		min;

	cur = stack;
	min = INT_MAX;
	while (cur)
	{
		min = compare_costs(cur, stack, min);
		cur = cur->next;
	}
}

int	choose_op(t_stack *node, int stack)
{
	int	op;

	if (stack == STACK_A)
	{
		if (node->location == UPPER_MEDIAN)
			op = RA;
		else
			op = RRA;
	}
	else
	{
		if (node->target->location == UPPER_MEDIAN)
			op = RB;
		else
			op = RRB;
	}
	return (op);
}

void	move_cheap_to_top(t_stack **a, t_stack **b,
		void (*rotation_dir)(t_stack **, int), void (*rot_together)(t_stack **,
			t_stack **))
{
	int		op;
	t_stack	*best;

	best = (*a)->cheapest;
	op = choose_op(best, STACK_A);
	while (best->cost > best->target->cost && best->cost > 0)
	{
		rotation_dir(a, op);
		best->cost--;
	}
	op = choose_op(best, STACK_B);
	while (best->target->cost > best->cost && best->target->cost > 0)
	{
		rotation_dir(b, op);
		best->target->cost--;
	}
	while (best->cost == best->target->cost && best->cost > 0)
	{
		rot_together(a, b);
		best->cost--;
		best->target->cost--;
	}
}

void	exec_operations(t_stack **a, t_stack **b, t_stack *best)
{
	if (best->location == best->target->location)
	{
		if (best->location == UPPER_MEDIAN)
			move_cheap_to_top(a, b, rotate, rotate_a_and_b);
		else
			move_cheap_to_top(a, b, reverse_rotate, rr_a_and_b);
	}
	else if (best->location != best->target->location)
	{
		while (best->cost > 0)
		{
			find_rotation(a, best, STACK_A);
			best->cost--;
		}
		while (best->target->cost > 0)
		{
			find_rotation(b, best->target, STACK_B);
			best->target->cost--;
		}
	}
}
