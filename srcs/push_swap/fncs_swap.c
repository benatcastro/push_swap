/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncs_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/08/12 20:01:21 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_node(t_stack *node1, t_stack *node2)
{


	printf("Key 1 (%d) Key 2 (%d)\n", node1->key, node2->key);

	t_stack	*tmp;

	tmp = node1->prev;
	tmp->next = node2;
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
