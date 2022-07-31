/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/07/31 18:25:53 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_node(t_stack **head, t_stack *ref_node)
{
	t_stack	*aux;

	if (ref_node == (*head))
		(*head) = (*head)->next;
	else
	{
		aux = (*head);
		while (aux->next != ref_node)
				aux = aux->next;
		aux->next = ref_node->next;
	}
	free (ref_node);
}

void	ft_create_node(t_stack **head, int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->n = n;
	node->next = NULL;
	node->before = NULL;
	ft_addstack(head, node);
}

void	ft_addstack(t_stack **head, t_stack *node)
{
	t_stack		*aux;
	static int	i;

	if (i == 0)
	{
		(*head) = node;
		i++;
		return ;
	}
	aux = (*head);
	while (aux->next)
		aux = aux->next;
	aux->next = node;
	node->before = aux;
	node->before->n = aux->n;
}
