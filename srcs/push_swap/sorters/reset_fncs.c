/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_fncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 05:56:00 by bena              #+#    #+#             */
/*   Updated: 2022/09/03 05:56:49 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reset_stack(t_stack	*stack)
{
	t_stack	*aux;

	aux = stack;
	while (aux)
	{
		aux->s_mv.ra = 0;
		aux->s_mv.rb = 0;
		aux->s_mv.rr = 0;
		aux->s_mv.rra = 0;
		aux->s_mv.rrb = 0;
		aux->s_mv.rrr = 0;
		aux = aux->next;
	}
}

void	ft_reset_data(t_data	*data)
{
	data->mv.ra = 0;
	data->mv.rb = 0;
	data->mv.rr = 0;
	data->mv.rra = 0;
	data->mv.rrb = 0;
	data->mv.rrr = 0;
}
