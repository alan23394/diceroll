/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diceroll.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 00:57:23 by alan              #+#    #+#             */
/*   Updated: 2019/02/28 03:18:14 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	**************************       USAGE        ***********************{{{
**	*   The nums variable should be an array of less than MAX_NUMS         *
**	*   numbers of type unsigned int. It is allocated in the init_dice     *
**	*   function to size how_many, so you just have to fill it.            *
**	*   The init function will return (0) if you give it a value for       *
**	*   how_many that is larger than MAX_NUMS.                             *
**	*                                                                      *
**	*   When grabbing a number from nums, you must index it with the       *
**	*   nums_counter variable.                                             *
**	*   It should NOT be indexed if nums_counter is >= how_many!           *
**	*   Remember to incrememt nums_counter each time you take a number     *
**	*   from nums, to keep track of how many numbers have been taken.      *
**	*   Note: this all is implemented in the roll function, which          *
**	*   returns the result of the index.                                   *
**	*********************************************************************}}}
*/

#ifndef DICEROLL_H
# define DICEROLL_H

# define MAX_NUMS (10)

typedef struct		s_dice
{
	int				*nums;
	unsigned int	nums_counter;
	unsigned int	how_many;
	unsigned int	sides;
}					t_dice;

t_dice				*init_dice(unsigned int how_many, unsigned int sides);
void				delete_dice(t_dice *del);

int					roll(t_dice *dice);
void				roll_dice(t_dice *dice);

#endif
