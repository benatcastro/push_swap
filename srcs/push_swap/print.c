/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 05:29:55 by becastro          #+#    #+#             */
/*   Updated: 2022/09/13 15:09:04 by becastro         ###   ########.fr       */
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

void	print_tab(int *tab, int sz)
{
	int	i;

	i = -1;
	printf("=======\nsize: (%d)\ntab: [", sz);
	while (++i < sz)
		printf("%d ", tab[i]);
	printf("]\n");
}
