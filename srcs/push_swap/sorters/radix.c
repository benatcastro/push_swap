/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 06:32:31 by becastro          #+#    #+#             */
/*   Updated: 2022/09/09 06:41:39 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix(t_data *data)
{
	size_t	i;
	size_t	bit_pos;

	bit_pos = 0;
	i = data->sz_a;
	ft_short_keys(data);
	ft_show_double_list(&data->stack_a, &data->stack_b);
	while (i--)
	{
		bit_pos++;
	}
}
