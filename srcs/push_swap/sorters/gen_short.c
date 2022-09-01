/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:40:18 by becastro          #+#    #+#             */
/*   Updated: 2022/09/01 13:53:20 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_exec_moves(t_data *data, t_moves *moves)
{
	print_struct(data, moves);
	//sleep(100);
	while (moves->ra--)
		ft_ra(&data->stack_a, true);
	while (moves->rb--)
		ft_rb(&data->stack_b, true);
	while (moves->rr--)
	{
		printf("test (%d)\n", moves->rr);
		ft_rr(&data->stack_a, &data->stack_b);
		sleep(100);
	}
	while (moves->rra--)
		ft_rra(&data->stack_a, true);
	while (moves->rrb--)
		ft_rrb(&data->stack_b, true);
	while (moves->rrr--)
		ft_rrr(&data->stack_a, &data->stack_b);

}

void	ft_general_short(t_data *data)
{
	size_t	list_size;
	t_moves	gen_moves;

	ft_find_node(&data->stack_a, 0)->key = ft_lastnode(&data->stack_a)->key + 1;
	list_size = ft_lst_size(&data->stack_a);
	ft_pb(&data->stack_a, &data->stack_b);
	ft_pb(&data->stack_a, &data->stack_b);
	ft_bzero(&gen_moves, sizeof(t_moves));
	while (list_size--)
	{
		moves_a(data, &gen_moves, list_size);
		print_struct(data, &gen_moves);
		moves_b(data, &gen_moves, list_size);
		print_struct(data, &gen_moves);
		ft_exec_moves(data, &gen_moves);
		ft_pa(&data->stack_a, &data->stack_b);
	}
}
