/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:48:38 by becastro          #+#    #+#             */
/*   Updated: 2022/08/17 03:27:47 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorter_manager(t_data *data)
{
	if (data->stack_size == 3)
		data->sorter = SORT_3;
	else if (data->stack_size == 5)
		data->sorter = SORT_5;
	else
		data->sorter = QUICK_SHORT;

}
