/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/08/07 20:38:08ecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_node(t_stack **head, t_stack *ref_node)
{
	t_stack	*aux;

	if (ref_node == (*head))
		(*head)->next = ref_node->next;
	else
	{
		aux = (*head);
		while (aux)
			aux = aux->next;
		aux->next = ref_node->next;
	}
	free (ref_node);
}

void	ft_create_node(t_stack **head, int n)
{
	static int	key;
	t_stack		*node;

	node = ft_calloc(1, sizeof(t_stack));
	node->key = key;
	key++;
	node->n = n;
	node->next = NULL;
	//printf("creating node n -> (%d)\n", n);
	ft_addnode(head, node);
}

void	ft_addnode(t_stack **head, t_stack *node)
{
	t_stack		*aux;

	//printf("adding node n -> (%d)\n", node->n);
	if (!(*head))
		(*head) = node;
	else
	{
		aux = (*head);
		while (aux->next)
		{
			printf("aux key (%d) || (%d)\n", aux->key, node->key);
			aux = aux->next;
		}
		aux->next = node;
		printf("==========\n");
		aux = (*head);
		while (aux->next != node)
			aux = aux->next;
		aux->prev = aux;
	}
}
