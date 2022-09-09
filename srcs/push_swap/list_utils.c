/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/09/09 05:16:07 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_show_double_list(t_stack **stack_a, t_stack **stack_b)
{
	printf("===STACK A===\n");
	ft_show_list(stack_a);
	printf("===STACK B===\n");
	ft_show_list(stack_b);
}

void	ft_show_list(t_stack **head)
{
	t_stack	*aux;

	if (head)
	{
		if (!(*head))
			return ;
		aux = (*head);
		while (aux)
		{
			printf("Key (%d) ", aux->key);
			printf("n (%d) ", aux->n);
			if (aux->next)
				printf("next (%d) ", aux->next->key);
			else
				printf ("next (NULL) ");
			printf("\n");
			aux = aux->next;
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
