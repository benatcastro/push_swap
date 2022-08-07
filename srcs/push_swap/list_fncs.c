/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 01:00:25 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_node(t_stack **head, t_stack *ref_node)
{
	t_stack	*aux;

	if (ref_node == (*head))
	{
		printf("free first node\n");
		(*head) = (*head)->next;
	}
	else
	{
		printf("free other node\n");
		aux = (*head);
		while (aux->next != ref_node)
		{
			aux = aux->next;
			if (aux == (*head))
				break ;
		}
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
		(*head)->before = node;
	}
	else
	{
		aux = (*head);
		while (aux->next != (*head))
		{
			aux = aux->next;
			if (aux == (*head))
				break ;
		}
		node->next = (*head);
		node->before = aux;
		(*head)->before = node;
		aux->next = node;
	}
}
