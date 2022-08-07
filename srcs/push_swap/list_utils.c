/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 00:59:09 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_show_list(t_stack **head)
{
	t_stack	*aux;

	if (!(*head))
		return ;
	aux = (*head);
	while (aux->next)
	{
		printf("n:(%d) ", aux->n);
		printf("next:(%d) ", aux->next->n);
		printf("before:(%d)  ", aux->before->n);
		printf("\n");
		aux = aux->next;
		if (aux == (*head))
			break ;
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
		printf("LIST:(%d)\n", tmp->n);
		tmp = tmp->next;
		if (tmp == (*head))
			break ;
	}
	while (aux->next)
	{
		printf("Node: (%d)\n", aux->n);
		aux = aux->next;
		if (aux == (*head))
			break ;
	}
	printf("Last Return (%d)\n", aux->n);
	return (aux);
}
