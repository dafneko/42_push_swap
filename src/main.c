/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:40:04 by dkoca             #+#    #+#             */
/*   Updated: 2024/06/01 09:29:47 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_data(t_stacks *stacks, int ac, char **argv)
{
	stacks->a = create_dll(ac, argv, stacks);
	stacks->a->tail = stacks->a;
	find_tail(&stacks->a->tail);
	return (EXIT_SUCCESS);
}

int	main(int ac, char *av[])
{
	t_stacks	*stacks;

	if (ac < 3)
		return (EXIT_FAILURE);
	stacks = ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		return (EXIT_FAILURE);
	if (is_not_valid_input(av, ac))
		return (free_stack(stacks), error_handler(INPUT_ERROR), EXIT_FAILURE);
	init_data(stacks, ac, av);
	push_swap(&stacks->a, &stacks->b, ac);
	free_stack(stacks);
	return (EXIT_SUCCESS);
}
