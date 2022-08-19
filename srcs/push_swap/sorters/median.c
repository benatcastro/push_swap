/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:27:46 by becastro          #+#    #+#             */
/*                                                                            */

#include "push_swap.h"

static

int	ft_get_median(t_stack **stack)
{
	t_stack	*aux;
	int		i;
	int		*tab;

	tab = ft_calloc(ft_lst_size(stack), sizeof(int));
	aux = (*stack);
	i = 0;
	ft_show_list(stack);
	while (aux)
	{
		tab[i] = aux->n;
		i++;
		aux = aux->next;
	}

	return (0);
}
