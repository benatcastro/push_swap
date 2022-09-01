/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_counts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:46:26 by becastro          #+#    #+#             */
/*   Updated: 2022/09/01 13:47:56 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_key_finder(t_stack **stack, int key)
{
	t_stack	*aux;
	int		i;
	int		max;

	i = 0;
	max = 0;
	aux = (*stack);
	while (aux)
	{
		if (aux->key > i && aux->key < key)
			i = aux->key;
		if (aux->key > max)
			max = aux->key;
		aux = aux->next;
	}
	if (!i)
		return (max);
	return (i);
}

void	moves_a(t_data *data, t_moves *moves, size_t sz)
{
	t_stack	*aux;
	t_stack	*stack;

	stack = data->stack_a;
	while (stack)
	{
		// ft_show_double_list(&data->stack_a, &data->stack_b);
		// sleep(1);
		aux = data->stack_a;
		while (stack->key != aux->key)
		{
			moves->ra++;
			aux = aux->next;
		}
		if (moves->ra > (sz / 2))
		{
			moves->ra = 0;
			while (aux)
			{
				moves->rra++;
				aux = aux->next;
			}
		}
		stack = stack->next;
	}
}

void	moves_b(t_data *data, t_moves *moves, size_t sz)
{
	t_stack	*aux;
	t_stack	*stack;
	int		ref_key;

	stack = data->stack_a;
	while (stack)
	{
		aux = data->stack_b;
		ref_key = ft_key_finder(&data->stack_b, stack->key);
		while (ref_key != aux->key)
		{
			moves->rb++;
			aux = aux->next;
		}
		if (moves->rb > (sz / 2))
		{
			moves->rb = 0;
			while (aux)
			{
				moves->rrb++;
				aux = aux->next;
			}
		}
		stack = stack->next;
	}
}

// void	optimize_moves(t_moves *moves)
// {
// 	t_moves	*aux;

// 	aux = moves;
// 	while (aux)
// 	{
// 		while (aux->ra && aux->rb)
// 		{
// 			aux->ra--;
// 			aux->rb--;
// 			aux->rr++;
// 		}
// 		while (aux->rra && aux->rrb)
// 		{
// 			aux->rra--;
// 			aux->rrb--;
// 			aux->rrr++;
// 		}
// 		aux = aux->next;
// 	}
