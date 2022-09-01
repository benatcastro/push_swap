/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:55:12 by becastro          #+#    #+#             */
/*   Updated: 2022/09/01 15:18:32 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_general_short(t_data *data)
{
	ft_bzero(&data->stack_a->s_mv, sizeof(t_moves));
	ft_pb(&data->stack_a, &data->stack_b);
	ft_pb(&data->stack_a, &data->stack_b);
	while (data->sz_a)
	{

	}
}
