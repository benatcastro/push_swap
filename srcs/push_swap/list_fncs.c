/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/07/31 20:36:53 by bena             ###   ########.fr       */
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

	node = ft_calloc(1, sizeof(t_stack));
	node->n = n;
	node->next = NULL;
	node->before = NULL;
	ft_addnode(head, node);
}

void	ft_addnode(t_stack **head, t_stack *node)
{
	t_stack		*aux;


	if (!(*head))
	{
		(*head) = node;
		(*head)->next = (*head);
	}
	else
	{
		aux = (*head);
		while (aux->next != (*head))
		{
			printf("test (%d)\n", aux->n);
			aux = aux->next;
		}
		node->next = (*head);
		aux->next = node;
		//last->next = (*head);
	}
}

