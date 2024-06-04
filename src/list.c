/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:05:25 by dkoca             #+#    #+#             */
/*   Updated: 2024/06/01 02:45:23 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 	next = found->next;
	prev = found->prev; */
t_stack	*remove_node(t_stack *list, int key)
{
	t_stack	*found;

	found = search_list(list, key);
	if (found != NULL)
	{
		if (found->prev == NULL && found->next)
		{
			list = found->next;
			found->next->tail = found->tail;
		}
		if (found->next != NULL)
		{
			found->next->prev = found->prev;
			found->next = update_index(found->next);
		}
		if (found->prev != NULL)
			found->prev->next = found->next;
		if (!found->prev && !found->next)
			list = NULL;
		free(found);
	}
	return (list);
}

t_stack	*search_list(t_stack *list, int key)
{
	t_stack	*cur;

	cur = list;
	while (cur != NULL)
	{
		if (cur->num == key)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

t_stack	*create_new_node(int i, int nb)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->index = i;
	new_node->num = nb;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*insert_all(t_stacks *stacks, int ac, char **argv, int i)
{
	t_stack	*head;
	t_stack	*current;
	t_stack	*new;
	int		nb;

	head = stacks->a;
	if (head == NULL)
	{
		nb = ft_atoll(argv[i]);
		head = create_new_node(i, nb);
	}
	current = head;
	while (++i < ac)
	{
		nb = ft_atoll(argv[i]);
		new = create_new_node(i, nb);
		if (!new)
			(free_stack(stacks), error_handler(ENOMEM));
		current->next = new;
		new->prev = current;
		current = new;
	}
	return (head);
}

t_stack	*create_dll(int ac, char **argv, t_stacks *stacks)
{
	int	i;

	i = 1;
	stacks->a = NULL;
	stacks->a = insert_all(stacks, ac, argv, i);
	return (stacks->a);
}

// void	print_list_backwards(t_stack *tail)
// {
// 	t_stack *cur;

// 	cur = tail;
// 	while (cur != NULL)
// 	{
// 		printf("num = [%i], address= [%p], index = [%i], location = %i\n\n",
// 			cur->num, cur, cur->index, cur->location);
// 		cur = cur->prev;
// 	}
// }

// void	print_list(t_stack *head)
// {
// 	t_stack	*cur;

// 	cur = head;
// 	while (cur != NULL)
// 	{
// 		cur = cur->next;
// 	}
// }