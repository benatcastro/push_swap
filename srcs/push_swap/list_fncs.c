/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 05:17:21 by becastro          #+#    #+#             */
/*   Updated: 2022/09/15 15:28:17 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Iterates trough the stack freeing every node.
 * @param head_a
 * @param head_b
 */
void	ft_free_stacks(t_stack *head_a, t_stack *head_b)
{
	t_stack	*tmp;

	if (head_a)
	{
		while (head_a)
		{
			tmp = head_a;
			head_a = head_a->next;
			free(tmp);
		}
	}
	if (head_b)
	{
		while (head_b)
		{
			tmp = head_b;
			head_b = head_b->next;
			free(tmp);
		}
	}
}

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
	}
}
