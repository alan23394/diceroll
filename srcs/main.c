/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 01:21:46 by alan              #+#    #+#             */
/*   Updated: 2019/02/28 03:06:21 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "diceroll.h"
#include <unistd.h>
#include <fcntl.h>

int		read_random(t_dice *dice)
{
	int		fd;
	int		size_read;

	fd = open("/dev/random", O_RDONLY);
	size_read = read(fd, dice->nums, sizeof(int) * dice->how_many);
	if ((unsigned long)size_read < (sizeof(int) * dice->how_many))
	{
		ft_printfd(2, "read error, try again later (%lu/%lu)\n",
				(unsigned long)size_read, (sizeof(int) * dice->how_many));
		return (-1);
	}
	close(fd);
	return (0);
}

int		main(int argc, char **argv)
{
	int		rolls;
	t_dice	*dice;

	if (argc != 3)
	{
		ft_printfd(2, "usage: diceroll [number of die] [how many sides]\n");
		return (1);
	}
	rolls = ft_atoi(argv[1]);
	if (rolls > MAX_NUMS)
	{
		ft_printfd(2, "no more than %d dice at a time\n", MAX_NUMS);
		return (1);
	}
	dice = init_dice(rolls, ft_atoi(argv[2]));
	if (read_random(dice) == -1)
	{
		return (1);
	}
	roll_dice(dice);
	delete_dice(dice);
	ft_putchar('\n');
	return (0);
}
