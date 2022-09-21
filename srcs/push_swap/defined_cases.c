/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defined_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:44:43 by becastro          #+#    #+#             */
/*   Updated: 2022/09/17 19:29:24 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "movements.h"
/**
 * @brief
 * Declares the variable needed for the possible cases conditions when sorting
 * 3 nbrs
 * @param t_stack the stack to be sorted
 */
void	ft_sort_3_logic(t_data *data)
{
	int		top;
	int		mid;
	int		bot;
	t_stack	**stack;

	stack = &data->stack_a;
	if (ft_check_short(stack))
		return ;
	top = (*stack)->n;
	mid = (*stack)->next->n;
	bot = (*stack)->next->next->n;
	ft_sort_3_cases(top, mid, bot, data);
}

/**
 * @brief
 * Checks for the 5 possible combinations and sorts the stack
 * @param top --> top nbr at the stack
 * @param mid --> middle nbr at the stack
 * @param bot --> botton nbr at the stack
 * @param stack stack to be sorted
 */
void	ft_sort_3_cases(int top, int mid, int bot, t_data *data)
{
	if (top > mid && mid < bot && bot > top)
		ft_sa(&data->stack_a, true);
	else if (top > mid && mid > bot && top > bot)
	{
		ft_sa(&data->stack_a, true);
		ft_rra(data, true);
	}
	else if (top > mid && mid < bot && top > bot)
		ft_ra(&data->stack_a, true);
	else if ((top < mid) && (mid > bot) && (bot > top))
	{
		ft_sa(&data->stack_a, true);
		ft_ra(&data->stack_a, true);
	}
	else if (top < mid && mid > bot && bot < top)
		ft_rra(data, true);
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
	if (ft_check_short(&data->stack_a))
		return ;
	ft_moveto_head(&data->stack_a, NULL, data, ft_find_min_nbr(&data->stack_a));
	ft_pb(data, true);
	ft_moveto_head(&data->stack_a, NULL, data, ft_find_min_nbr(&data->stack_a));
	ft_pb(data, true);
	ft_sort_3_logic(data);
	ft_pa(data, true);
	ft_pa(data, true);
}
