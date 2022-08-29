/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:48:38 by becastro          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/29 14:13:51 by becastro         ###   ########.fr       */
=======
/*   Updated: 2022/08/19 06:43:37 by bena             ###   ########.fr       */
>>>>>>> 11123d44b6fe86645dfa5d5b4f49a2be579562b2
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
	// printf("stack size: (%zu)\n", data->stack_size);
	if (data->stack_size == 3)
	{
		data->sorter = SORT_3;
		ft_sort_3_logic(&data->stack_a);
	}
	else if (data->stack_size == 5)
	{
		data->sorter = SORT_5;
		ft_sort_5_logic(data);
	}
	else
		data->sorter = QUICK_SHORT;
}
