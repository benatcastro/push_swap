/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defined_cases_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:04:49 by becastro          #+#    #+#             */
/*   Updated: 2022/08/29 15:00:49 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Finds mins values in a stack
 * @param stack
 * @return array of 2 integers (refs) to the nodes with 2
 * minimimun values of stack
 */
int	ft_find_min_n(t_stack **stack)
{
	t_stack	*aux;
	int		min;

	aux = (*stack);
	min = (*stack)->n;
	while (aux)
	{
		if (aux->n < min)
			min = aux->n;
		aux = aux->next;
	}
	return (ft_find_node(stack, min)->n);
}
