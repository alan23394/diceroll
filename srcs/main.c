/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 01:21:46 by alan              #+#    #+#             */
/*   Updated: 2019/02/28 01:30:09 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "diceroll.h"
#include <unistd.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		size_read;
	int		rolls;

	if (argc != 3)
	{
		ft_printfd(2, "usage: diceroll [number of die] [how many sides]\n");
		return (1);
	}
	rolls = ft_atoi(argv[1]);
	if (rolls > MAX_NUMS)
	{
		ft_printfd(2, "no more than 10 dice at a time\n");
		return (1);
	}
	fd = open("/dev/random", O_RDONLY);
	size_read = read(fd, nums, sizeof(unsigned int) * MAX_NUMS);
	if ((unsigned long)size_read < (sizeof(unsigned int) * MAX_NUMS))
	{
		ft_printfd(2, "read error, try again later\n");
		return (1);
	}
	roll_many(rolls, ft_atoi(argv[1]));
	ft_putchar('\n');
	return (0);
}
