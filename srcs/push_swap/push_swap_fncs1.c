/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fncs1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/07/31 17:55:12 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **head_a)
{
	int		aux;

	aux = (*head_a)->n;
	(*head_a)->n = (*head_a)->next->n;
	(*head_a)->next->n = aux;
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_stack **head_b)
{
	int		aux;

	aux = (*head_b)->n;
	(*head_b)->n = (*head_b)->next->n;
	(*head_b)->next->n = aux;
	ft_putstr_fd("sa\n", 1);
}

void	ft_ss(t_stack **head_a, t_stack **head_b)
{
	ft_sa(head_a);
	ft_sb(head_b);
}
