/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncs_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/08/17 00:12:09 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief shorts the pointers of next and prev after pushing a node.
 *
 * @param head_a head of the stack A
 * @param head_b head of the stack B
 */
void	ft_arrange_links(t_stack **head_a, t_stack **head_b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;

	aux_a = (*head_a);
	aux_b = (*head_b);

	aux_a->prev = NULL;
	aux_b->prev = NULL;
	while (aux_a->next)
	{
		aux_a = aux_a->next;
		aux_a->prev = ft_find_node(head_a, aux_a->key - 1);
	}
	while (aux_b->next)
	{
		aux_b = aux_b->next;
		aux_b->prev = ft_find_node(head_b, aux_a->key - 1);
	}
}

/*Takes the first element of the stack B and pushes it to the top of the stack A
If the stack B is empty it does nothing*/
void	ft_pa(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	ft_putstr_fd("pa\n", 1);
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
	ft_arrange_links(head_a, head_b);
}

void	ft_pb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	ft_putstr_fd("pb\n", 1);
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
	ft_arrange_links(head_a, head_b);
}
