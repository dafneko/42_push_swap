/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 09:23:19 by dkoca             #+#    #+#             */
/*   Updated: 2024/06/01 09:25:42 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	if (*a)
	{
		*b = insert_at_front(*b, (*a)->num);
		*a = remove_node(*a, (*a)->num);
	}
}

void	pa(t_stack **a, t_stack **b)
{
	if (*b)
	{
		*a = insert_at_front(*a, (*b)->num);
		*b = remove_node(*b, (*b)->num);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	if ((*a) && (*b) && (*a)->next && (*b)->next)
	{
		rotate(a, TRY);
		rotate(b, TRY);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	if ((*a) && (*b) && (*a)->next && (*b)->next)
	{
		reverse_rotate(a, TRY);
		reverse_rotate(b, TRY);
	}
}
