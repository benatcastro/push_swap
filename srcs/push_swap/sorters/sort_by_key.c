/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 05:19:32 by becastro          #+#    #+#             */
/*   Updated: 2022/09/19 18:37:55 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_short(int *tab, size_t sz)
{
	int32_t	tmp;
	size_t	step;
	size_t	i;

	step = 0;
	while (step < sz - 1)
	{
		i = 0;
		while (i < sz - step - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		step++;
	}
}


static void	ft_set_keys(int *tab, t_data *data)
{
	int	key;
	int	i;

	key = 1;
	i = -1;
	while (++i < (int)data->sz_a)
	{
		ft_find_nbr_node(&data->stack_a, tab[i])->key = key;
		key++;
	}
}

void	ft_short_keys(t_data *data)
{
	t_stack	*aux;
	int		i;
	int		*tab;

	tab = ft_calloc(data->sz_a, sizeof(int));
	aux = data->stack_a;
	i = 0;
	while (aux)
	{
		tab[i] = aux->n;
		i++;
		aux = aux->next;
	}
	bubble_short(tab, data->sz_a);
	ft_set_keys(tab, data);
	free(tab);
}
