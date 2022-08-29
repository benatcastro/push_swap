/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:52:23 by becastro          #+#    #+#             */
/*   Updated: 2022/08/29 20:15:46 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param head of the list where to find the node
 * @param ref of the node to find
 * @return the node, if the key is not present returns last node
 */
t_stack	*ft_find_node(t_stack **head, int ref)
{
	t_stack	*aux;

	aux = (*head);
	while (aux->next)
	{
		if (aux->key == ref)
			break ;
		aux = aux->next;
	}
	return (aux);
}

/**
 * @brief
 * iterates the list till the next node is matches the ref and key.
 * @param head head of the stack
 * @param ref
 * @return the previous node of @ref param
 */
t_stack	*ft_find_prev(t_stack **head, int ref)
{
	t_stack	*aux;

	aux = (*head);
	while (aux->next && aux->next->key != ref)
		aux = aux->next;
	return (aux);
}

/**
 * @brief
 * Return the nbr of a node given a ref key
 * @param stack -> stack to be searched
 * @param ref -> ref key of the node
 * @return int nbr of the node with the ref param
 * if no ref is find return the key of the last node
 */
int	ft_find_n_node(t_stack **stack, int ref)
{
	t_stack	*aux;

	aux = (*stack);
	while (aux)
	{
		if (aux->key == ref)
			return (aux->n);
	}
	return (aux->key);
}
