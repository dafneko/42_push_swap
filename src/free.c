/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:15:58 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/30 23:27:19 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (1);
}

int	free_list(t_stack *stack)
{
	t_stack	*cur;

	if (stack)
	{
		cur = stack->tail;
		while (cur && cur->prev)
		{
			cur = cur->prev;
			free(cur->next);
		}
		free(cur);
	}
	return (EXIT_SUCCESS);
}

int	free_stack(t_stacks *stacks)
{
	if (stacks && stacks->a)
		free_list(stacks->a);
	if (stacks && stacks->b)
		free_list(stacks->b);
	if (stacks)
		free(stacks);
	return (EXIT_SUCCESS);
}
