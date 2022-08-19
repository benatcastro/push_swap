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

	while (tab[++i] && i < sz && i + 1 < sz)
		if (tab[i] > tab[i + 1])
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
	while (tab[++i] && i < sz)
	{
		if (tab[i] > tab[i + 1] && i + 1 < sz)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
		}
	}
	if (!is_sorted(tab, sz))
		sort_tab(tab, sz);
}

int	ft_get_median(t_stack **stack)
{
	t_stack	*aux;
	int		i;
	int		*tab;
	int		median;

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
	sort_tab(tab, ft_lst_size(stack));
	median = tab[i % 2];
	free(tab);
	return (median);
}
