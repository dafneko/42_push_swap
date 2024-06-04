/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:16:08 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/30 23:27:41 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **a, t_stack **b)
{
	if (*a)
	{
		*b = insert_at_front(*b, (*a)->num);
		*a = remove_node(*a, (*a)->num);
		print_op(PB);
	}
}

void	push_a(t_stack **a, t_stack **b)
{
	if (*b)
	{
		*a = insert_at_front(*a, (*b)->num);
		*b = remove_node(*b, (*b)->num);
		print_op(PA);
	}
}

int	swap(t_stack **stack, int op)
{
	int	tmp;

	(void)op;
	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack)->num;
		(*stack)->num = (*stack)->next->num;
		(*stack)->next->num = tmp;
		print_op(op);
	}
	return (NOT_DONE);
}

void	rotate(t_stack **stack, int op)
{
	t_stack	*cur;
	t_stack	*old_head;

	(void)op;
	if ((*stack) && (*stack)->next)
	{
		old_head = (*stack);
		(*stack) = (*stack)->next;
		cur = old_head;
		while (cur->next != NULL)
			cur = cur->next;
		(*stack)->tail = old_head;
		old_head->prev = cur;
		cur->next = old_head;
		old_head->next->prev = NULL;
		old_head->next = NULL;
		(*stack) = update_index(*stack);
		print_op(op);
	}
}

void	reverse_rotate(t_stack **stack, int op)
{
	t_stack	*tail;
	t_stack	*new_tail;

	(void)op;
	if ((*stack) && (*stack)->next)
	{
		tail = (*stack);
		while (tail->next != NULL)
			tail = tail->next;
		new_tail = tail->prev;
		tail->next = (*stack);
		(*stack)->prev = tail;
		tail->prev->next = NULL;
		tail->prev = NULL;
		(*stack) = tail;
		(*stack)->tail = new_tail;
		*stack = update_index(*stack);
		print_op(op);
	}
}
