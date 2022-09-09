/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defined_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:44:43 by becastro          #+#    #+#             */
/*   Updated: 2022/09/09 04:01:08 by becastro         ###   ########.fr       */
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
	if (ft_check_short(&data->stack_a))
		return ;
	ft_moveto_head(&data->stack_a, NULL, ft_find_min_nbr(&data->stack_a));
	ft_pb(data);
	ft_moveto_head(&data->stack_a, NULL, ft_find_min_nbr(&data->stack_a));
	ft_pb(data);
	ft_sort_3_logic(&data->stack_a);
	ft_pa(data);
	ft_pa(data);
}
