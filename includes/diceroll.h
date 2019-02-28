/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diceroll.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 00:57:23 by alan              #+#    #+#             */
/*   Updated: 2019/02/28 03:55:58 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	**************************       USAGE        ***********************{{{
**	*   The nums variable should be an array of less than MAX_NUMS         *
**	*   numbers of type int. It is allocated in the init_dice function to  *
**	*   size how_many, so you just have to fill it.                        *
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
**	*                                                                      *
**	*   The diceroll function does all of this for you! Simply provide     *
**	*   it with the amount of dice to roll, how many sides they have,      *
**	*   and a function to get random numbers (more on that later)! It      *
**	*   starts up a dice struct, fills up it's random numbers with the     *
**	*   extra function, rolls all the numbers, and deletes the struct.     *
**	*                                                                      *
**	*   Here are rules for the random number function:                     *
**	*   The (*nums_source) function pointer must be a pointer to an int    *
**	*   function, that takes an already allocated t_dice pointer and       *
**	*   fills up it's nums pointer. It should only fill up to the          *
**	*   how_many variable in the t_dice pointer. It should return -1 on    *
**	*   failure (it doesn't matter what it returns if it succeeds, but     *
**	*   conventional wisdom says return (0)).                              *
**	*   Place prototypes for these functions in the "random_sources.h"     *
**	*   header file.                                                       *
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

void				diceroll(int how_many, int sides,
						int (*nums_source)(t_dice *dice));

#endif
