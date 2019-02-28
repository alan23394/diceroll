/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 01:21:46 by alan              #+#    #+#             */
/*   Updated: 2019/02/28 03:57:16 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "diceroll.h"
#include "random_sources.h"

int		main(int argc, char **argv)
{
	int		amount;

	if (argc != 3)
	{
		ft_printfd(2, "usage: roll [number of die] [how many sides]\n");
		return (1);
	}
	amount = ft_atoi(argv[1]);
	if (amount > MAX_NUMS)
	{
		ft_printfd(2, "no more than %d dice at a time\n", MAX_NUMS);
		return (1);
	}
	diceroll(amount, ft_atoi(argv[2]), read_dev_random);
	return (0);
}
