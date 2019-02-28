/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dev_random.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 03:39:03 by alan              #+#    #+#             */
/*   Updated: 2019/02/28 03:48:22 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "diceroll.h"
#include <unistd.h>
#include <fcntl.h>

int		read_dev_random(t_dice *dice)
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
