/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:55:12 by becastro          #+#    #+#             */
/*   Updated: 2022/09/09 04:05:05 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_total_moves(t_data *data)
{
	t_stack	*aux;
	int		min;

	min = __INT_MAX__;
	aux = data->stack_a;
	while (aux)
	{
		aux->s_mv.moves += aux->s_mv.ra;
		aux->s_mv.moves += aux->s_mv.rb;
		aux->s_mv.moves += aux->s_mv.rr;
		aux->s_mv.moves += aux->s_mv.rra;
		aux->s_mv.moves += aux->s_mv.rrb;
		aux->s_mv.moves += aux->s_mv.rrr;
		if (min > aux->s_mv.moves)
			min = aux->s_mv.moves;
		aux = aux->next;
	}
	return (min);
}

static void	ft_mv_to_data(int min_moves, t_data *data)
{
	t_stack	*aux;

	aux = data->stack_a;
	while (min_moves != aux->s_mv.moves)
		aux = aux->next;
	data->mv.ra = aux->s_mv.ra;
	data->mv.rb = aux->s_mv.rb;
	data->mv.rr = aux->s_mv.rr;
	data->mv.rra = aux->s_mv.rra;
	data->mv.rrb = aux->s_mv.rrb;
	data->mv.rrr = aux->s_mv.rrr;
}

static void	ft_exec_fncs(t_data *data)
{
	while (data->mv.ra--)
		ft_ra(&data->stack_a, true);
	while (data->mv.rb--)
		ft_rb(&data->stack_b, true);
	while (data->mv.rr--)
		ft_rr(&data->stack_a, &data->stack_b);
	while (data->mv.rra--)
		ft_rra(&data->stack_a, true);
	while (data->mv.rrb--)
		ft_rrb(&data->stack_b, true);
	while (data->mv.rrr--)
		ft_rrr(&data->stack_a, &data->stack_b);
}

static void	ft_refill_a(t_data	*data)
{
	t_stack	*aux;

	aux = data->stack_b;
	while (aux->key != data->sz_b)
	{
		aux = aux->next;
		data->mv.rb++;
	}
	if (data->mv.rb > (data->sz_b / 2))
	{
		data->mv.rb = 0;
		while (aux)
		{
			aux = aux->next;
			data->mv.rrb++;
		}
	}
	ft_exec_fncs(data);
	while (data->sz_b)
		ft_pa(data);
}

void	ft_general_short(t_data *data)
{
	ft_short_keys(data);
	print_struct(data);
	ft_pb(data);
	ft_pb(data);
	while (data->sz_a)
	{
		ft_get_moves_a(data);
		ft_get_moves_b(data);
		ft_cmp_mv(data->stack_a);
		ft_mv_to_data(ft_get_total_moves(data), data);
		ft_exec_fncs(data);
		ft_reset_stack(data->stack_a);
		ft_pb(data);
	}
	ft_reset_data(data);
	ft_refill_a(data);
	print_struct(data);
	//print_struct(data);
	//ft_show_double_list(&data->stack_a, &data->stack_b);
}
