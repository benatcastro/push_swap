/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncs_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:34:01 by becastro          #+#    #+#             */
/*   Updated: 2022/08/18 18:52:53 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief
 *Reverse Rotate - shift down all elements of
 stack A by 1. The last element becomes the first one.
 * @param head_a head of Stack A
 * @param print bool - print or not the fnc name
 */
void	ft_rra(t_stack **head_a, bool print)
{
	t_stack	*tail;

	if (ft_lst_size(head_a) <= 2)
	{
		ft_sa(head_a, false);
		return ;
	}
	tail = ft_lastnode(head_a);
	tail->next = (*head_a);
	tail->prev->next = NULL;
	(*head_a)->prev = tail;
	(*head_a) = tail;
	ft_arrange_links(head_a, NULL);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

/**
 * @brief
 *Reverse Rotate - shift down all elements of
 stack B by 1. The last element becomes the first one.
 * @param head_a head of Stack B
 * @param print bool - print or not the fnc name
 */
void	ft_rrb(t_stack **head_b, bool print)
{
	t_stack	*tail;

	if (ft_lst_size(head_b) <= 2)
	{
		ft_sb(head_b, false);
		return ;
	}
	tail = ft_lastnode(head_b);
	tail->next = (*head_b);
	tail->prev->next = NULL;
	(*head_b) = tail;
	tail->prev = (*head_b);
	ft_arrange_links(NULL, head_b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

/**
 * @brief
 * Reverse Rotate A and B at the same time
 * @param head_a head of stack A
 * @param head_b head of stack B
 */
void	ft_rrr(t_stack **head_a, t_stack **head_b)
{
	ft_rra(head_a, false);
	ft_rrb(head_b, false);
	ft_putstr_fd("rra\n", 1);
}
