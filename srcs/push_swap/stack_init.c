/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/31 16:57:18 by bena             ###   ########.fr       */
=======
/*   Updated: 2022/07/31 16:40:22 by bena             ###   ########.fr       */
>>>>>>> e977679 (tests with before node statment)
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_addstack(t_stack **head, t_stack *node)
{
	t_stack		*aux;

	if (!(*head))
	{
		printf("test\n");
		(*head) = node;
	}
	else
	{
		aux = (*head);
		while (aux->next)
			aux = aux->next;
		printf("aux: (%p) node: (%p)\n", aux, node);
		aux = node;
	}
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


