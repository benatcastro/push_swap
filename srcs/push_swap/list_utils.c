/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/08/11 18:40:19 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_show_list(t_stack **head)
{
	t_stack	*aux;

	if (!(*head))
		return ;
	aux = (*head);
	while (aux)
	{
		printf("Key (%d) ", aux->key);
		printf("n (%d) ", aux->n);
		printf("\n");
		usleep(50000);
		aux = aux->next;
	}
}

int	ft_lst_size(t_stack **head)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = (*head);
	while (aux->next || aux == (*head))
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

t_stack	*ft_lastnode(t_stack **head)
{
	t_stack	*aux;
	t_stack	*tmp;

	aux = (*head);
	tmp = (*head);
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp == (*head))
			break ;
	}
	while (aux->next)
	{
		aux = aux->next;
		if (aux == (*head))
			break ;
	}
	return (aux);
}
