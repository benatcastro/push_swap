/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncs_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/09/05 19:04:27 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Takes the first element of the stack B and pushes it to the top of the stack A
If the stack B is empty it does nothing
 * @param head_a -> head of stack A
 * @param head_b -> head of stack B
 */
void	ft_pa(t_stack **head_a, t_stack **head_b, t_data *data)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (!(*head_b))
		return ;
	tmp_a = (*head_a);
	tmp_b = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp_b->next = NULL;
	if (!head_a)
		(*head_a) = tmp_a;
	else
	{
		tmp_b->next = tmp_a;
		(*head_a) = tmp_b;
	}
	data->sz_a++;
	data->sz_b--;
	//ft_arrange_links(head_a, head_b);
	ft_putstr_fd("pa\n", 1);
}

/**
 * @brief
 * Takes the first element of the stack A and pushes it to the top of the stack b
If the stack a is empty it does nothing
 * @param head_a -> head of stack A
 * @param head_b -> head of stack B
 */
void	ft_pb(t_stack **head_a, t_stack **head_b, t_data *data)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (!(*head_a))
		return ;
	tmp_a = (*head_a);
	tmp_b = (*head_b);
	(*head_a) = (*head_a)->next;
	tmp_a->next = NULL;
	if (!head_b)
		(*head_b) = tmp_a;
	else
	{
		tmp_a->next = tmp_b;
		(*head_b) = tmp_a;
	}
	data->sz_a--;
	data->sz_b++;
	//ft_arrange_links(head_a, head_b);
	ft_putstr_fd("pb\n", 1);
}
