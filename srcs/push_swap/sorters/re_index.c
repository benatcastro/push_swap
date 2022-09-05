/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:22:08 by becastro          #+#    #+#             */
/*   Updated: 2022/09/05 14:42:44 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_setkey_zero(t_data *data)
{
	t_stack	*aux;

	aux = data->stack_a;
	while (aux)
	{
		aux->key = 0;
		aux = aux->next;
	}
}

static void	ft_min_key(t_data *data)
{
	t_stack		*aux;
	t_stack		*tmp;
	bool		check;
	static int	key;

	ft_setkey_zero(data);
	tmp = data->stack_a;
	while (tmp)
	{
		check = false;
		aux = data->stack_a;
		while (aux)
		{
			if (tmp->n > aux->n && aux->key == 0)
				check = true;
			aux = aux->next;
		}
		if (check == false && tmp->key == 0)
		{
			tmp->key = key++;
			break ;
		}
		tmp = tmp->next;
	}
}

void	ft_reset_keys(t_data *data)
{
	int	i;

	i = data->sz_a;
	while (i--)
		ft_min_key(data);
}
