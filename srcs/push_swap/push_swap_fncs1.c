/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fncs1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/07/19 02:32:35 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **head_a)
{
	t_stack	*aux;

	ft_putstr_fd("sa\n", 1);
	if (ft_stack_size(head_a) <= 1)
		return ;
	aux = (*head_a);
	(*head_a) = (*head_a)->before;
	aux->before = aux->next;
}
