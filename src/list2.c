/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:15:39 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/30 23:27:34 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*insert_at_front(t_stack *list, int new_node_num)
{
	t_stack	*old_head;
	t_stack	*new_node;

	new_node = create_new_node(1, new_node_num);
	if (!new_node)
		(free_list(list), error_handler(ENOMEM));
	if (list == NULL)
	{
		list = new_node;
		list->tail = list;
		return (list);
	}
	old_head = list;
	list = new_node;
	new_node->next = old_head;
	old_head->prev = new_node;
	find_tail(&list);
	update_index(new_node);
	return (list);
}

t_stack	*insert_to_end(t_stack *list, int new_node_num)
{
	t_stack	*cur;
	t_stack	*new_node;

	new_node = create_new_node(INT_MAX, new_node_num);
	if (!new_node)
		(free_list(list), error_handler(ENOMEM));
	if (list == NULL)
	{
		new_node->index = 1;
		list = new_node;
		return (list);
	}
	cur = list->tail;
	new_node->index = cur->index + 1;
	cur->next = new_node;
	new_node->prev = cur;
	return (list);
}

t_stack	*update_index(t_stack *list)
{
	int		index;
	t_stack	*cur;

	cur = list;
	if (list->prev == NULL)
		index = 0;
	else
		index = list->prev->index;
	while (cur != NULL)
	{
		cur->index = ++index;
		cur = cur->next;
	}
	return (list);
}

void	find_tail(t_stack **stack)
{
	t_stack	*cur;

	cur = *stack;
	while (cur->next)
		cur = cur->next;
	(*stack)->tail = cur;
}
