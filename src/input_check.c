/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:16:10 by dkoca             #+#    #+#             */
/*   Updated: 2024/06/01 09:28:56 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *nptr)
{
	long long	n;
	int			m;

	n = 0;
	m = 1;
	if ((*nptr == 32) || (*nptr > 8 && *nptr < 14))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			m *= -1;
		nptr++;
	}
	while (*nptr > 47 && *nptr < 58)
	{
		n *= 10;
		n = n + (*nptr - 48);
		nptr++;
	}
	n *= m;
	return (n);
}

int	is_not_num(const char *nptr)
{
	if (ft_strlen(nptr) == 0)
		return (EXIT_FAILURE);
	if ((*nptr == 32) || (*nptr > 8 && *nptr < 14))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			return (EXIT_FAILURE);
		nptr++;
	}
	return (EXIT_SUCCESS);
}

int	is_not_unique(char **arr, int ac)
{
	int	count;

	count = ac;
	while (--ac > 0)
	{
		count = ac;
		while (--count > 0)
			if (ft_atoll(arr[ac]) == ft_atoll(arr[count]))
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	is_not_int(char *arr)
{
	long long	num;

	num = 0;
	if (ft_strlen(arr) > INT_MAX_LEN)
		return (EXIT_FAILURE);
	num = ft_atoll(arr);
	if (num > INT_MAX || num < INT_MIN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_not_valid_input(char **input, int ac)
{
	int	count;

	count = ac;
	while (--ac > 0)
	{
		if (is_not_num(input[ac]))
			return (EXIT_FAILURE);
		if (is_not_int(input[ac]))
			return (EXIT_FAILURE);
	}
	if (is_not_unique(input, count))
		return (EXIT_FAILURE);
	return (0);
}
