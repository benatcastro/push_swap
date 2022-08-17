/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defined_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:44:43 by becastro          #+#    #+#             */
/*   Updated: 2022/08/17 04:25:37 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Shorts a list of 3 nodes, each of one containing 1 integer in no more than 2
 * steps
 * @param t_stack the stack to be sorted
 */
void	ft_sort_3(t_stack **stack)
{
	if (ft_check_short(stack))
		return ;
	if ((*stack)->n == 2 && (*stack)->next->n == 1)
		ft_sa(stack, true);

}
