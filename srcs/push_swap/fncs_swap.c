/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncs_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/09/20 20:32:50 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief
 *- swap the first 2 elements at the top of stack A. Do nothing if there
is only one or no elements).
 * @param head_a head of Stack A
 * @param print bool - print or not fnc name
 */
void	ft_sa(t_stack **head_a, bool print)
{
	t_stack	*tmp;

	if (!(*head_a) || ft_lst_size(head_a) < 2)
		return ;
	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	tmp->next = (*head_a)->next;
	(*head_a)->next = tmp;
	if (print)
		ft_putstr_fd("sa\n", 1);
}

/**
 * @brief
 *- swap the first 2 elements at the top of stack B. Do nothing if there
is only one or no elements).
 * @param head_b head of Stack B
 * @param print bool - print or not fnc name
 */
void	ft_sb(t_stack **head_b, bool print)
{
	t_stack	*tmp;

	if (!(*head_b) || ft_lst_size(head_b) < 2)
		return ;
	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp->next = (*head_b)->next;
	(*head_b)->next = tmp;
	if (print)
		ft_putstr_fd("sb\n", 1);
}

/**
 * @brief
 * Swap A and Swap B at the same time
 * @param head_a
 * @param head_b
 */
void	ft_ss(t_stack **head_a, t_stack **head_b, bool print)
{
	ft_sa(head_a, false);
	ft_sb(head_b, false);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
