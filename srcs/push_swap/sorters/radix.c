/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 06:32:31 by becastro          #+#    #+#             */
/*   Updated: 2022/09/09 08:34:07 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_back_to_a(__attribute__((unused))t_stack **head_a, t_stack **head_b, t_data *data)
{
	t_stack	*aux;
	int		i;
	int		iterations;

	iterations = ft_lst_size(head_b);
	i = 0;
	aux = *head_b;
	while (i < iterations)
	{
		ft_pa(data);
		aux = *head_b;
		i++;
	}
}

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
	i = data->sz_a;
	ft_short_keys(data);
	while (i--)
	{
		ft_bitmove(data, bit_pos);
		ft_back_to_a(&data->stack_a, &data->stack_b, data);
		bit_pos++;
	}
	// ft_show_double_list(&data->stack_a, &data->stack_b);
}
