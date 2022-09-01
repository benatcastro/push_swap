/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:55:12 by becastro          #+#    #+#             */
/*   Updated: 2022/09/01 16:13:10 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_general_short(t_data *data)
{
	ft_find_node(&data->stack_a, 0)->key = ft_lastnode(&data->stack_a)->key + 1;
	ft_bzero(&data->stack_a->s_mv, sizeof(t_moves));
	print_struct(data);
	ft_pb(&data->stack_a, &data->stack_b, data);
	ft_pb(&data->stack_a, &data->stack_b, data);
	while (data->sz_a)
	{
		ft_get_moves_a(data);
		ft_get_moves_b(data);
		data->sz_a--;
	}
}
