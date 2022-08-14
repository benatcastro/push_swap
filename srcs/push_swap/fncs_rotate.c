/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncs_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:45:30 by becastro          #+#    #+#             */
/*   Updated: 2022/08/14 20:56:02 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **head_a)
{
	t_stack	*aux;

	aux = (*head_a);
	ft_swap_node(head_a, aux, aux->next);
	ft_swap_node(head_a, aux->next, aux->next->next);
	// while (aux->next)
	// {
	// 	ft_swap_node(head_a, aux, aux->next);
	// 	aux = aux->next;
	// }
	ft_putstr_fd("ra\n", 1);

}
