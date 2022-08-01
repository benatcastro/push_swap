/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/08/01 02:27:10 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_duplicate_arg(char **args, char *c_arg)
{
	int	i;
	int	arg;
	int	tmp;
	int	check;

	check = 0;
	arg = ft_atoi(c_arg);
	i = -1;
	while (args[++i])
	{
		tmp = ft_atoi(args[i]);
		if (arg == tmp)
			check++;
		else if (arg == tmp && check != 0)
		{
			ft_putstr_fd("Error, argument number ", 1);
			ft_putnbr_fd(i, 1);
			ft_putstr_fd(" appears more than 1 time ❌\n", 1);
			exit (EXIT_FAILURE);
		}
	}
}

void	ft_check_args(int count, char **args)
{
	int	i;
	int	j;

	i = 0;
	if (count <= 1)
	{
		ft_putstr_fd("Error, missing arguments ❌\n", 1);
		exit (EXIT_FAILURE);
	}
	while (args[++i])
	{
		j = -1;
		while (args[i][++j])
		{
			ft_duplicate_arg(args, args[i]);
			if (!ft_isdigit(args[i][j]))
			{
				ft_putstr_fd("Error, argument number ", 1);
				ft_putnbr_fd(i, 1);
				ft_putstr_fd(" isn't a digit ❌\n", 1);
				exit (EXIT_FAILURE);
			}
		}
	}
}
