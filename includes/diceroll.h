/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diceroll.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 00:57:23 by alan              #+#    #+#             */
/*   Updated: 2019/02/28 12:48:33 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
