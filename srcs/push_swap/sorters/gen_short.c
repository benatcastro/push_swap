/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:40:18 by becastro          #+#    #+#             */
/*   Updated: 2022/09/01 12:42:36 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_exec_moves(t_data *data, t_moves *moves)
{
	while (moves->ra--)
		ft_ra(&data->stack_a, true);
	while (moves->rb--)
		ft_ra(&data->stack_b, true);
	while (moves->rr)
		ft_rr(&data->stack_a, &data->stack_b);
	while (moves->rra)
		ft_rra(&data->stack_a, true);
	while (moves->rrb)
		ft_rrb(&data->stack_b, true);
	while (moves->rrr)
		ft_rrr(&data->stack_a, &data->stack_b);

}

void	ft_general_short(t_data *data)
{
	size_t	list_size;
	t_moves	gen_moves;

	list_size = ft_lst_size(&data->stack_a);
	ft_pb(&data->stack_a, &data->stack_b);
	ft_pb(&data->stack_a, &data->stack_b);
	while (list_size--)
	{
		moves_a(data, &gen_moves, list_size);
		moves_b(data, &gen_moves, list_size);
		ft_exec_moves(data, &gen_moves);
	}
}
