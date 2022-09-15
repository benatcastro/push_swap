/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncs_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:34:01 by becastro          #+#    #+#             */
/*   Updated: 2022/09/14 18:52:52 by becastro         ###   ########.fr       */
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
void	ft_rra(t_data *data, bool print)
{
	t_stack	**stack;
	t_stack	*aux;

	stack = &data->stack_a;
	aux = *stack;
	while (aux->next->next != NULL)
		aux = aux->next;
	aux->next->next = *stack;
	*stack = aux->next;
	aux->next = NULL;
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
void	ft_rrb(t_data *data, bool print)
{
	t_stack	**stack;
	t_stack	*aux;

	stack = &data->stack_b;
	aux = *stack;
	while (aux->next->next != NULL)
		aux = aux->next;
	aux->next->next = *stack;
	*stack = aux->next;
	aux->next = NULL;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

/**
 * @brief
 * Reverse Rotate A and B at the same time
 * @param head_a head of stack A
 * @param head_b head of stack B
 */
void	ft_rrr(t_data *data)
{
	ft_rra(data, false);
	ft_rrb(data, false);
	ft_putstr_fd("rrr\n", 1);
}
