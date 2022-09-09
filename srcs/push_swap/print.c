/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 05:29:55 by becastro          #+#    #+#             */
/*   Updated: 2022/09/09 05:29:58 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_data(t_data *data)
{
	printf("=====DATA STRUCT========\n");
	printf("%d ra,	%d rb,	%d rr	", data->mv.ra,
		data->mv.rb, data->mv.rr);
	printf("%d rra,	%d rrb,	%d rrr ", data->mv.rra,
		data->mv.rrb, data->mv.rrr);
	printf("Total moves -> %d\n", data->mv.moves);
}

static void	print_lst(t_stack *stack)
{
	while (stack)
	{
		printf("%d	->	%d,	", stack->key, stack->n);
		printf("%d ra,	%d rb,	%d rr	", stack->s_mv.ra,
			stack->s_mv.rb, stack->s_mv.rr);
		printf("%d rra,	%d rrb,	%d rrr ", stack->s_mv.rra,
			stack->s_mv.rrb, stack->s_mv.rrr);
		printf("Total moves -> %d\n", stack->s_mv.moves);
		stack = stack->next;
	}
}

void	print_struct(t_data *data)
{
	write(1, "\n--- Stack a ---\n", 18);
	printf("Size (%d)\n", data->sz_a);
	print_lst(data->stack_a);
	write(1, "\n--- Stack b ---\n", 18);
	printf("Size (%d)\n", data->sz_b);
	print_lst(data->stack_b);
}
