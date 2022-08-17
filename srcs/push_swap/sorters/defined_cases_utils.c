/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defined_cases_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:04:49 by becastro          #+#    #+#             */
/*   Updated: 2022/08/17 07:10:03 by becastro         ###   ########.fr       */
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
int	*find_min_n(t_stack **stack)
{
	t_stack	*aux;
	int		min_n[2];

	aux = (*stack);
	min_n[0] = aux->n;
	while (aux)
	{
		if (aux->n < min_n[0])
		{
			min_n[1] = min_n[0];
			min_n[0] = aux->key;
		}
		aux = aux->next;
	}
	return (min_n);
}
