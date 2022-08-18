/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defined_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:44:43 by becastro          #+#    #+#             */
/*   Updated: 2022/08/18 19:12:57 by becastro         ###   ########.fr       */
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

void	ft_sort_5_logic(t_data *data)
{
	int	*min_values;

	min_values = find_min_n(&data->stack_a);
	printf("starting list\n");
	ft_show_list(&data->stack_a);
	ft_moveto_head(&data->stack_a, NULL, min_values[0]);
	ft_pb(&data->stack_a, &data->stack_b);
	ft_moveto_head(&data->stack_a, NULL, min_values[1]);
	ft_pb(&data->stack_a, &data->stack_b);
	ft_show_list(&data->stack_a);
	printf("==========\n");
	ft_show_list(&data->stack_b);
}
