/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:26:47 by becastro          #+#    #+#             */
/*   Updated: 2022/09/13 17:26:52 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Iterations requiered for the maximun index to reach 0 bitswifting
 * @param max_key
 * @return int
 */
int	ft_max_key_binary(size_t max_key)
{
	size_t	i;

	i = 0;
	while (max_key)
	{
		max_key >>= 1;
		i++;
	}
	return (i);
}

/**
 * @brief
 * sorts the keys of the stack (sorted before) using the radix method
 * @param data
 * @param bit_pos
 */
static void	ft_bitmove(t_data *data, size_t bit_pos)
{
	size_t	i;
	size_t	j;
	t_stack	*aux;

	j = -1;
	i = data->sz_a;
	aux = data->stack_a;
	while (i > ++j)
	{
		if (aux->key & (1 << bit_pos))
			ft_ra(&data->stack_a, true);
		else
			ft_pb(data);
		aux = data->stack_a;
	}
}

void	ft_radix(t_data *data)
{
	size_t	i;
	size_t	bit_pos;

	bit_pos = 0;
	ft_short_keys(data);
	i = ft_max_key_binary(data->sz_a);
	while (i--)
	{
		ft_bitmove(data, bit_pos);
		while (data->sz_b)
			ft_pa(data);
		bit_pos++;
	}
}
