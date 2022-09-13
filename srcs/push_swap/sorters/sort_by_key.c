/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 05:19:32 by becastro          #+#    #+#             */
/*   Updated: 2022/09/13 15:23:33 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * checks if an array of integers is sorted
 * @param tab -> array to be checked
 * @param sz -> size of the array
 * @return true
 * @return false
 */
static bool	is_sorted(int *tab, int sz)
{
	int	i;

	i = -1;
	while (tab[++i] && (i + 1) < sz)
		if (tab[i] >= tab[i + 1])
			return (false);
	return (true);
}

/**
 * @brief
 * Binary sorting of tab
 * @param tab -> array of ints to be sorted
 */
static void	sort_tab(int *tab, int sz)
{
	int	i;
	int	tmp;

	i = -1;
	while (++i < sz - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
		}
	}
	if (!is_sorted(tab, sz))
		sort_tab(tab, sz);
}

static void	ft_set_keys(int *tab, t_data *data)
{
	int	key;
	int	i;

	key = 1;
	i = -1;
	while (++i < data->sz_a)
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
	sort_tab(tab, data->sz_a);
	ft_set_keys(tab, data);
}
