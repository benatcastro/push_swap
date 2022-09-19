/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncs_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/09/19 19:58:16 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Takes the first element of the stack B and pushes it to the top of the stack A
If the stack B is empty it does nothing
 * @param head_a -> head of stack A
 * @param head_b -> head of stack B
 */
void	ft_pa(t_data *data, bool print)
{
	t_stack	*aux;

	if (!data->stack_b || data->sz_b == 0)
		return ;
	aux = data->stack_b;
	data->stack_b = data->stack_b->next;
	ft_lstadd_front(&data->stack_a, aux);
	data->sz_a++;
	data->sz_b--;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

/**
 * @brief
 * Takes the first element of the stack A and pushes it to the top of the stack b
If the stack a is empty it does nothing
 * @param head_a -> head of stack A
 * @param head_b -> head of stack B
 */
void	ft_pb(t_data *data, bool print)
{
	t_stack	*aux;

	if (!data->stack_a || data->sz_a == 0)
		return ;
	aux = data->stack_a;
	data->stack_a = data->stack_a->next;
	ft_lstadd_front(&data->stack_b, aux);
	data->sz_a--;
	data->sz_b++;
	if (print)
		ft_putstr_fd("pb\n", 1);
}
