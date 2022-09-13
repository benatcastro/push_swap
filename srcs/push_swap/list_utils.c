/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/09/13 16:37:38 by becastro         ###   ########.fr       */
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

/**
 * @brief
 * Return the len of the @param head list
 * @param head list head
 * @return size_t len of the list
 */
size_t	ft_lst_size(t_stack **head)
{
	t_stack	*aux;
	int		i;

	if (!head)
		return (0);
	i = 0;
	aux = (*head);
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

/**
 * @brief
 * Iterates through the list and the returns the last node of it
 * @param head -> head of the list to be iterated
 * @return t_stack* last node of the head list
 */
t_stack	*ft_lastnode(t_stack **head)
{
	t_stack	*aux;

	aux = (*head);
	while (aux->next)
		aux = aux->next;
	return (aux);
}
