/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:48:38 by becastro          #+#    #+#             */
/*   Updated: 2022/09/15 15:51:57 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Checks if the stack is sorted
 * @param stack the head of the list to be checked
 * @return true -> is sorted
 * @return false -> not sorted
 */
bool	ft_check_short(t_stack	**stack)
{
	t_stack	*aux;

	aux = (*stack);
	while (aux->next)
	{
		if (aux->next->n < aux->n)
			return (false);
		aux = aux->next;
	}
	return (true);
}

/**
 * @brief
 * checks for specific cases and calls chooses the shorting algorithtm
 * @param data data structure
 */
void	ft_sorter_manager(t_data *data)
{

	if (data->sz_a == 1)
		return ;
	else if (data->sz_a == 3)
	{
		data->sorter = SORT_3;
		ft_sort_3_logic(data);
	}
	else if (data->sz_a == 5)
	{
		data->sorter = SORT_5;
		ft_sort_5_logic(data);
	}
	else
		ft_general_short(data);
}
