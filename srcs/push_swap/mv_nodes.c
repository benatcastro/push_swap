/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:01:14 by becastro          #+#    #+#             */
/*   Updated: 2022/09/09 06:55:38 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_moveto_head(t_stack **stack_a, t_stack **stack_b, t_data *data, int ref)
{
	int	max_ref;

	if (stack_a)
	{
		max_ref = ft_lastnode(stack_a)->key;
		if ((max_ref - ref) >= ref)
			while ((*stack_a)->key != ref)
				ft_ra(stack_a, true);
		else
			while ((*stack_a)->key != ref)
				ft_rra(data, true);
	}
	if (stack_b)
	{
		if ((max_ref - ref) >= ref)
			while ((*stack_b)->key != ref)
				ft_rb(stack_b, true);
		else
			while ((*stack_b)->key != ref)
				ft_rrb(data, true);
	}
}
