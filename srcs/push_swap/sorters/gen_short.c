/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:55:12 by becastro          #+#    #+#             */
/*   Updated: 2022/09/01 17:17:12 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_total_moves(t_data *data)
{
	t_stack	*aux;
	int		min;

	min = INT16_MAX;
	aux = data->stack_a;
	while (aux)
	{
		aux->s_mv.moves += aux->s_mv.ra;
		aux->s_mv.moves += aux->s_mv.rb;
		aux->s_mv.moves += aux->s_mv.rr;
		aux->s_mv.moves += aux->s_mv.rra;
		aux->s_mv.moves += aux->s_mv.rrb;
		aux->s_mv.moves += aux->s_mv.rrr;
		if (min > (int)aux->s_mv.moves)
			min = aux->s_mv.moves;
		aux = aux->next;
	}
	return (min);
}

static void	ft_mv_to_data(int min_moves, t_data *data)
{
	t_stack	*aux;

	(void)min_moves;
	aux = data->stack_a;
	data->mv.ra = aux->s_mv.ra;
	data->mv.rb = aux->s_mv.rb;
	data->mv.rr = aux->s_mv.rr;
	data->mv.rra = aux->s_mv.rra;
	data->mv.rrb = aux->s_mv.rrb;
	data->mv.rrr = aux->s_mv.rrr;
}

static void	ft_exec_fncs(t_data *data)
{
	print_data(data);
	//sleep(1000);
	while (data->mv.ra--)
		ft_ra(&data->stack_a, true);
	while (data->mv.rb--)
		ft_rb(&data->stack_a, true);
	while (data->mv.rr--)
		ft_rr(&data->stack_a, &data->stack_b);
	while (data->mv.rra--)
		ft_rra(&data->stack_a, true);
	while (data->mv.rrb--)
		ft_rrb(&data->stack_b, true);
	while (data->mv.rrr--)
		ft_rrr(&data->stack_a, &data->stack_b);
}

void	ft_general_short(t_data *data)
{
	int i = 1;
	ft_find_node(&data->stack_a, 0)->key = ft_lastnode(&data->stack_a)->key + 1;
	ft_bzero(&data->stack_a->s_mv, sizeof(t_moves));
	ft_bzero(&data->mv, sizeof(t_moves));
	ft_pb(&data->stack_a, &data->stack_b, data);
	ft_pb(&data->stack_a, &data->stack_b, data);
	while (i--)
	{
		ft_get_moves_a(data);
		ft_get_moves_b(data);
		ft_mv_to_data(ft_get_total_moves(data), data);
		//print_struct(data);
		ft_exec_fncs(data);
	}
	print_struct(data);
}
