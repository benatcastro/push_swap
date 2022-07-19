/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/07/19 00:21:13 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_args(int count, char **args)
{
	int	i;
	int	j;

	i = 0;
	if (count <= 1)
	{
		ft_putstr_fd("Error, missing arguments\n", 1);
		exit (EXIT_FAILURE);
	}
	while (args[++i])
	{
		j = -1;
		while (args[i][++j])
		{
			if (!ft_isdigit(args[i][j]))
			{
				ft_putstr_fd("Error, argument number ", 1);
				ft_putnbr_fd(i, 1);
				ft_putstr_fd(" isn't a digit\n", 1);
				exit (EXIT_FAILURE);
			}
		}
	}
}
