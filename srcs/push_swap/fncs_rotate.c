/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncs_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:45:30 by becastro          #+#    #+#             */
/*   Updated: 2022/09/05 19:13:59 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * shift up all elements of stack a by 1. The first
 * element becomes the last one.
 * @param head_a The stack in which the fnc will be applied
 * @param print bool - print or not the fnc name
 */
void	ft_ra(t_stack **head_a, bool print)
{
	t_stack	*aux;
	t_stack	*tail;
	t_stack	*t_prev;

	tail = ft_lastnode(head_a);
	if (ft_lst_size(head_a) <= 2)
	{
		ft_sa(head_a, false);
		return ;
	}
	t_prev = tail;
	aux = (*head_a)->next;
	tail->next = (*head_a);
	(*head_a)->prev = t_prev;
	(*head_a)->next = NULL;
	(*head_a) = aux;
	//ft_arrange_links(head_a, NULL);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

/**
 * @brief
 *shift up all elements of stack b by 1. The first element becomes
the last one.
 * @param head_b The stack in which the fnc will be applied
 * @param print bool - print or not the fnc name
 */
void	ft_rb(t_stack **head_b, bool print)
{
	t_stack	*aux;
	t_stack	*tail;
	t_stack	*t_prev;

	if (ft_lst_size(head_b) <= 2)
	{
		ft_sb(head_b, false);
		return ;
	}
	tail = ft_lastnode(head_b);
	t_prev = tail;
	aux = (*head_b)->next;
	tail->next = (*head_b);
	(*head_b)->prev = t_prev;
	(*head_b)->next = NULL;
	(*head_b) = aux;
	//ft_arrange_links(NULL, head_b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

/**
 * @brief
 * Rotate A and Rotate B at the same time
 *
 * @param head_a Stack A head
 * @param head_b Stack B head
 */
void	ft_rr(t_stack **head_a, t_stack **head_b)
{
	ft_ra(head_a, false);
	ft_rb(head_b, false);
	ft_putstr_fd("rr\n", 1);
}
