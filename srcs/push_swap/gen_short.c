/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:55:12 by becastro          #+#    #+#             */
/*   Updated: 2022/09/17 21:10:57 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "movements.h"

static int	ft_get_total_moves(t_stack *stack)
{
	t_stack	*aux;
	size_t	min;

	min = __INT_MAX__;
	aux = stack;
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

/**
 * @brief
 *
 * @param min_moves
 * @param data
 */
static void	ft_mv_to_data(size_t min_moves, t_data *data)
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

/**
 * @brief
 * Executes the movements stored in the data structure
 * @param data
 */
static void	ft_exec_fncs(t_data *data)
{
	while (data->mv.ra--)
		ft_ra(&data->stack_a, true);
	while (data->mv.rb--)
		ft_rb(&data->stack_b, true);
	while (data->mv.rr--)
		ft_rr(&data->stack_a, &data->stack_b, true);
	while (data->mv.rra--)
		ft_rra(data, true);
	while (data->mv.rrb--)
		ft_rrb(data, true);
	while (data->mv.rrr--)
		ft_rrr(data, true);
}

/**
 * @brief
 * from back to black comes back to a
 * takes all of the nodes in stack B and refills stack A
 * @param data
 */
static void	ft_amy_winehouse(t_data	*data)
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
		ft_pa(data, true);
}

/**
 * @brief
 * Function structure for the general shorting algo
 * @param data
 */
void	ft_general_short(t_data *data)
{
	ft_short_keys(data);
	ft_pb(data, true);
	ft_pb(data, true);
	while (data->sz_a)
	{
		ft_get_moves_a(data);
		ft_get_moves_b(data);
		ft_cmp_mv(data->stack_a);
		ft_mv_to_data(ft_get_total_moves(data->stack_a), data);
		ft_exec_fncs(data);
		ft_reset_stack(data->stack_a);
		ft_pb(data, true);
	}
	ft_reset_data(data);
	ft_amy_winehouse(data);
}
