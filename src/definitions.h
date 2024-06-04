/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:08:53 by dkoca             #+#    #+#             */
/*   Updated: 2024/06/01 00:20:13 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

enum	e_errors
{
	INPUT_ERROR,
	INIT_ERROR,
	ENOMEM,
};

# define INT_MAX_LEN 11
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define DONE 0
# define NOT_DONE 1

enum	e_operations
{
	TRY,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
};

# define UPPER_MEDIAN 0
# define LOWER_MEDIAN 1

# define DESCENT 0
# define ASCENT 1

# define SMALL 0
# define BIG 1

# define STACK_A 0
# define STACK_B 1 
#endif