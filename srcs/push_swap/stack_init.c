/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*   Updated: 2022/07/19 02:00:48 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_addstack(t_stack **head, t_stack *node)
{
	t_stack		*aux;
	static int	i;

	if (i == 0)
	{
		(*head) = node;
		i++;
		return ;
	}
	aux = (*head);
	while (aux->next)
		aux = aux->next;
	aux->next = node;
	node->before = aux;
}

static void	ft_create_node(t_stack **head, int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->n = n;
	node->next = NULL;
	node->before = NULL;
	ft_addstack(head, node);
}

void	ft_stack_init(t_stack **head, char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		ft_create_node(head, ft_atoi(args[i]));
}


