/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 06:32:31 by becastro          #+#    #+#             */
/*   Updated: 2022/09/13 13:49:56y becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_key(t_stack *stack)
{
	int		biggest;

	biggest = stack->key;
	while (stack)
	{
		if (biggest < stack->key)
			biggest = stack->key;
		stack = stack->next;
	}
	return (biggest);
}

int	ft_max_key_binary(t_stack *head)
{
	int	iteration;
	int	biggest;

	biggest = ft_max_key(head);
	iteration = 0;
	while (biggest)
	{
		biggest >>= 1;
		iteration++;
	}
	return (iteration);
}

void	ft_amy_winehouse(t_data *data)
{
	t_stack	*aux;
	int		i;
	int		iterations;

	iterations = ft_lst_size(&data->stack_b);
	i = 0;
	aux = data->stack_b;
	while (i < iterations)
	{
		ft_pa(data);
		aux = data->stack_b;
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
	ft_short_keys(data);
	i = ft_max_key_binary(data->stack_a);
	while (i--)
	{
		ft_bitmove(data, bit_pos);
		ft_amy_winehouse(data);
		bit_pos++;
	}
}
