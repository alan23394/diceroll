/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diceroll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 23:38:55 by alan              #+#    #+#             */
/*   Updated: 2019/02/28 01:59:54 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "diceroll.h"

t_dice	*init_dice()
{
	t_dice	*new_dice;

	new_dice = (t_dice *)ft_memalloc(sizeof(t_dice));
	new_dice->nums = (unsigned int)ft_memalloc(sizeof(unsigned int) * MAX_NUMS);
	new_dice->nums_counter = 0;
	return (new_dice);
}

void	delete_dice(t_dice *del)
{
	if (del)
	{
		if (del->nums)
		{
			ft_memdel(del->nums);
		}
		ft_memdel(del);
	}
}

int		roll(int sides)
{
	int	roll;

	if (nums_counter >= MAX_NUMS)
		return (-1);
	roll = ft_abs(nums[nums_counter] % sides);
	++nums_counter;
	return (roll);
}

void	roll_many(int how_many, int sides)
{
	int	result;

	while (how_many > 0)
	{
		result = roll(sides);
		ft_putnbr(result);
		if (how_many > 1)
			ft_putstr(", ");
		--how_many;
	}
}
