/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/07/31 20:23:59 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_show_list(t_stack **head)
{
	t_stack	*aux;

	aux = (*head);
	while (aux->next != (*head))
	{
		printf("(%d)\n", aux->n);
		aux = aux->next;
		if (aux == (*head))
			break ;
	}
}

int	ft_stack_size(t_stack **head)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = (*head);
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

t_stack	*ft_lastnode(t_stack **head)
{
	t_stack	*aux;

	aux = (*head);
	while (aux->next)
		aux = aux->next;
	return (aux);
}
