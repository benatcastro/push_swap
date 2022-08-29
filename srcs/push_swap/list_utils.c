/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/29 14:52:15 by becastro         ###   ########.fr       */
=======
/*   Updated: 2022/08/19 07:21:37 by bena             ###   ########.fr       */
>>>>>>> 11123d44b6fe86645dfa5d5b4f49a2be579562b2
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_show_double_list(t_stack **stack_a, t_stack **stack_b)
{
<<<<<<< HEAD
	if (stack_a)
	{
		printf("====LIST A====\n");
		ft_show_list(stack_a);
	}
	if (stack_b)
	{
		printf("====LIST B====\n");
		ft_show_list(stack_b);
	}
}

=======
	printf("===STACK A===\n");
	ft_show_list(stack_a);
	printf("===STACK B===\n");
	ft_show_list(stack_b);
}
>>>>>>> 11123d44b6fe86645dfa5d5b4f49a2be579562b2
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
			if (aux->prev)
				printf("prev (%d) ", aux->prev->key);
			else
				printf ("prev (NULL) ");
			printf("\n");
			//usleep(50000);
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
<<<<<<< HEAD
=======

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
	while (aux)
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
 * @param head -> head of the stack.
 * @param ref -> ref value of the node to find the prev.
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
>>>>>>> 11123d44b6fe86645dfa5d5b4f49a2be579562b2
