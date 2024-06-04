/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 06:16:00 by dkoca             #+#    #+#             */
/*   Updated: 2024/06/01 09:40:36 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_op(char *op, t_stack **a, t_stack **b)
{
	if (ft_strncmp(op, "pa", 2) == 0)
		pa(a, b);
	else if (ft_strncmp(op, "pb", 2) == 0)
		pb(a, b);
	else if (ft_strncmp(op, "sa", 2) == 0)
		swap(a, TRY);
	else if (ft_strncmp(op, "sb", 2) == 0)
		swap(b, TRY);
	else if (ft_strncmp(op, "ss", 2) == 0)
		swap_a_and_b(a, b);
	else if (ft_strncmp(op, "ra", 2) == 0)
		rotate(a, TRY);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rotate(b, TRY);
	else if (ft_strncmp(op, "rra", 3) == 0)
		reverse_rotate(a, TRY);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		reverse_rotate(b, TRY);
	else if (ft_strncmp(op, "rr", 2) == 0)
		rr(a, b);
	else if (ft_strncmp(op, "rrr", 3) == 0)
		rrr(a, b);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	read_input(char op[4], t_stacks *stacks)
{
	int	i;

	i = 0;
	while (read(STDIN_FILENO, &op[i], 1))
	{
		if (i > 3)
			(free_stack(stacks), ft_putendl_fd("error", STDERR_FILENO),
				exit(1));
		if (op[i] == '\n')
		{
			op[i] = '\0';
			if (exec_op(op, &stacks->a, &stacks->b))
				return (EXIT_FAILURE);
			i = 0;
		}
		else
			i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **argv)
{
	t_stacks	*stacks;
	char		op[4];

	if (ac < 3)
		exit(EXIT_FAILURE);
	if (is_not_valid_input(argv, ac))
		return (error_handler(INPUT_ERROR), 1);
	stacks = ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		return (EXIT_FAILURE);
	stacks->a = create_dll(ac, argv, stacks);
	stacks->a->tail = stacks->a;
	find_tail(&stacks->a->tail);
	if (read_input(op, stacks))
		(free_stack(stacks), ft_putendl_fd("error", STDERR_FILENO), exit(1));
	if (!is_not_sorted(stacks->a, ASCENT) && !stacks->b)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		return (free_stack(stacks), ft_putendl_fd("KO", STDERR_FILENO), 1);
	return (free_stack(stacks), EXIT_SUCCESS);
}

// void	print_stacks(t_stack *a, t_stack *b)
// {
// 	t_stack	*cur_a;
// 	t_stack	*cur_b;

// 	cur_a = a;
// 	cur_b = b;
// 	ft_printf("\nSTACK A:          STACK B:\n\n");
// 	while (cur_a || cur_b)
// 	{
// 		if (cur_a != NULL)
// 		{
// 			ft_printf("    %i      |", cur_a->num);
// 			if (cur_b == NULL)
// 				ft_putendl_fd("    ", STDOUT_FILENO);
// 		}
// 		if (cur_b != NULL)
// 		{
// 			if (cur_a == NULL)
// 				ft_printf("           |");
// 			ft_printf("        %i", cur_b->num);
// 			ft_putendl_fd("    ", STDOUT_FILENO);
// 			cur_b = cur_b->next;
// 		}
// 		if (cur_a != NULL)
// 			cur_a = cur_a->next;
// 	}
// }
