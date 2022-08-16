/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncs_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:45:30 by becastro          #+#    #+#             */
/*   Updated: 2022/08/17 00:52:28 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **head_a, bool print)
{
	t_stack	*aux;
	t_stack	*tail;
	t_stack	*t_prev;

	tail = ft_lastnode(head_a);
	t_prev = tail;
	aux = (*head_a)->next;
	tail->next = (*head_a);
	(*head_a)->prev = t_prev;
	(*head_a)->next = NULL;
	(*head_a) = aux;
	ft_arrange_links(head_a, NULL);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **head_b, bool print)
{
	t_stack	*aux;
	t_stack	*tail;
	t_stack	*t_prev;

	tail = ft_lastnode(head_b);
	t_prev = tail;
	aux = (*head_b)->next;
	tail->next = (*head_b);
	(*head_b)->prev = t_prev;
	(*head_b)->next = NULL;
	(*head_b) = aux;
	ft_arrange_links(NULL, head_b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **head_a, t_stack **head_b)
{
	ft_ra(head_a, false);
	ft_rb(head_b, false);
	ft_putstr_fd("rr\n", 1);
}
