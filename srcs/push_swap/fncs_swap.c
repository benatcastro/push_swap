/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncs_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/08/14 19:46:59 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_node(t_stack *node1, t_stack *node2)
{
	t_stack	*tmp;
	t_stack	*aux;
	t_stack	*p_aux;

	p_aux = node2->prev;
	aux = node2->next;
	tmp = node1->prev;
	tmp->next = node2;
	node2->next = node1;
	node1->next = aux;
	node2->prev = node1->prev;
	node1->prev = p_aux;
}

void	ft_sa(t_stack **head_a)
{
	t_stack	*tmp;

	ft_putstr_fd("sa\n", 1);
	if (!(*head_a)->next)
		return ;
	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	tmp->next = (*head_a)->next;
	(*head_a)->next = tmp;
}

void	ft_sb(t_stack **head_b)
{
	t_stack	*tmp;

	ft_putstr_fd("sb\n", 1);
	if (!(*head_b)->next)
		return ;
	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp->next = (*head_b)->next;
	(*head_b)->next = tmp;
}

void	ft_ss(t_stack **head_a, t_stack **head_b)
{
	ft_sa(head_a);
	ft_sb(head_b);
	ft_putstr_fd("ss\n", 1);
}
