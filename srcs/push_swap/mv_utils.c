/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:06:54 by becastro          #+#    #+#             */
/*   Updated: 2022/09/17 15:20:21 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_get_key(size_t ref, t_stack *stack)
{
	t_stack	*aux;
	size_t	i;
	size_t	max;

	i = 0;
	max = 0;
	aux = stack;
	while (aux)
	{
		if (aux->key > i && aux->key < ref)
			i = aux->key;
		if (aux->key > max)
			max = aux->key;
		aux = aux->next;
	}
	if (!i)
		return (max);
	return (i);
}

void	ft_get_moves_a(t_data *data)
{
	t_stack	*stack;
	t_stack	*aux;

	stack = data->stack_a;
	while (stack)
	{
		aux = data->stack_a;
		while (stack->key != aux->key)
		{
			stack->s_mv.ra++;
			aux = aux->next;
		}
		if (stack->s_mv.ra > (data->sz_a / 2))
		{
			stack->s_mv.ra = 0;
			while (aux)
			{
				stack->s_mv.rra++;
				aux = aux->next;
			}
		}
		stack = stack->next;
	}
}

void	ft_get_moves_b(t_data *data)
{
	t_stack	*stack;
	t_stack	*aux;
	size_t	ref;

	stack = data->stack_a;
	while (stack)
	{
		aux = data->stack_b;
		ref = ft_get_key(stack->key, data->stack_b);
		while (ref != aux->key)
		{
			stack->s_mv.rb++;
			aux = aux->next;
		}
		if (stack->s_mv.rb > (data->sz_b / 2))
		{
			stack->s_mv.rb = 0;
			while (aux)
			{
				stack->s_mv.rrb++;
				aux = aux->next;
			}
		}
		stack = stack->next;
	}
}

void	ft_cmp_mv(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	while (aux)
	{
		while (aux->s_mv.ra && aux->s_mv.rb)
		{
			aux->s_mv.ra--;
			aux->s_mv.rb--;
			aux->s_mv.rr++;
		}
		while (aux->s_mv.rra && aux->s_mv.rrb)
		{
			aux->s_mv.rra--;
			aux->s_mv.rrb--;
			aux->s_mv.rrr++;
		}
		aux = aux->next;
	}
}
