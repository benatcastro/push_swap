/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defined_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:44:43 by becastro          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/29 14:59:05 by becastro         ###   ########.fr       */
=======
/*   Updated: 2022/08/19 08:12:04 by bena             ###   ########.fr       */
>>>>>>> 11123d44b6fe86645dfa5d5b4f49a2be579562b2
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * Declares the variable needed for the possible cases conditions when sorting
 * 3 nbrs
 * @param t_stack the stack to be sorted
 */
void	ft_sort_3_logic(t_stack **stack)
{
	int	top;
	int	mid;
	int	bot;

	if (ft_check_short(stack))
		return ;
	top = (*stack)->n;
	mid = (*stack)->next->n;
	bot = (*stack)->next->next->n;
	ft_sort_3_cases(top, mid, bot, stack);
}

/**
 * @brief
 * Checks for the 5 possible combinations and sorts the stack
 * @param top --> top nbr at the stack
 * @param mid --> middle nbr at the stack
 * @param bot --> botton nbr at the stack
 * @param stack stack to be sorted
 */
void	ft_sort_3_cases(int top, int mid, int bot, t_stack **stack)
{
	if (top > mid && mid < bot && bot > top)
		ft_sa(stack, true);
	else if (top > mid && mid > bot && top > bot)
	{
		ft_sa(stack, true);
		ft_rra(stack, true);
	}
	else if (top > mid && mid < bot && top > bot)
		ft_ra(stack, true);
	else if ((top < mid) && (mid > bot) && (bot > top))
	{
		ft_sa(stack, true);
		ft_ra(stack, true);
	}
	else if (top < mid && mid > bot && bot < top)
		ft_rra(stack, true);
}

/**
 * @brief
 * Pushes the 2 lowest nbrs of the stacks,
 * after sorts the lasting 3 nbrs
 * with sort_3 algorithm,
 * then the 2 lasting nbrs are pushed in the correct position
 * @param data -> general struct
 */
void	ft_sort_5_logic(t_data *data)
{
	int	*min_values;

	if (ft_check_short(&data->stack_a))
		return ;
	min_values = find_min_n(&data->stack_a);
	ft_moveto_head(&data->stack_a, NULL, min_values[0]);
	ft_pb(&data->stack_a, &data->stack_b);
	ft_moveto_head(&data->stack_a, NULL, ft_find_min_n(&data->stack_a));
	ft_pb(&data->stack_a, &data->stack_b);
	ft_sort_3_logic(&data->stack_a);
	ft_pa(&data->stack_a, &data->stack_b);
	ft_pa(&data->stack_a, &data->stack_b);
	free(min_values);
}
