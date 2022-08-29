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
	ft_addnode(head, node);
}

/**
 * @brief
 *
 * @param head
 * @param node
 */
void	ft_addnode(t_stack **head, t_stack *node)
{
	t_stack	*aux;

	if (!(*head))
		(*head) = node;
	else
	{
		aux = (*head);
		while (aux->next)
			aux = aux->next;
		aux->next = node;
		node->prev = aux;
	}
}

/**
 * @brief shorts the pointers of next and prev on a stack.
 *
 * @param head_a head of the stack A or NULL
 * @param head_b head of the stack B or NULL
 */
void	ft_arrange_links(t_stack **head_a, t_stack **head_b)
{
	t_stack	*aux_a;
	t_stack	*aux_b;

	if (head_a)
	{
		aux_a = (*head_a);
		while (aux_a->next)
		{
			aux_a->prev = ft_find_prev(head_a, aux_a->key - 1);
			aux_a = aux_a->next;
		}
		(*head_a)->prev = NULL;
	}
	if (head_b)
	{
		aux_b = (*head_b);
		while (aux_b->next)
		{
			aux_b->prev = ft_find_prev(head_b, aux_b->key - 1);
			aux_b = aux_b->next;
		}
		(*head_b)->prev = NULL;
	}
}


