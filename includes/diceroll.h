/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diceroll.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 00:57:23 by alan              #+#    #+#             */
/*   Updated: 2019/02/28 01:59:48 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	**************************       USAGE        ***********************{{{
**	*   The nums variable should be an array of amount MAX_NUMS numbers    *
**	*   of type unsigned int. It is allocated in the init_dice function,   *
**	*   so you just have to fill it.                                       *
**	*                                                                      *
**	*   When grabbing a number from nums, you must index it with the       *
**	*   nums_counter variable.                                             *
**	*   It should NOT be indexed if nums_counter is >= MAX_NUMS!           *
**	*   Remember to incrememt nums_counter each time you take a number     *
**	*   from nums, to keep track of how many numbers have been taken.      *
**	*********************************************************************}}}
*/

#ifndef DICEROLL_H
# define DICEROLL_H

# define MAX_NUMS (10)

typedef struct		s_dice
{
	unsigned int	*nums;
	unsigned int	nums_counter;
}					t_dice;

t_dice				*init_dice();
void				delete_dice(t_dice *del);

void				roll_many(int how_many, int sides);

#endif
