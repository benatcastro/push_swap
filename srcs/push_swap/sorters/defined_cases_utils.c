/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defined_cases_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:04:49 by becastro          #+#    #+#             */
/*   Updated: 2022/08/29 20:28:39 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
/**
 * @brief
 * Finds mins values in a stack
 * @param stack
 * @return ref to the node with minimun n value
 * minimimun values of stack
 */
int	ft_find_min_nbr(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*result;
	int		min;

	aux = (*stack);
	min = INT16_MAX;
	while (aux)
	{
		if (aux->n < min)
		{
			min = aux->n;
			result = aux;
		}
		aux = aux->next;
	}
	return (result->key);
}
