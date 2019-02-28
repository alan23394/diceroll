/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diceroll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:38:55 by alan              #+#    #+#             */
/*   Updated: 2019/02/28 03:51:20 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "diceroll.h"

t_dice			*init_dice(unsigned int how_many, unsigned int sides)
{
	t_dice	*new_dice;

	if (how_many > MAX_NUMS)
	{
		return (0);
	}
	new_dice = (t_dice *)ft_memalloc(sizeof(t_dice));
	new_dice->nums = (int *)ft_memalloc(sizeof(int) * how_many);
	new_dice->nums_counter = 0;
	new_dice->how_many = how_many;
	new_dice->sides = sides;
	return (new_dice);
}

void			delete_dice(t_dice *del)
{
	if (del)
	{
		if (del->nums)
		{
			ft_memdel((void **)&del->nums);
		}
		ft_memdel((void **)&del);
	}
}

int				roll(t_dice *dice)
{
	int	roll;

	if (dice->nums_counter >= dice->how_many)
	{
		return (-1);
	}
	roll = ft_abs(dice->nums[dice->nums_counter] % dice->sides) + 1;
	++(dice->nums_counter);
	return (roll);
}

void			roll_dice(t_dice *dice)
{
	unsigned int	i;
	int				result;

	i = 0;
	while (i < dice->how_many)
	{
		result = roll(dice);
		if (result == -1)
		{
			return ;
		}
		ft_printf("%u%s", result, ((i < (dice->how_many - 1)) ? ", " : ""));
		++i;
	}
	ft_putchar('\n');
}

void			diceroll(int how_many, int sides,
					int (*nums_source)(t_dice *dice))
{
	t_dice	*dice;

	dice = init_dice(how_many, sides);
	if (nums_source(dice) == -1)
	{
		return ;
	}
	roll_dice(dice);
	delete_dice(dice);
}
