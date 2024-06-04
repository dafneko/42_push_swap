/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:15:51 by dkoca             #+#    #+#             */
/*   Updated: 2024/05/30 23:27:44 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_and_b(t_stack **a, t_stack **b)
{
	if ((*a) && (*a)->next && (*b) && (*b)->next)
	{
		swap(a, TRY);
		swap(b, TRY);
		ft_printf("ss\n");
	}
}

void	rotate_a_and_b(t_stack **a, t_stack **b)
{
	if ((*a) && (*b) && (*a)->next && (*b)->next)
	{
		rotate(a, TRY);
		rotate(b, TRY);
		ft_printf("rr\n");
	}
}

void	rr_a_and_b(t_stack **a, t_stack **b)
{
	if ((*a) && (*b) && (*a)->next && (*b)->next)
	{
		reverse_rotate(a, TRY);
		reverse_rotate(b, TRY);
		ft_printf("rrr\n");
	}
}
