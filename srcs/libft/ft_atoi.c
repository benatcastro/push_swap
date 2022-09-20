/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:48:44 by bena              #+#    #+#             */
/*   Updated: 2022/09/20 07:45:13 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

static void	swap_error(int64_t n)
{
	if (n > INT_MAX)
	{
		ft_putstr_fd("Error\nInt value is greater than max int ❌\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (n < -2147483648)
	{
		ft_putstr_fd("Error\nInt value is lower than min int ❌\n", 2);
		exit(EXIT_FAILURE);
	}
	return ;
}

int	ft_atoi(const char *nptr)
{
	int			sign;
	int64_t		nbr;
	size_t		i;

	nbr = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\f'
		|| nptr[i] == '\r' || nptr[i] == '\n' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		nbr *= 10;
		nbr += (nptr[i] - '0');
		i++;
	}
	swap_error(nbr * sign);
	return (nbr * sign);
}
