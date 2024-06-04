/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 00:49:36 by dkoca             #+#    #+#             */
/*   Updated: 2024/06/01 02:18:40 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_not_sorted(t_stack *stack, int flag)
{
	t_stack	*tmp;

	if (stack == NULL)
		return (EXIT_FAILURE);
	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->num > tmp->next->num && flag == ASCENT)
			return (EXIT_FAILURE);
		else if (tmp->num < tmp->next->num && flag == DESCENT)
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

int	find_max(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*next;
	int		max;

	cur = stack;
	next = stack->next;
	max = cur->num;
	while (cur && next)
	{
		if (next->num > cur->num)
			max = next->num;
		cur = cur->next;
		next = next->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*next;
	int		min;

	cur = stack;
	next = stack->next;
	min = cur->num;
	while (cur && next)
	{
		if (next->num < cur->num)
			min = next->num;
		cur = cur->next;
		next = next->next;
	}
	return (min);
}

void	find_rotation(t_stack **stack, t_stack *best, int flag)
{
	int	op;

	if (best->location == UPPER_MEDIAN)
	{
		if (flag == STACK_A)
			op = RA;
		else
			op = RB;
		rotate(stack, op);
	}
	else
	{
		if (flag == STACK_A)
			op = RRA;
		else
			op = RRB;
		reverse_rotate(stack, op);
	}
}

int	compare_costs(t_stack *cur, t_stack *stack, int min)
{
	if (cur->location != cur->target->location && cur->cost
		+ cur->target->cost < min)
	{
		min = cur->cost + cur->target->cost;
		stack->cheapest = cur;
	}
	else if (cur->location == cur->target->location)
	{
		if (cur->cost >= cur->target->cost && min > cur->cost)
		{
			min = cur->cost;
			stack->cheapest = cur;
		}
		else if (cur->cost < cur->target->cost && min > cur->target->cost)
		{
			min = cur->target->cost;
			stack->cheapest = cur;
		}
	}
	return (min);
}
